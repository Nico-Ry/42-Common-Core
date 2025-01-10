/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:39:29 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 14:39:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_varlist **alst, t_varlist *new)
{
	t_varlist	*last;

	if (!alst)
		return ;
	last = ft_lstlast(*alst);
	if (!last)
		*alst = new;
	else
		last->next = new;
}

/*This function lets us add a new element to the end of an existing list.*/
