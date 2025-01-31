/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:33:49 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 13:33:49 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Prints an error message, frees all (allegedly)
 * allocated memory and exits the program
 * @param minish the mother of all structs
 * @param msg the error message to print
 */
void	ft_error(t_minishell *minish, char *msg)
{
	cleanup_minishell(minish);
	printf("Error:\n%s", msg);
	exit(EXIT_FAILURE);
}

/**
 * @brief Frees minish->input_line and sets it to NULL
 */
void	free_user_input(t_minishell *minish)
{
	char	*line;

	if (!minish->input_line)
		return ;
	line = minish->input_line;
	free(line);
	minish->input_line = NULL;
}

/**
 * @brief Frees all nodes of minish->arg_lst linked list.
 * @note As arg_lst->value points to the same memory as minimsh->args,
 * we only need to free the nodes and not tmp->value
 * (value is freed by free_array(minish->args))
 * in `reset_minish()`
 */
void	free_arglst(t_minishell *minish)
{
	t_args	*tmp;
	t_args	*next;

	if (!minish->arg_lst)
		return ;
	tmp = minish->arg_lst;
	while (tmp)
	{
		if (tmp->next)
			next = tmp->next;
		else
			next = NULL;
		if (tmp->tok)
		{
			free(tmp->tok->value);
			free(tmp->tok);
		}
		free(tmp);
		tmp = next;
	}
}
	// free(minish->arg_lst);

/**
 * @brief Frees and resets all relevant fields of
 * the minishell struct to NULL or 0.
 * between each prompt.
 */
void	reset_minish(t_minishell *minish)
{
	free_user_input(minish);
	free_array(minish->args);
	free_arglst(minish);
	free_ast(minish->ast);
	minish->input_line = NULL;
	minish->args = NULL;
	minish->arg_lst = NULL;
	minish->ast = NULL;
}

/**
 * @brief Cleans up the minishell context.
 */
void	cleanup_minishell(t_minishell *minish)
{
	reset_minish(minish);
	free_varlist(minish->env_lst);
	free_varlist(minish->local_vars);
	if (minish->env_array)
		free_array(minish->env_array);
	free(minish);
}
