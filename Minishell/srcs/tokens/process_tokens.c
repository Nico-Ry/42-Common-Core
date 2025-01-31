/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:16:03 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 21:16:03 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_prcs_tok(int *i, int *j, char **res, t_quote_state *state)
{
	*i = 0;
	*j = 0;
	*state = NO_QUOTE;
	*res = malloc(sizeof(char) * 4096);
	if (!res)
	{
		perror("malloc failed");
		return (0);
	}
	return (1);
}
/* static int	expansion_needed(char *token, t_quote_state state)
{
	if (state == NO_QUOTE || state == DOUBLE_QUOTE)
	{

	}
	if (ft_isalnum(token[1]) || token[1] == '_')
		return (1);
	return (0);
} */

char	*process_token(t_minishell *minish, char *token)
{
	int				i;
	int				j;
	t_quote_state	state;
	char			*result;

	if (!init_prcs_tok(&i, &j, &result, &state))
		return (NULL);
	while (token[i])
	{
		if (update_state(token[i], &state))
			i++;
		else if (token[i] == '$' && state != SINGLE_QUOTE)
		{
			append_expanded(minish, &result, &j, &token[i]);
			i += len_of_var(&token[i]);
		}
		else
			result[j++] = token[i++];
	}
	result[j] = '\0';
	return (result);
}

bool	update_state(char c, t_quote_state *state)
{
	if (c == '\'' && *state != DOUBLE_QUOTE)
	{
		if (*state == SINGLE_QUOTE)
			*state = NO_QUOTE;
		else
			*state = SINGLE_QUOTE;
		return (true);
	}
	else if (c == '"' && *state != SINGLE_QUOTE)
	{
		if (*state == DOUBLE_QUOTE)
			*state = NO_QUOTE;
		else
			*state = DOUBLE_QUOTE;
		return (true);
	}
	return (false);
}
