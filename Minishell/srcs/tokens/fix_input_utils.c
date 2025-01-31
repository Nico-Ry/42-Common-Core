/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_input_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:39:55 by nryser            #+#    #+#             */
/*   Updated: 2025/01/28 23:40:06 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Helper funtion for fix_input. Checks if a pipe
 * is preceded or followed by a space and adds one if not.
 * Also properly increments all pointers accordingly
 * @param res the new string being generated
 * @param tmp the original string
 * @param i the current position in res (used by fix_input)
 */
void	handle_pipe(char **res, char **tmp, int *i)
{
	if (*i > 0 && (*res)[*i - 1] != ' ')
		add_space(res, i);
	(*res)[*i] = '|';
	(*i)++;
	if ((*tmp)[1] != ' ')
		add_space(res, i);
	(*tmp)++;
}

/**
 * @brief Helper funtion for fix_input. Checks if a `>` or `>>`
 * redirection is preceded or followed by a space and adds one if not.
 * Also properly increments all pointers accordingly
 * @param res the new string being generated
 * @param tmp the original string
 * @param i the current position in res (used by fix_input)
 */
void	handle_redir_out(char **res, char **tmp, int *i)
{
	if (*i > 0 && (*res)[*i - 1] != ' ')
		add_space(res, i);
	(*res)[*i] = '>';
	(*i)++;
	if ((*tmp)[1] == '>')
	{
		(*res)[*i] = '>';
		(*i)++;
		if ((*tmp)[2] != ' ')
			add_space(res, i);
		(*tmp)++;
	}
	else if ((*tmp)[1] != ' ')
		add_space(res, i);
	(*tmp)++;
}

/**
 * @brief Helper funtion for fix_input. Checks if a `<` or `<<`
 * redirection is preceded or followed by a space and adds one if not.
 * Also properly increments all pointers accordingly
 * @param res the new string being generated
 * @param tmp the original string
 * @param i the current position in res (used by fix_input)
 */
void	handle_redir_in(char **res, char **tmp, int *i)
{
	if (*i > 0 && (*res)[*i - 1] != ' ')
		add_space(res, i);
	(*res)[*i] = '<';
	(*i)++;
	if ((*tmp)[1] == '<')
	{
		(*res)[*i] = '<';
		(*i)++;
		if ((*tmp)[2] != ' ')
			add_space(res, i);
		(*tmp)++;
	}
	else if ((*tmp)[1] != ' ')
		add_space(res, i);
	(*tmp)++;
}

/* void	handle_dollar(char **res, char **tmp, int *i)
{
	printf("find a solution for dollars\n");
} */
/**
 * @brief Helper funtion for fix_input. Adds a space to the new string
 * and increments the position in the new string
 * @param res the new string being generated
 * @param i the current position in res (used by fix_input)
 */
void	add_space(char **res, int *i)
{
	(*res)[*i] = ' ';
	(*i)++;
}
