/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:38:25 by nryser            #+#    #+#             */
/*   Updated: 2024/10/12 20:00:33 by ameechan         ###   ########.fr       */
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
