/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:24:35 by nryser            #+#    #+#             */
/*   Updated: 2024/10/12 14:38:23 by ameechan         ###   ########.fr       */
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
