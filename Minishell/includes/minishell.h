/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:40:34 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 19:40:34 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <signal.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# include "signals.h"

// Define constants
# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SKIP 1
# define NOSKIP 0

# define BUFF_SIZE 4096
# define EXPANSION -36
# define ERROR 1
# define SUCCESS 0
# define IS_DIRECTORY 126
# define UNKNOWN_COMMAND 127

/////////////////////////// ENV STRUCTS /////////////////////////////

/**
 * @brief enum to define the type of token
 * @param DEFAULT default value
 * @param ENV an environment variable
 * @param LOCAL a local variable
 */
typedef enum vtype
{
	DEFAULT,
	ENV,
	LOCAL,
}	t_vtype;

//struct that stores the name, value and type of environment variable
// vexported: 1 if marked for export, 0 otherwise
typedef struct s_env
{
	char			*vname;
	char			*vvalue;
	int				vexported;
	t_vtype			vtype;
}	t_env;

//linked list to store each individual environment variable
typedef struct s_varlist
{
	t_env				*var;
	struct s_varlist	*next;
}	t_varlist;

/////////////////////////// TOKENS STRUCTS /////////////////////////////

/**
 * @brief enum to define the type of token
 * @note WORD, ENV_VAR, LOC_VAR, FILENAME are all considered words
 * @param NONE default value 								0
 * @param WORD a word or argument 							1
 * @param PIPE | 											2
 * @param REDIR_OUT > 										3
 * @param REDIR_APPEND >> 									4
 * @param REDIR_IN < 										5
 * @param HERE_DOC << 										6
 * @param ENV_VAR an environment variable 					7
 * @param LOC_VAR New local variable declaration 			8
 * @param UFO invalid input									9
 */
typedef enum s_tok
{
	NONE,
	WORD,
	PIPE,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_IN,
	HERE_DOC,
	ENV_VAR,
	LOC_VAR,
	FILENAME,
	UFO,
}	t_tok;

/**
 * @brief struct to store token type and its value
 * @param i position of token in the input string
 * @param value stored character string
 * @param type type of word
 */
typedef struct s_word
{
	int		i;
	char	*value;
	t_tok	type;
}	t_word;

/**
 * @brief struct to store each token of the input line
 * @param tok the token
 * @param next pointer to the next token
 * @param prev pointer to the previous token
 */
typedef struct s_args
{
	t_word			*tok;
	int				is_word;
	struct s_args	*next;
	struct s_args	*prev;
}	t_args;

/////////////////////////// AST STRUCTS /////////////////////////////
/**
 * @brief enum to define the type of node in the AST
 * @param DEFAULT_NODE default value
 * @param COMMAND_NODE a command (e.g., echo, ls)
 * @param PIPE_NODE a pipe (|)
 * @param REDIRECTION_NODE a redirection (>, >>, <, <<)
 */
typedef enum e_node_type
{
	DEFAULT_NODE,
	COMMAND_NODE,
	PIPE_NODE,
	REDIRECTION_NODE,
}	t_node_type;

/**
 * @brief Basic node of the abstract syntax tree
 * @param type PIPE_NODE, REDIRECTION_NODE, COMMAND_NODE
 * @param data pointer to either t_command or t_redir node
 * @param left left child
 * @param right right child
 */
