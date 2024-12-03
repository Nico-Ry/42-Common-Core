/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:29:09 by nryser            #+#    #+#             */
/*   Updated: 2024/10/12 14:42:31 by ameechan         ###   ########.fr       */
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
