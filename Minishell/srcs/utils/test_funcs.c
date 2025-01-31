/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 00:26:18 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 00:31:42 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Checks if a character is a space
 * @return True if the character is a space, False otherwise
 */
int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

// /**
//  * @brief Used to print the contents of minish->env
//  * @param lst minish->env (the linked list with parsed elements from envp)
//  */
// void	print_env_all_type(t_varlist *lst)
// {
// 	t_varlist	*tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		printf("vname: %s\n", tmp->var->vname);
// 		printf("vvalue: %s\n", tmp->var->vvalue);
// 		printf("vtype: %d\n", tmp->var->vtype);
// 		tmp = tmp->next;
// 	}
// }

// /**
//  * @brief prints all the contents of a char **array
//  * @param env_array the array to print
//  */
// void	print_array(char **env_array)
// {
// 	int		i;

// 	i = 0;
// 	while (env_array[i])
// 	{
// 		printf("%s\n", env_array[i]);
// 		i++;
// 	}
// }

// /**
//  * @brief Prints the type of token and the token itself
//  */
// void	ft_print_type(t_tok type, char *str)
// {
// 	printf("Token: %s\n", str);
// 	if (type == '0')
// 		printf("Type: NONE (%d)\n", type);
// 	else if (type == 1)
// 		printf("Type: WORD (%d)\n", type);
// 	else if (type == 2)
// 		printf("Type: PIPE (%d)\n", type);
// 	else if (type == 3)
// 		printf("Type: REDIR_OUT (%d)\n", type);
// 	else if (type == 4)
// 		printf("Type: REDIR_APPEND (%d)\n", type);
// 	else if (type == 5)
// 		printf("Type: REDIR_IN (%d)\n", type);
// 	else if (type == 6)
// 		printf("Type: HERE_DOC (%d)\n", type);
// 	else if (type == 7)
// 		printf("Type: ENV_VAR (%d)\n", type);
// 	else if (type == 8)
// 		printf("Type: LOC_VAR (%d)\n", type);
// 	else if (type == 9)
// 		printf("Type: FILENAME (%d)\n", type);
// 	else if (type == 10)
// 		printf("Type: UFO (%d)\n", type);
// }

// /**
//  * @brief Prints the contents of minish->arg_lst
//  * @param arg_lst the linked list to print
//  */
// void	print_arg_lst(t_args *arg_lst)
// {
// 	t_args	*tmp;

// 	tmp = arg_lst;
// 	printf("Printing arg_lst\n");
// 	printf("###############\n");
// 	while (tmp)
// 	{
// 		ft_print_type(tmp->tok->type, tmp->tok->value);
// 		printf("Index: %d\n", tmp->tok->i);
// 		printf("###############\n");
// 		tmp = tmp->next;
// 	}
// }

// // Helper function to print indentation and tree markers
// void	print_indentation(int depth, int is_last)
// {
// 	for (int i = 0; i < depth; i++)
// 		printf("%s", (i + 1 == depth && is_last) ? "    " : "│   ");
// 	if (depth > 0)
// 		printf("%s", is_last ? "└── " : "├── ");
// }

// // Print the AST recursively
// void	print_ast(t_ast *ast, int depth, int is_last)
// {
// 	t_command	*cmd;
// 	t_redir		*redir;

// 	if (!ast)
// 		return ;
// 	print_indentation(depth, is_last);
// 	if (ast->type == COMMAND_NODE)
// 	{
// 		cmd = (t_command *)ast->data;
// 		if (!cmd)
// 		{
// 			printf(COLOR_RED "Invalid Command Node\n" COLOR_RESET);
// 			return ;
// 		}
// 		printf(COLOR_CYAN "Command Node:\n" COLOR_RESET);
// 		print_indentation(depth + 1, 0);
// 		printf(COLOR_GREEN "Command: %s\n" COLOR_RESET,
// 			cmd->cmd ? cmd->cmd : "(null)");
// 		for (int i = 0; i < cmd->argc && cmd->args; i++)
// 		{
// 			print_indentation(depth + 1, i == cmd->argc - 1);
// 			printf(COLOR_GREEN "Arg[%d]: %s\n" COLOR_RESET,
// 				i, cmd->args[i] ? cmd->args[i] : "(null)");
// 		}
// 	}
// 	else if (ast->type == REDIRECTION_NODE)
// 	{
// 		redir = (t_redir *)ast->data;
// 		if (!redir)
// 		{
// 			printf(COLOR_RED "Invalid Redirection Node\n" COLOR_RESET);
// 			return ;
// 		}
// 		printf(COLOR_YELLOW "Redirection Node:\n" COLOR_RESET);
// 		print_indentation(depth + 1, 0);
// 		printf(COLOR_YELLOW "Type: %s\n" COLOR_RESET,
// 			(redir->type == REDIR_OUT) ? ">" :
// 			(redir->type == REDIR_APPEND) ? ">>" :
// 			(redir->type == REDIR_IN) ? "<" :
// 			(redir->type == HERE_DOC) ? "<<" : "Unknown");
// 		print_indentation(depth + 1, 1);
// 		printf(COLOR_YELLOW "File: %s\n" COLOR_RESET,
// 				redir->file ? redir->file : "(null)");
// 		if (ast->left)
// 		{
// 			print_indentation(depth + 1, 0);
// 			printf(COLOR_YELLOW "Left Child:\n" COLOR_RESET);
// 			print_ast(ast->left, depth + 2, 1);
// 		}
// 		else
// 		{
// 			print_indentation(depth + 1, 1);
// 			printf(COLOR_RED "No Left Child\n" COLOR_RESET);
// 		}
// 	}
// 	else if (ast->type == PIPE_NODE)
// 	{
// 		printf(COLOR_MAGENTA "Pipe Node:\n" COLOR_RESET);
// 		if (ast->left)
// 		{
// 			print_indentation(depth + 1, ast->right == NULL);
// 			print_ast(ast->left, depth + 1, ast->right == NULL);
// 		}
// 		if (ast->right)
// 		{
// 			print_ast(ast->right, depth + 1, 1);
// 		}
// 	}
// 	else
// 	{
// 		printf(COLOR_RED "Unknown Node Type\n" COLOR_RESET);
// 	}
// }
