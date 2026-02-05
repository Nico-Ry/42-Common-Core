/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:21:09 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:21:23 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

void	free_ray(t_ray *ray)
{
	if (!ray)
		return ;
	free(ray);
}

void	free_matrix(t_matrix *matrix)
{
	int	i;

	if (!matrix)
		return ;
	if (matrix->values)
	{
		i = 0;
		while (i < matrix->rows)
		{
			free(matrix->values[i]);
			i++;
		}
		free(matrix->values);
	}
	free(matrix);
}

void	free_patt(t_patt *patt)
{
	if (!patt)
		return ;
	if (patt->transform)
		free_matrix(patt->transform);
	if (patt->a_patt)
		free_patt(patt->a_patt);
	if (patt->b_patt)
		free_patt(patt->b_patt);
	free(patt);
}

void	free_hitlist(t_hitlist **hs)
{
	t_hitlist	*current;
	t_hitlist	*next;

	if (!hs)
		return ;
	current = *hs;
	while (current)
	{
		next = current->next;
		free(current->hit);
		free(current);
		current = next;
	}
	free(hs);
}
