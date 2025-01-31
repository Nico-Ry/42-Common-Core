/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 03:57:02 by nryser            #+#    #+#             */
/*   Updated: 2025/01/04 03:57:02 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief checks if the arg_lst is empty, if not it calls parse_pipe()
 * and sets minish->ast to the root node returned by parse_pipe()
 */
int	create_ast(t_minishell *minish)
{
	t_ast	*ast;
	t_args	*first_tok;

	ast = NULL;
	first_tok = minish->arg_lst;
	if (!minish->arg_lst)
		return (0);
	ast = parse_pipe(&minish->arg_lst);
	if (!ast)
	{
		printf("Error: AST creation failed\n");
		return (0);
	}
	minish->ast = ast;
	minish->arg_lst = first_tok;
	return (1);
}

/**
 * @brief if the current token is a pipe, it creates a pipe node
 * and stores the left child as the result of parse_redir()
 * if the current token is not a pipe, it returns the result of parse_redir()
 * @note Each of the following functions increment curr_token as appropriate:
 * `parse_command()` `parse_redir()` `parse_pipe()`
 */
t_ast	*parse_pipe(t_args **curr_tok)
{
	t_ast	*pipe_node;
	t_ast	*left_node;

	if (!curr_tok || !(*curr_tok))
		return (NULL);
	left_node = parse_redir(curr_tok);
	if (!left_node)
		return (NULL);
	while ((*curr_tok) && (*curr_tok)->tok && (*curr_tok)->tok->type == PIPE)
	{
		pipe_node = new_ast_node();
		if (!pipe_node)
			return (NULL);
		pipe_node->type = PIPE_NODE;
		pipe_node->data = NULL;
		pipe_node->left = left_node;
		increment_tok(curr_tok);
		pipe_node->right = parse_redir(curr_tok);
		if (!pipe_node->right)
			return (NULL);
		left_node = pipe_node;
	}
	return (left_node);
}

/**
 * @brief if the current token is a word, it calls parse_command()
 * to create a command node if the current token is a redirection
 * operator, it creates a redirection node and stores the
 * command node as the left child of the redirection node
 * @note Each of the following functions increment curr_token as appropriate:
 * `parse_command()` `parse_redir()` `parse_pipe()`
 */
/**
 * @brief Parses commands with redirection operators (> < >> <<)
 */
t_ast	*parse_redir(t_args **curr_tok)
{
	t_ast	*cmd_node;
	t_ast	*redir_ast;

	cmd_node = NULL;
	redir_ast = NULL;
	if (!curr_tok || !(*curr_tok))
		return (NULL);
	if (!cmd_node && (*curr_tok) && (*curr_tok)->is_word)
		cmd_node = parse_command(curr_tok);
	if ((*curr_tok) && is_redir((*curr_tok)->tok->type))
	{
		redir_ast = make_redir_chain(curr_tok);
		curr_tok = find_cmd_tok(curr_tok);
	}
	if (!cmd_node && (*curr_tok) && (*curr_tok)->is_word
		&& (!is_redir((*curr_tok)->prev->tok->type)))
		cmd_node = parse_command(curr_tok);
	if (redir_ast)
		append_cmd(&redir_ast, cmd_node);
	else if (!cmd_node)
		return (NULL);
	curr_tok = find_next_pipe(curr_tok);
	if (redir_ast)
		return (redir_ast);
	return (cmd_node);
}

/**
 * @brief creates a t_command node which it stores in t_ast *node->data
 * the t_command node is comprised of `cmd` which stores the str value
 * of the first token it encounters (given is_word = true) all subsequent
 * tokens which is_word = true for are stored in char **args in the t_command
 * node
 * @note Each of the following functions increment curr_token as appropriate:
 * `parse_command()` `parse_redir()` `parse_pipe()`
 * @return an `ast_node` with a command_node and all relevant info stored
 * within it
 */
t_ast	*parse_command(t_args **curr_tok)
{
	t_ast		*new_node;
	t_command	*cmd_node;
	int			arg_count;

	if (!curr_tok || !(*curr_tok))
		return (NULL);
	new_node = new_ast_node();
	if (!new_node)
		return (NULL);
	arg_count = count_args((*curr_tok));
	cmd_node = new_cmd_node(arg_count);
	cmd_node->cmd = ft_strdup((*curr_tok)->tok->value);
	cmd_node->args = malloc(sizeof(char *) * (arg_count + 1));
	cmd_node->args[0] = ft_strdup((*curr_tok)->tok->value);
	increment_tok(curr_tok);
	if (arg_count > 1)
		add_args_to_cmd(cmd_node, *curr_tok, 1);
	cmd_node->args[arg_count] = NULL;
	new_node->type = COMMAND_NODE;
	new_node->data = cmd_node;
	new_node->left = NULL;
	new_node->right = NULL;
	while ((*curr_tok)->next && (*curr_tok)->is_word)
		increment_tok(curr_tok);
	return (new_node);
}
