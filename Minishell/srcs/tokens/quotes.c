/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:49:38 by nryser            #+#    #+#             */
/*   Updated: 2025/01/28 23:49:58 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Checks if there are quotes in the input
 * @return True if there are quotes, False otherwise
 */
int	find_quotes(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/**
 * @brief Checks if the quotes in the input are complete
 * @return True if the quotes are complete, False otherwise
 */
int	quotes_complete(char *input)
{
	int	in_sgl;
	int	in_dbl;
	int	i;

	in_sgl = FALSE;
	in_dbl = FALSE;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' && in_dbl == FALSE)
			in_sgl = !in_sgl;
		if (input[i] == '"' && in_sgl == FALSE)
			in_dbl = !in_dbl;
		i++;
	}
	if (in_sgl || in_dbl)
		return (FALSE);
	return (TRUE);
}

/**
 * @brief Replaces all spaces enclosed in quotes with '#'
 * so ft_split considers it as a single word
 * @param input the input string
 */
void	remove_spaces(char *input)
{
	int	in_sgl;
	int	in_dbl;
	int	i;

	in_sgl = FALSE;
	in_dbl = FALSE;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' && in_dbl == FALSE)
			in_sgl = !in_sgl;
		if (input[i] == '"' && in_sgl == FALSE)
			in_dbl = !in_dbl;
		if ((in_sgl || in_dbl) && input[i] == ' ')
			input[i] = PLACEHOLDER;
		i++;
	}
}

/**
 * @brief Restores the spaces replaced by '#' in remove_spaces
 */
void	restore_spaces(char *input)
{
	int	in_sgl;
	int	in_dbl;
	int	i;

	in_sgl = FALSE;
	in_dbl = FALSE;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' && in_dbl == FALSE)
			in_sgl = !in_sgl;
		if (input[i] == '"' && in_sgl == FALSE)
			in_dbl = !in_dbl;
		if ((in_sgl || in_dbl) && input[i] == PLACEHOLDER)
			input[i] = ' ';
		i++;
	}
}
