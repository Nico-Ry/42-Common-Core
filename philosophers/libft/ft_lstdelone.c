/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:40:46 by nryser            #+#    #+#             */
/*   Updated: 2024/10/12 20:00:19 by ameechan         ###   ########.fr       */
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
