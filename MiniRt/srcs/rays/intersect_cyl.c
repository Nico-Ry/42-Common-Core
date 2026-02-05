/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cyl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:09:08 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:09:27 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_swap_t_cyl(t_cyl_vals *data)
{
	data->temp = data->t0;
	data->t0 = data->t1;
	data->t1 = data->temp;
}

static void	validate(t_hitlist **xs, t_cylinder *cyl, t_ray *ray, t_cyl_vals d)
{
	double	y0;
	double	y1;
	t_hit	*hit_0;
	t_hit	*hit_1;

	if (d.t0 > d.t1)
		ft_swap_t_cyl(&d);
	y0 = ray->origin.y + d.t0 * ray->direction.y;
	if (cyl->min < y0 && y0 < cyl->max)
	{
		hit_0 = intersection(d.t0, cyl);
		add_hit(xs, hit_0);
	}
	y1 = ray->origin.y + d.t1 * ray->direction.y;
	if (cyl->min < y1 && y1 < cyl->max)
	{
		hit_1 = intersection(d.t1, cyl);
		add_hit(xs, hit_1);
	}
}

static int	check_cap(t_ray *r, double t)
{
	double	x;
	double	z;
	double	res;

	x = r->origin.x + t * r->direction.x;
	z = r->origin.z + t * r->direction.z;
	res = ft_sqr(x) + ft_sqr(z);
	if (res <= 1)
		return (1);
	return (0);
}

static void	intersect_caps(t_cylinder *cyl, t_ray *ray, t_hitlist **xs)
{
	double	t;

	if (!cyl->closed || ft_equal(ray->direction.y, 0))
		return ;
	t = (cyl->min - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, t))
		add_hit(xs, intersection(t, cyl));
	t = (cyl->max - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, t))
		add_hit(xs, intersection(t, cyl));
}

void	intersect_cyl(t_cylinder *cyl, t_ray *ray, t_hitlist **xs)
{
	double		disc;
	double		a;
	double		b;
	double		c;
	t_cyl_vals	data;

	a = ft_sqr(ray->direction.x) + ft_sqr(ray->direction.z);
	if (ft_equal(a, 0))
	{
		intersect_caps(cyl, ray, xs);
		return ;
	}
	b = (2 * ray->origin.x * ray->direction.x)
		+ (2 * ray->origin.z * ray->direction.z);
	c = ft_sqr(ray->origin.x) + ft_sqr(ray->origin.z) - 1;
	disc = ft_sqr(b) - 4 * a * c;
	if (disc < 0)
		return ;
	data.t0 = (-b - sqrt(disc)) / (2 * a);
	data.t1 = (-b + sqrt(disc)) / (2 * a);
	validate(xs, cyl, ray, data);
	intersect_caps(cyl, ray, xs);
}
