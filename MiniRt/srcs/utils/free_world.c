/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:16:24 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:17:37 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

static void	free_world_objects(t_world *w)
{
	int			i;
	t_object	*obj;

	i = 0;
	while (i < w->object_count)
	{
		obj = (t_object *)w->objects[i];
		if (obj->type == SPHERE)
			free_sphere((t_sphere *)obj);
		else if (obj->type == PLANE)
			free_plane((t_plane *)obj);
		else if (obj->type == CYLINDER)
			free_cylinder((t_cylinder *)obj);
		else if (obj->type == CONE)
			free_cone((t_cone *)obj);
		i++;
	}
	free(w->objects);
}

static void	free_world_lights(t_world *w)
{
	int	i;

	i = 0;
	while (i < w->light_count)
	{
		if (w->lights[i])
			free(w->lights[i]);
		i++;
	}
	free(w->lights);
}

void	free_world(t_world *w)
{
	if (!w)
		return ;
	free_world_objects(w);
	free_world_lights(w);
	free(w);
}
