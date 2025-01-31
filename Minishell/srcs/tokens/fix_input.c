/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:40:44 by nryser            #+#    #+#             */
/*   Updated: 2025/01/28 23:42:08 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Counts the number of operators in the input string
 * @return the number of operators
 */
int	count_operators(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '|' || (input[i] == '$' && input[i + 1]))
			count++;
		else if (input[i] == '>')
		{
			if (input[i + 1] == '>')
				i++;
			count++;
		}
		else if (input[i] == '<')
		{
			if (input[i + 1] == '<')
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * @brief Cleans up the input string by adding spaces around operators.
 *		  Allocates a new string with sufficient space and frees the original.
 * @param input Pointer to the original input string.
 * @return The cleaned-up input string, or NULL on failure.
 */
char	*clean_input(char **input)
{
	char	*res;
	char	*tmp;
	int		count;

	tmp = *input;
	count = count_operators(tmp);
	res = malloc(sizeof(char) * (ft_strlen(tmp) + (count * 2) + 1));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	do_cleanup(&res, &tmp);
	free(*input);
	*input = NULL;
	return (res);
}

/**
 * @brief Cleans up the input by adding spaces around
 * operators like '|', '>', '<'.
 * Modifies the result string `res` and reads
 * from the temporary string `tmp`.
 * @param res The resulting cleaned-up string.
 * @param tmp The input string to process.
 * @return 1 (true) on success, 0 (false) on failure.
 */
int	do_cleanup(char **res, char **tmp)
{
	int	i;

	i = 0;
	if (!res || !*res || !tmp || !*tmp)
		return (0);
	while (**tmp)
	{
		if (**tmp == '|')
			handle_pipe(res, tmp, &i);
		else if (**tmp == '>')
			handle_redir_out(res, tmp, &i);
		else if (**tmp == '<')
			handle_redir_in(res, tmp, &i);
		else
		{
			(*res)[i] = **tmp;
			i++;
			(*tmp)++;
		}
	}
	(*res)[i] = '\0';
	return (1);
}
