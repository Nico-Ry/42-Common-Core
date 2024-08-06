/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:43:31 by nryser            #+#    #+#             */
/*   Updated: 2024/08/06 09:44:24 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fractal.h"

void	set_pixel_color(t_engine *engine, int x, int y, int color);
void	change_color(int key, t_engine *engine);
void	change_view(int key, t_engine *engine);
int		calc_fractal(t_fractal *fract, t_complex *c, int x, int y);
void	draw_fractal(t_engine *engine);

#endif  /* RENDER_H */
