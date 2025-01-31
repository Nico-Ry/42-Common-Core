/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:11:44 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 20:11:44 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * @brief Validates whether an AST node represents
 * a valid command or redirection.
 * @note If the node is a redirection, it traverses to the leftmost command node.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param ast The AST node to validate.
 * @return t_ast* The validated command node, or NULL on failure.
 */
t_ast	*validate_command_ast(t_minishell *minish, t_ast *ast)
{
	t_ast	*redir_ast;

	if (ast->type != COMMAND_NODE && ast->type != REDIRECTION_NODE)
	{
		minish->last_exit_status = EXIT_FAILURE;
		return (NULL);
	}
	redir_ast = ast;
	while (redir_ast && redir_ast->type == REDIRECTION_NODE)
		redir_ast = redir_ast->left;
	return (redir_ast);
}

/*
 * @brief Extracts and validates command data from a command AST node.
 * @note Also handles variable assignment if present.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param redir_ast The AST node to extract command data from.
 * @return t_command* The extracted command data, or NULL if invalid.
 */
t_command	*extract_and_validate_command(t_minishell *minish,
						t_ast *redir_ast)
{
	t_command	*cmd_data;

	if (redir_ast && redir_ast->type == COMMAND_NODE)
		cmd_data = extract_command_data(redir_ast);
	else
		cmd_data = NULL;
	if (cmd_data && handle_variable_assignment(minish, cmd_data)
		== EXIT_SUCCESS)
		return (NULL);
	return (cmd_data);
}

/*
 * @brief Updates the last exit status based on the status returned by waitpid.
 * @note Normalizes the exit status using WEXITSTATUS or WIFSIGNALED.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param status The raw status returned by waitpid.
 */
void	update_exit_status(t_minishell *minish, int status)
{
	if (status == 0 && minish->last_exit_status >= 128)
		return ;
	if (status >= 0 && status < 256)
		minish->last_exit_status = status;
	else if (WIFSIGNALED(status))
		minish->last_exit_status = 128 + WTERMSIG(status);
	else if (WIFEXITED(status))
		minish->last_exit_status = WEXITSTATUS(status);
	else
		minish->last_exit_status = status;
}

/*
 * @brief Determines and executes the appropriate execution strategy.
 * @note Handles pipelines, redirections, and regular commands.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param ast The AST node to execute.
 * @return int The exit status of the executed command.
 */
static int	handle_execution_strategy(t_minishell *minish, t_ast *ast)
{
	int	status;

	if (ast->type == PIPE_NODE)
	{
		if (preprocess_heredocs(minish, ast) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		status = execute_pipe(minish, ast);
	}
	else if (ast->type == REDIRECTION_NODE)
		status = handle_command_or_redirection(minish, ast, NULL);
	else
		status = handle_command_or_redirection(minish, ast, NULL);
	status = minish->last_exit_status;
	update_exit_status(minish, status);
	return (status);
}

/*
 * @brief Executes a command based on the type of AST node.
 * @note Handles pipelines, redirections, and heredocuments before execution.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param ast The AST node to execute.
 * @return int The exit status of the executed command.
 */
int	execute_cmd(t_minishell *minish, t_ast *ast)
{
	int	status;

	if (!ast)
	{
		ft_putstr_fd("[DEBUG] execute_cmd: NULL AST node\n", 2);
		return (EXIT_FAILURE);
	}
	if (ast->type != PIPE_NODE
		&& preprocess_heredocs(minish, ast) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	status = handle_execution_strategy(minish, ast);
	update_exit_status(minish, status);
	return (status);
}