typedef struct s_ast
{
	t_node_type		type;
	void			*data;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

typedef struct s_command
{
	char		*cmd;
	char		**args;
	int			argc;
}	t_command;

typedef struct s_redir
{
	t_tok		type;
	char		*file;
	char		*temp_file;
}	t_redir;

/////////////////////////// MINISH /////////////////////////////

/**
 * @brief The main struct that holds all the data
 * @param env_lst linked list of environment variables
 * @param local_vars linked list of local variables
 * @param input_line the input line from the user
 * @param args ft_split() of input_line
 * @param env_array array of environment variables
 * @param env_size size of the environment array
 * @param arg_lst linked list of tokens
 * @param ast abstract syntax tree used for execution
 * @param last_exit_status the exit status of the last command
 */
typedef struct s_minishell
{
	t_varlist	*env_lst;
	t_varlist	*local_vars;
	char		*input_line;
	char		**args;
	char		**env_array;
	ssize_t		env_size;
	t_args		*arg_lst;
	t_ast		*ast;
	int			last_exit_status;
}	t_minishell;

typedef struct s_minishell	t_mish;

/////////////////////////// builtin /////////////////////////////

//builtin.c
int			is_builtin(const char *cmd);
t_command	*extract_command_data(t_ast *ast);
int			exec_builtin(const char *cmd,
				t_command *cmd_data, t_mish *minish, int out_fd);
int			handle_builtin_command(const char *cmd, t_command *cmd_data,
				t_mish *minish, int out_fd);
int			exec_builtin(const char *cmd, t_command *cmd_data,
				t_mish *minish, int out_fd);

// cd.c
void		cd_error(const char *path);
int			change_directory(t_minishell *minish, const char *path);
char		*resolve_cd_path_home_or_oldpwd(t_command *node, t_mish *minish);
char		*resolve_cd_path(t_command *node, t_minishell *minish);
int			handle_cd(t_command *node, t_minishell *minish);

// echo.c

bool		is_valid_n_option(const char *str);
void		echo_write_args(t_command *node,
				t_minishell *minish, int out_fd, int start_index);
bool		echo_check_newline(t_command *node, int *start_index);
int			handle_echo(t_command *node, t_minishell *minish, int out_fd);
// size_t		ft_strcspn(const char *s, const char *reject);
// void		write_to_fd(int fd, const char *str, bool free_flag);
// int			handle_echo(t_command *node, t_minishell *minish, int out_fd);

// env.c

int			handle_env(t_command *node, t_minishell *minish);
char		*get_env_var(t_minishell *minish, const char *name);
void		set_env_var(t_minishell *minish,
				const char *name, const char *value);
// void	print_env(t_varlist *lst);
// int handle_env(t_command *node, t_minishell *minish);

//exit_invalid.c
int			exit_too_many_args(t_minishell *minish);
int			exit_invalid_arg(t_minishell *minish, t_command *node);
int			exit_many_arguments(t_minishell *minish,
				t_command *node, int arg_count);

// exit.c
int			is_valid_numeric(const char *str);
void		cleanup_varlist(t_varlist *varlist);
int			handle_exit(t_command *node, t_minishell *minish);
// int 	is_numeric(const char *str);
// void	cleanup_minishell(t_minishell *minish);

// export.c

char		*find_var_value(t_minishell *minish, const char *name);
int			add_or_update_env_var(t_minishell *minish, char *name, char *value);
void		print_exported_env(t_minishell *minish);
int			handle_export(t_command *node, t_minishell *minish);
// int	export_var(t_minishell *minish, char *var);
// int	add_or_update_env_var(t_minishell *minish, char *name, char *value);
// int		promote_local_var(t_minishell *minish, const char *arg);

//export2_utils.c

int			export_var(t_minishell *minish, char *var);

// pwd.c

int			handle_pwd(t_command *node);

// unset.c

int			unset_var(t_minishell *minish, const char *name);
int			handle_unset(t_command *node, t_minishell *minish);

/////////////////////////// env /////////////////////////////

//lst.c

void		ft_lstadd_back(t_varlist **alst, t_varlist *new);
t_varlist	*ft_lstlast(t_varlist *lst);
t_varlist	*ft_lstnew(void *content);
t_varlist	*find_var(t_varlist *var_list, const char *name);
ssize_t		get_env_size(char **envp);

//parse_env.c
char		*get_var_value(const char *cmd);
char		*get_var_name(const char *str);
void		add_var(t_minishell *minish, char *name, char *value, t_vtype type);
void		parse_env(t_minishell *minish, char **env_array);

//setup_env.c

void		duplicate_envp(t_minishell *minish, char **envp);
void		setup_env(char **envp, t_minishell *minish);
void		increment_shlvl(t_minishell *minish);
char		**generate_env_array(t_varlist *env_lst);
// void 	init_minish_struct(t_minishell *minish);

/////////////////////////// execution /////////////////////////////

// execute_cmd.c			(5 functions)

t_ast		*validate_command_ast(t_minishell *minish, t_ast *ast);
t_command	*extract_and_validate_command(t_minishell *minish,
				t_ast *redir_ast);
void		update_exit_status(t_minishell *minish, int status);
int			execute_cmd(t_minishell *minish, t_ast *ast);
// int	handle_command_or_redirection
//			(t_minishell *minish, t_ast *ast, int pipe_fds[2]);

//execute_new_minish.c		(5 functions)

int			handle_new_minishell(t_minishell *minish);

//execute_redir_cmd.c		(5 functions)

int			handle_command_or_redirection(t_minishell *minish,
				t_ast *ast, int pipe_fds[2]);

//execute_exec_utils.c		(4 functions)

char		*path_join(const char *dir, const char *command);
char		*find_executable(const char *cmd,
				t_varlist *env_lst, t_minishell *minish);
char		**convert_env_to_array(t_varlist *env_lst);

//external_exec.c			(5 functions)

void		update_env_array(t_minishell *minish);
int			execute_external(t_minishell *minish, t_command *cmd);

//start_shell.c				(5 functions)

char		*read_input(void);
void		update_exit_set_sigstatus(t_minishell *minish,
				int exit_status, int signal_status);
void		cleanup_heredoc_files(t_ast *node);
int			start_shell(t_minishell *minish);

// ///////////////////// execution_handlers /////////////////////////

//command_handler.c			(5 functions)

int			execute_builtin(t_minishell *minish, t_command *cmd);
int			handle_external_command(t_minishell *minish,
				t_ast *ast, t_command *cmd_data);
int			handle_command(t_minishell *minish, t_command *cmd);

//generate_temp_file.c		(3 functions)

char		*generate_temp_file_name(void);

//handle_variable_assignment.c	(4 functions)

int			handle_variable_assignment(t_minishell *minish,
				t_command *cmd_data);

//heredoc_handler_utils.c		(3 functions)

void		ft_heredoc_putstr(char *str, int fd);
void		process_heredoc_input(int fd, t_redir *dir, t_minishell *minish);
void		get_heredoc_line(int fd, t_redir *dir, t_minishell *minish);

//heredoc_handler.c				(3 functions)

int			preprocess_heredocs(t_minishell *minish, t_ast *ast);
void		handle_heredoc_redirection(t_redir *redir_data,
				t_minishell *minish);

//local_var_handler.c			(5 functions)

void		remove_local_var(t_varlist **local_vars, const char *name);
int			promote_variable(t_minishell *minish,
				const char *name, const char *value);
void		update_variable_value(t_varlist *var, char *value);
int			handle_local_var(t_minishell *minish, const char *cmd);

//pipe_handler.c				(3 functions)

int			execute_pipe(t_minishell *minish, t_ast *ast);

//redirection_handler.c			(5 functions)

int			handle_redirections_parent(t_ast *ast, int fd_backup[2]);
int			handle_redirections_child(t_ast *ast, t_minishell *minish);
// int	handle_heredocuments(t_minishell *minish, t_ast *ast);

//////////////////////// main ///////////////////////

//main.c

void		print_banner(void);
void		init_minish_struct(t_minishell *minish);
int			main(int ac, char **av, char **envp);

/////////////////////////// parsing /////////////////////////////

//new_nodes.c

t_ast		*new_ast_node(void);
t_redir		*new_redir_node(void);
t_command	*new_cmd_node(int arg_count);

//parse_ast.c

t_ast		*process_redirection_ast(t_ast *redir_chain, t_ast **last_redir,
				t_args **curr_tok);
void		append_cmd(t_ast **redir_ast, t_ast *cmd_node);
void		add_args_to_cmd(t_command *cmd_node,
				t_args *curr_tok, int arg_count);
int			create_ast(t_minishell *minish);

//parse_utils.c

void		increment_tok(t_args **curr_tok);
int			count_args(t_args *arg);
int			is_redir(t_tok type);

//parse.c

t_ast		*parse_pipe(t_args **curr_tok);
t_ast		*parse_redir(t_args **curr_tok);
t_ast		*parse_command(t_args **curr_tok);

//redir_chain.c

t_ast		*make_redir_chain(t_args **curr_tok);
t_ast		*fill_redir_info(t_args **curr_tok);
t_args		**find_cmd_tok(t_args **curr_tok);
t_args		**find_next_pipe(t_args **curr_tok);

/////////////////////// signals ///////////////////////

// void	child_handle_sigint(int signum);
// void	ft_heredoc_test(void);
// void	handle_ctrl_d(char *input, t_minishell *minish);

/////////////////////// syntax ///////////////////////

//syntax_error.c

void		pipe_error(t_minishell *minish);
void		redir_error(t_minishell *minish);
void		heredoc_error(t_minishell *minish);

//syntax.c

int			syntax_check(t_minishell *minish);
void		pipe_syntax(t_args *arg, int *error);
void		redir_syntax(t_args *arg, int *error);
void		heredoc_syntax(t_args *arg, int *error);

/////////////////////// tokens ///////////////////////
# define TRUE 1
# define FALSE 0

//args_lst.c

t_args		*arg_lstlast(t_args *arg_lst);
void		arg_lstadd_back(t_args **arg_lst, t_args *new_node);
t_args		*arg_lstnew(t_word *tok);
void		add_arg_lst(t_minishell *minish, char *arg, t_tok type, int i);

//expand_tokens.c

char		*expand_token(t_minishell *minish, char *var);
void		append_expanded(t_mish *minish, char **res, int *j, char *token);
char		*grab_dollar(char *token, int len);
int			len_of_var(char *token);

//fix_input_utils.c

void		handle_pipe(char **res, char **tmp, int *i);
void		handle_redir_out(char **res, char **tmp, int *i);
void		handle_redir_in(char **res, char **tmp, int *i);
void		handle_dollar(char **res, char **tmp, int *i);
void		add_space(char **res, int *i);

//fix_input.c

int			count_operators(char *input);
char		*clean_input(char **input);
int			do_cleanup(char **res, char **tmp);

//identify.c

t_tok		identify_redir(char *token);
t_tok		identify_token(char *str);
int			is_new_localvar(char *token);
t_tok		valid_localvar(char *token);

//lexer.c

int			ft_lexer(t_minishell *minish);
int			split_args(t_minishell *minish, char *input);
void		find_files(t_args *arg_lst);

//process_tokens.c

typedef enum e_quote_state
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}			t_quote_state;

