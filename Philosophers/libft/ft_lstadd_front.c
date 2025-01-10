/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:58:19 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 13:58:22 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_varlist **alst, t_varlist *new)
{
	new->next = *alst;
	*alst = new;
}

/*This function lets us add a new element to the
front of an existing list.
We receive the new element and the existing list.*/
