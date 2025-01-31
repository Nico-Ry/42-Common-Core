/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:37:02 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 14:45:56 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Identifies and returns the type of token
 */
t_tok	identify_token(char *str)
{
	char	*token;

	token = str;
	if (*token == '|')
		return (PIPE);
	else if (*token == '<' || *token == '>')
		return (identify_redir(token));
	return (WORD);
}

/**
 * @brief Checks if a string contains an `=`
 * and is likely a new local variable declaration
 * @return TRUE if an `=` is found, FALSE otherwise
 */
int	is_new_localvar(char *token)
{
	int	i;

	i = 0;
	if (token[0] == '=')
		return (FALSE);
	while (token[i])
	{
		if (token[i] == '=')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/**
 * @brief checks that everything up to the first '=' is a valid local variable
 * @return LOC_VAR if yes, UFO if invalid local variable name
 */
t_tok	valid_localvar(char *token)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(token[0]) || token[0] == '_'))
	{
		ft_putstr_fd("miniHell: ", STDERR_FILENO);
		ft_putstr_fd(": `", STDERR_FILENO);
		write(STDERR_FILENO, token, ft_strlen(token));
		ft_putstr_fd("`: not a valid identifier\n", STDERR_FILENO);
		return (UFO);
	}
	while (token[i] && token[i] != '=')
	{
		if (!(ft_isalnum(token[i]) || token[i] == '_'))
		{
			ft_putstr_fd("miniHell: ", STDERR_FILENO);
			ft_putstr_fd(": `", STDERR_FILENO);
			write(STDERR_FILENO, token, ft_strlen(token));
			ft_putstr_fd("`: not a valid identifier\n", STDERR_FILENO);
			return (UFO);
		}
		i++;
	}
	return (LOC_VAR);
}

/**
 * @brief Identifies what type of redirection the token is
 * @return >, <, >>, << accordingly
 */
t_tok	identify_redir(char *token)
{
	if (token[0] == '>')
	{
		if (token[1] == '>')
			return (REDIR_APPEND);
		else
			return (REDIR_OUT);
	}
	else
	{
		if (token[1] == '<')
			return (HERE_DOC);
		else
			return (REDIR_IN);
	}
}
