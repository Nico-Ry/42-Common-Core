/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:51:04 by ameechan          #+#    #+#             */
/*   Updated: 2025/01/31 20:19:27 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*seek_var_inlist(t_varlist *var_list, char *var)
{
	t_varlist	*current;
	char		*res;

	res = NULL;
	if (!var_list)
		return (NULL);
	current = var_list;
	while (current)
	{
		if (ft_strcmp(current->var->vname, var) == 0 && current->var->vvalue)
		{
			res = ft_strdup(current->var->vvalue);
			return (res);
		}
		current = current->next;
	}
	if (res)
		return (res);
	return (NULL);
}

char	*expand_token(t_minishell *minish, char *var)
{
	char		*res;

	res = NULL;
	res = seek_var_inlist(minish->env_lst, var);
	if (res)
		return (res);
	res = seek_var_inlist(minish->local_vars, var);
	if (res)
		return (res);
	return (NULL);
}

void	append_expanded(t_minishell *minish, char **res, int *j, char *token)
{
	char	*expanded;
	char	*var;
	int		len;

	len = len_of_var(token);
	var = grab_dollar(token, len);
	if (!var)
		return ;
	if (len == 1 && token[1] == 0)
		expanded = ft_strdup(var);
	else if (len == 2 && token[1] == '?')
		expanded = ft_itoa(minish->last_exit_status);
	else
		expanded = expand_token(minish, var + 1);
	if (expanded)
	{
		ft_strcpy(&(*res)[*j], expanded);
		*j += ft_strlen(expanded);
		free(expanded);
	}
	free(var);
}

char	*grab_dollar(char *token, int len)
{
	int		i;
	char	*var;

	i = 0;
	var = NULL;
	if (len == 1 && token[1] != 0)
		return (NULL);
	var = malloc(sizeof(char) * len + 1);
	if (!var)
		return (NULL);
	while (i < len)
	{
		var[i] = token[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

int	len_of_var(char *token)
{
	int	len;

	len = 1;
	if (token[1] == '?')
		return (2);
	while (token[len] && (ft_isalnum(token[len]) || token[len] == '_'))
		len++;
	return (len);
}
