/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:52:54 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:53:36 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "minirt.h"
# include "pthread.h"

# define WALL_Z 5
# define WALL_SIZE 7
# define CANVAS_SIZE WIN_SIZE

typedef struct s_tuple	t_tuple;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr_ptr;
	int		pixel_bits;
	int		line_len;
	int		endian;
}	t_image;

//#############################################
//################# ENGINE ####################
//#############################################
// Struct representing the engine with the window and fractal properties
typedef struct s_engine
{
	void		*mlx;
	void		*window;
	t_image		image;
	int			offset_x;
	int			offset_y;
	float		zoom;
	int			mouse_pressed;
	int			last_mouse_x;
	int			last_mouse_y;
}	t_engine;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_progress
{
	int					lines_rendered;
	int					current_y;
	int					total_lines;
	pthread_mutex_t		mutex;
}	t_progress;

typedef struct s_render_thread
{
	t_camera		cam;
	t_world			*world;
	t_image			*image;
	int				start_y;
	int				end_y;
	t_progress		*progress;
}	t_render_thread;

typedef struct s_render_launch
{
	t_camera		cam;
	t_world			*world;
	t_image			*img;
	t_progress		*progress;
	int				thread_count;
}	t_render_launch;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_scale_info
{
	char	*dst_addr;
	int		dst_line_len;
	int		dst_bits;
	float	zoom;
}	t_scale_info;

typedef struct s_zoom_data
{
	float	zoom_factor;
	float	limit;
	int		is_zoom_in;
}	t_zoom_data;

//#############################################
//################# DRAW ######################
//#############################################
typedef struct s_projectile
{
	t_tuple		position;
	t_tuple		velocity;
}	t_projectile;

typedef struct s_environment
{
	t_tuple		gravity;
	t_tuple		wind;
}	t_environment;

//#############################################
//############## MAKE_ENGINE ##################
//#############################################
//clean_engine.c
void		error_message(t_engine *engine, char *text, int mode);
int			on_destroy_event(t_engine *engine);
void		cleanup(t_engine *engine);
void		display_help_message(t_engine *engine);

//handle_bar.c
void		draw_zoom_bar(t_engine *engine);

//handle_hooks.c
void		copy_pixel(t_engine *engine, t_point p, t_scale_info info);
void		scale_image(t_engine *engine, void *zoomed_img, float zoom);
void		redraw_image(t_engine *engine);
void		setup_hooks(t_engine *engine);

//handle_mouse.c
int			mouse_release(int button, int x, int y, t_engine *engine);
void		apply_zoom(t_engine *engine, int x, int y, t_zoom_data zoom);
int			mouse_press(int button, int x, int y, t_engine *engine);
int			mouse_move(int x, int y, t_engine *engine);
int			mouse_hook(int button, int x, int y, t_engine *engine);

//key_hook.c
int			key_hook(int keycode, t_engine *engine);

//make_engine.c
void		init_engine(t_engine *engine);

//main.c
int			ft_main_render(int run);
int			run_render_with(void (*render_func)(t_engine *));
int			ft_main_engine(int run);
//#############################################
//############## DRAW_TEST ####################
//#############################################
//draw_circle.c
void		draw_circle_scene(t_engine *engine);
int			draw_circle(int run);

//draw_clock.c
// void		draw_marker(t_image *img, int x, int y, int color, int marker_size);
void		draw_clock_scene(t_engine *engine);
int			draw_hour_markers(int run);

//draw_projectile.c
void		draw_trajectory_scene(t_engine *engine);
int			draw_trajectory(int run);

//draw_silhouette.c
void		draw_silhouette(t_engine *engine);

//draw_sphere.c
void		draw_sphere(t_engine *engine);

//draw_world_shadows.c
void		draw_world_with_shadows(t_engine *engine);

//draw_world.c
void		draw_world(t_engine *engine);

//#############################################
//################ RENDER #####################
//#############################################
//bonus_render.c
t_image		*render(t_camera cam, t_world *world, t_image *img);

//normal_render.c
t_image		*render(t_camera cam, t_world *world, t_image *img);

//render_threads.c
int			grab_next_block(t_render_thread *ctx, int *y_start,
				int *y_end, int block_size);
void		render_line(t_render_thread *ctx, int y);
void		*render_section(void *arg);
t_image		*render(t_camera cam, t_world *world, t_image *img);

//thread_utils.c
int			get_cpu_count(void);
int			auto_block_size(int image_height);
void		create_threads(pthread_t *threads, t_render_thread *args,
				t_render_launch *ctx);
void		join_threads(pthread_t *threads, int thread_count);

//#############################################
//################## UTILS ####################
//#############################################
//messages.c
void		help_text(t_engine *engine, int *y, char *text);
void		display_help_message(t_engine *engine);
void		malloc_err(char *func_name);
void		print_tuple(t_tuple tuple, char *name);
//ft_utils.c
void		put_pixel(t_image *img, int x, int y, int color);

//parse_color.c
t_colour	parse_color(char *str);

//parse_cyl.c
t_cylinder	*parse_cylinder(char **split_line);

//parse_plane.c
t_plane		*parse_plane(char **split_line);

//parse_utils.c
int			skip_spaces_and_sign(const char *str, int *sign);
double		ft_atof(const char *str);
void		free_split(char **split);
t_tuple		parse_tuple(char *str, int type);

//rodrigues.c
t_matrix	*build_skew_matrix(t_tuple v);
t_matrix	*rotation_matrix(t_tuple from, t_tuple to);

#endif
