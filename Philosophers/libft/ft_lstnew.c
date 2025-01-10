/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:58:59 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 13:58:59 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_varlist	*ft_lstnew(void *content)
{
	t_varlist	*elem;

	elem = malloc(sizeof(t_varlist));
	if (!elem)
		return (NULL);
	elem->var = content;
	elem->next = NULL;
	return (elem);
}

/*
This function allocates memory for a new element of type t_list,
 setting its content to be the content parameter,
 and setting the next variable to NULL.
Then it returns the newly allocated / created element of the list.
*/
