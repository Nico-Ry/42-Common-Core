/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:24:35 by nryser            #+#    #+#             */
/*   Updated: 2023/11/15 15:25:45 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
	tmp = tmp->next;
	return (tmp);
}

/* instead of looping directly over the element, we check if
there is a next element in the list, if not, that means we
reached the end and we have to return the current pointer
if we looped over the element directly like for ft_lstsize
we would be returning NULL every time
*/