int			init_prcs_tok(int *i, int *j, char **res, t_quote_state *state);
char		*process_token(t_minishell *minish, char *token);
bool		update_state(char c, t_quote_state *state);

//quotes.c

int			find_quotes(char *input);
int			quotes_complete(char *input);
void		remove_spaces(char *input);
void		restore_spaces(char *input);

//tokens.c

t_tok		identify_token(char *str);
int			is_new_localvar(char *token);
int			is_command(char *token);
int			is_minishell(char *token);

//valid.c

t_tok		valid_pipe(char *token);
int			seek_equal_localvar(char *str, int equal_pos);
int			valid_redir(char *token);

/////////////////////// utils //////////////////////

//cleanup.c

void		ft_error(t_minishell *minish, char *msg);
void		free_user_input(t_minishell *minish);
void		free_arglst(t_minishell *minish);
void		reset_minish(t_minishell *minish);
void		cleanup_minishell(t_minishell *minish);

//execution_utils.c

void		handle_redirection_standalone(t_minishell *minish, t_ast *ast);
void		backup_original_fd(int fd_backup[2], int std_fd);
char		*ft_strjoin_three(const char *s1, const char *s2, const char *s3);
char		*get_env_value(t_varlist *env, const char *var_name);
char		*get_path_from_env(t_varlist *env_lst);

