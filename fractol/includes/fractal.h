/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:39:52 by nryser            #+#    #+#             */
/*   Updated: 2024/08/06 10:34:05 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdbool.h>
# include "libft.h"
# include "keys.h"
# include "mlx.h"

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
# define BURNING_SHIP_STR "burning_ship"

# define WIN_SIZE 800
# define VIEW_CHANGE_SIZE 60
# define MIN_ITERATIONS 256
# define MAX_ITERATIONS 256
# define DEFAULT_COLOR 265

# define SCALE 2
# define FIXED_RADIUS 1
# define MINIMUM_RADIUS 0.5

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr_ptr;
	int		pixel_bits;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractal
{
	int			type;
	double		zoom;
	u_int32_t	color;
	double		mouse_x;
	double		mouse_y;
	double		offset_x;
	double		offset_y;
	int			iterations;
	bool		is_julia_lock;
}	t_fractal;

typedef struct s_engine
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_fractal	fractal;
}	t_engine;

int	calc_mandelbrot(t_fractal *fract, t_complex *c);
int	calc_julia(t_fractal *fract, t_complex *c, int x, int y);
int	calc_burning_ship(t_fractal *fract, t_complex *c);

#endif  /* FRACTAL_H */
