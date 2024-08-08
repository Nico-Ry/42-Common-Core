/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:39:52 by nryser            #+#    #+#             */
/*   Updated: 2024/08/07 21:26:18 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdbool.h>
# include "libft.h"
# include "keys.h"
# include "mlx.h"

// Define fractal types
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

// Define fractal type strings
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
# define BURNING_SHIP_STR "burning_ship"

// Define window and view parameters
# define WIN_SIZE 500
# define VIEW_CHANGE_SIZE 60
# define MIN_ITERATIONS 256
# define MAX_ITERATIONS 256
# define DEFAULT_COLOR 265

# define SCALE 2
# define FIXED_RADIUS 1
# define MINIMUM_RADIUS 0.5

// Struct representing a pixel with x and y coordinates
typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

// Struct representing a complex number with real and imaginary parts
typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

// Struct representing an image with its properties and data pointer
typedef struct s_image
{
	void	*img_ptr;
	char	*addr_ptr;
	int		pixel_bits;
	int		line_len;
	int		endian;
}	t_image;

// Struct representing a fractal & properties
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

// Struct representing the engine with the window and fractal properties
typedef struct s_engine
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_fractal	fractal;
}	t_engine;

// Function declarations for fractal calculations
int	calc_mandelbrot(t_fractal *fract, t_complex *c);
int	calc_julia(t_fractal *fract, t_complex *c, int x, int y);
int	calc_burning_ship(t_fractal *fract, t_complex *c);

#endif  /* FRACTAL_H */
