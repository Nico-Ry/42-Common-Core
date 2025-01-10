/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:58:38 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 13:58:38 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_varlist *lst, void (*del)(void *))
{
	del(lst->var);
	free(lst);
}

/*This function takes a list element as parameter
and deletes its content as well as free the
allocated memory using the del function passed as parameter too.*/
