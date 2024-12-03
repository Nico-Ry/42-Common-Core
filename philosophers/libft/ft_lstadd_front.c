/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:05:59 by nryser            #+#    #+#             */
/*   Updated: 2024/10/12 14:37:54 by ameechan         ###   ########.fr       */
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