//free_ast.c

void		free_ast(t_ast *node);
void		free_node_data(t_ast *node);
void		free_redirection_node(t_redir *redir);
void		free_command_node(t_command *cmd);

//free.c	(5 functions)

void		free_array(char **array);
void		free_var(t_env *var);
void		free_varlist(t_varlist *list);

//validate_utils.c
int			is_valid_identifier(const char *name);
int			validate_identifier(const char *identifier);
int			is_valid_executable_path(t_command *cmd);
int			is_invalid_directory_usage(t_command *cmd);
char		*get_parent_directory(const char *path);

//test_funcs
int			ft_isspace(char c);
void		print_ast(t_ast *ast, int depth, int is_last);
//process_signs.c
//
// char	*process_dollar_sign(const char **ptr, t_mish *minish, char *expanded);
// char	*process_quotes(const char **ptr, t_minishell *minish, char *expanded);
/*
void	print_env_all_type(t_varlist *lst);
void	print_arg_lst(t_args *arg_lst);
void	print_array(char **env_array);
void	ft_print_type(t_tok type, char *str);
void	print_indentation(int depth, int is_last);

 */
//extras
// int	promote_variable(t_mish *minish, const char *name, const char *value);
// void	update_variable_value(t_varlist *var, char *value);
// int	validate_identifier(const char *identifier, const char *error_context);

// ANSI color codes
# define COLOR_RESET   "\033[0m"
# define COLOR_CYAN    "\033[36m"
# define COLOR_YELLOW  "\033[33m"
# define COLOR_MAGENTA "\033[35m"
# define COLOR_GREEN   "\033[32m"
# define COLOR_RED     "\033[31m"

//define variables
# define PLACEHOLDER 0x1F

//define error messages
# define ERR_MALLOC "Error: malloc failed\n"

#endif
