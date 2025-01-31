/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:32:24 by ameechan          #+#    #+#             */
/*   Updated: 2025/01/30 13:28:13 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Allocates memory for a new AST node
 * initializes the type to DEFAULT_NODE
 * and the left and right children to NULL
 * @return a pointer to the new AST node
 */
t_ast	*new_ast_node(void)
{
	t_ast	*ast_node;

	ast_node = malloc(sizeof(t_ast));
	if (!ast_node)
	{
		free(ast_node);
		return (NULL);
	}
	ast_node->type = DEFAULT_NODE;
	ast_node->left = NULL;
	ast_node->right = NULL;
	return (ast_node);
}

/**
 * @brief Allocates memory for a new redirection node
 * initializes the type to NONE
 * and the file and cmd to NULL
 * @return a pointer to the new redirection node
 */
t_redir	*new_redir_node(void)
{
	t_redir	*redir_node;

	redir_node = NULL;
	redir_node = malloc(sizeof(t_redir));
	if (!redir_node)
	{
		free(redir_node);
		return (NULL);
	}
	redir_node->type = NONE;
	redir_node->file = NULL;
	redir_node->temp_file = NULL;
	return (redir_node);
}

/**
 * @brief Allocates memory for a new command node.
 * Initializes cmd and args to NULL,
 * sets argc to arg_count.
 * @param arg_count the number of arguments in the command
 * @return a pointer to the new command node
 */
t_command	*new_cmd_node(int arg_count)
{
	t_command	*cmd_node;

	cmd_node = malloc(sizeof(t_command));
	if (!cmd_node)
	{
		free(cmd_node);
		return (NULL);
	}
	cmd_node->cmd = NULL;
	cmd_node->args = NULL;
	cmd_node->argc = arg_count;
	return (cmd_node);
}
