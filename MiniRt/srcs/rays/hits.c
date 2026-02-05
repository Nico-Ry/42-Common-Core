/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:08:38 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:08:43 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

void	sort_intersections(t_hit	**xs, int count)
{
	int		i;
	int		j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (xs[i]->t > xs[j]->t)
				ft_swap(&xs[i], &xs[j]);
			j++;
		}
		i++;
	}
}

t_hit	*find_visible_hit(t_hitlist **list)
{
	t_hit		*min;
	t_hitlist	*current;

	if (!list || !*list)
		return (NULL);
	current = *list;
	min = NULL;
	while (current)
	{
		if (current->hit && current->hit->t > 0
			&& (!min || current->hit->t < min->t))
			min = current->hit;
		current = current->next;
	}
	return (min);
}

double	find_hit(t_hit	**intersections, int count)
{
	double	hit;

	sort_intersections(intersections, count);
	hit = intersections[0]->t;
	return (hit);
}
