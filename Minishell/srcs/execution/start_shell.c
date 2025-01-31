/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:31:48 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 14:32:02 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * @brief Reads user input from the terminal.
 * @note Uses readline to retrieve input
 * and adds it to history if it's non-empty.
 * If EOF (Ctrl+D) is detected, exits the shell.
 *
 * @return char* The input string entered by the user.
 */
char	*read_input(void)
{
	char	*input;

	input = readline(":$ ");
	if (!input)
	{
		printf("exit\n");
		exit(0);
	}
	if (*input)
		add_history(input);
	return (input);
}

/*
 * @brief Updates the last exit status and signal status of the shell.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param exit_status The exit status to set.
 * @param signal_status The signal status to set.
 */
void	update_exit_set_sigstatus(t_minishell *minish,
	int exit_status, int signal_status)
{
	minish->last_exit_status = exit_status;
	g_signal_status = signal_status;
}

/*
 * @brief Cleans up temporary files created by heredoc redirections.
 * @note Recursively traverses the AST to find and delete heredoc files.
 *
 * @param node The AST node to process.
 */
void	cleanup_heredoc_files(t_ast *node)
{
	t_redir	*redir;

	if (!node)
		return ;
	cleanup_heredoc_files(node->left);
	cleanup_heredoc_files(node->right);
	if (node->type == REDIRECTION_NODE)
	{
		redir = (t_redir *)node->data;
		if (redir->type == HERE_DOC && redir->temp_file)
		{
			unlink(redir->temp_file);
			free(redir->temp_file);
			redir->temp_file = NULL;
		}
	}
}

/*
 * @brief Handles user input for the shell.
 * @note Reads input, checks for signal
 * interruptions, and processes EOF (Ctrl+D).
 *
 * @param minish The minishell structure containing environment and state data.
 * @return int Returns 1 if input is successfully read, 0 otherwise.
 */
static int	handle_shell_input(t_minishell *minish)
{
	minish->input_line = read_input();
	if (g_signal_status == 130)
	{
		minish->last_exit_status = g_signal_status;
		g_signal_status = 0;
	}
	if (!minish->input_line)
	{
		handle_ctrl_d(minish->input_line, minish);
		return (0);
	}
	return (1);
}

/*
 * @brief Starts the main shell loop.
 * @note Handles signals, reads user input,
 * processes commands, and executes them.
 *
 * @param minish The minishell structure containing environment and state data.
 * @return int The final exit status of the shell.
 */
int	start_shell(t_minishell *minish)
{
	int	status;

	setup_signals();
	status = 0;
	while (1)
	{
		reset_minish(minish);
		if (!handle_shell_input(minish))
			continue ;
		if (!ft_lexer(minish))
		{
			minish->last_exit_status = 1;
			continue ;
		}
		if (syntax_check(minish) == 2)
			continue ;
		if (!create_ast(minish))
			continue ;
		status = execute_cmd(minish, minish->ast);
		cleanup_heredoc_files(minish->ast);
	}
	return (status);
}
// print_ast(minish->ast, 0, 1);
