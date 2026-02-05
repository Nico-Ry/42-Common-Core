/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:41:48 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 23:41:48 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_varlist	*ft_lstlast(t_varlist *lst)
{
	t_varlist	*tmp;

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
