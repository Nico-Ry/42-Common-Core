/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projectile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:27:50 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:27:50 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

// static int	setup_simulation(t_projectile **p, t_environment **e)
// {
// 	t_tuple	velocity;

// 	*p = malloc(sizeof(t_projectile));
// 	*e = malloc(sizeof(t_environment));
// 	if (!*p || !*e)
// 		return (0);
// 	(*p)->position = ft_tuple(1, 1, 0, POINT);
// 	velocity = ft_tuple(1, 2, 0, VECTOR);
// 	(*p)->velocity = mult_tuple(normalize(velocity), 4.7);
// 	(*e)->gravity = ft_tuple(0, -0.5, 0, VECTOR);
// 	(*e)->wind = ft_tuple(-0.01, 0, 0, VECTOR);
// 	return (1);
// }

// static t_projectile	*update_projectile(t_projectile *p, t_environment *e)
// {
// 	t_tuple	new_pos;
// 	t_tuple	new_vel;

// 	new_vel = add_tuple(p->velocity, add_tuple(e->gravity, e->wind));
// 	new_pos = add_tuple(p->position, p->velocity);
// 	if (new_pos.y < 0)
// 	{
// 		new_pos.y = 0;
// 		new_vel.y *= -0.8;
// 	}
// 	if (magnitude(new_vel) > WIN_SIZE)
// 		new_vel = mult_tuple(normalize(new_vel), 20);
// 	p->position = new_pos;
// 	p->velocity = new_vel;
// 	return (p);
// }

// static void	draw_trajectory_loop(t_image *img,
					// t_projectile *p, t_environment *e)
// {
// 	int	screen_x;
// 	int	screen_y;

// 	while (p->position.x < WIN_SIZE / SCALE)
// 	{
// 		screen_x = (int)(p->position.x * SCALE);
// 		screen_y = WIN_SIZE - (int)(p->position.y * SCALE);
// 		draw_marker(img, screen_x, screen_y, RED, MARKER_SIZE);
// 		p = update_projectile(p, e);
// 		if (screen_y <= 0 || screen_y >= WIN_SIZE)
// 			p->velocity.y *= -1;
// 	}
// }

// void	draw_trajectory_scene(t_engine *engine)
// {
// 	t_projectile	*p;
// 	t_environment	*e;

// 	if (!setup_simulation(&p, &e))
// 		return ;
// 	draw_trajectory_loop(&engine->image, p, e);
// 	free(p);
// 	free(e);
// }

// int	draw_trajectory(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	return (1);
// }
