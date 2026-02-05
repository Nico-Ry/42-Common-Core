/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:15:19 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:15:19 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_world	*ft_world(void)
{
	t_world	*w;

	w = malloc(sizeof(t_world));
	if (!w)
		return (NULL);
	w->objects = NULL;
	w->object_count = 0;
	w->lights = NULL;
	w->light_count = 0;
	w->ambient.ratio = 0.1;
	w->ambient.colour = ft_colour(1, 1, 1);
	return (w);
}

t_world	*default_world(void)
{
	t_world		*w;
	t_sphere	*s1;
	t_sphere	*s2;

	w = ft_world();
	add_light_to_world(w, ft_light(ft_tuple(-10, 10, -10, POINT),
			ft_colour(1, 1, 1), 1.0));
	s1 = ft_sphere(1);
	s1->base.m.c = ft_colour(0.8, 1, 0.6);
	s1->base.m.diffuse = 0.7;
	s1->base.m.specular = 0.2;
	s2 = ft_sphere(1);
	set_transf(s2, scale(0.5, 0.5, 0.5));
	w->objects = malloc(sizeof(t_sphere *) * 2);
	if (!w->objects)
		return (NULL);
	w->objects[0] = s1;
	w->objects[1] = s2;
	w->object_count = 2;
	return (w);
}

void	copy_hits(t_inters *dst, t_inters *src)
{
	t_hit	*hit;
	int		j;

	j = 0;
	while (j < src->count)
	{
		hit = src->hits[j];
		dst->hits[dst->count] = hit;
		dst->count++;
		j++;
	}
}

t_hitlist	**new_hitlist(void)
{
	t_hitlist	**new;

	new = malloc(sizeof(t_hitlist *));
	if (!new)
		malloc_err("new_hitlist");
	*new = NULL;
	return (new);
}

void	intersect_world(t_world *w, t_ray *r, t_hitlist **xs)
{
	int			i;

	if (!xs)
		return ;
	i = 0;
	while (i < w->object_count)
	{
		intersect(w->objects[i], r, xs);
		i++;
	}
}
