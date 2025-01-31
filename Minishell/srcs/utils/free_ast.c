/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:22:09 by ameechan          #+#    #+#             */
/*   Updated: 2025/01/29 19:45:29 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Recursively frees an AST node and its children.
 *
 * @param node The AST node to free.
 */
void	free_ast(t_ast *node)
{
	if (!node)
		return ;
	free_ast(node->left);
	free_ast(node->right);
	free_node_data(node);
	free(node);
}

void	free_node_data(t_ast *node)
{
	if (!node || !node->data)
		return ;
	if (node->type == COMMAND_NODE)
		free_command_node((t_command *)node->data);
	else if (node->type == REDIRECTION_NODE)
		free_redirection_node((t_redir *)node->data);
}

void	free_redirection_node(t_redir *redir)
{
	if (!redir)
		return ;
	free(redir->file);
	if (redir->temp_file)
	{
		unlink(redir->temp_file);
		free(redir->temp_file);
	}
	free(redir);
}

void	free_command_node(t_command *cmd)
{
	if (!cmd)
		return ;
	free_array(cmd->args);
	free(cmd->cmd);
	free(cmd);
}
