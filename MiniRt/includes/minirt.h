/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:17:46 by nryser            #+#    #+#             */
/*   Updated: 2026/02/05 16:17:46 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
// # include <sys/types.h>
// # include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "keys.h"

typedef struct s_colour		t_colour;
typedef struct s_material	t_material;
typedef struct s_phong		t_phong;
typedef struct t_cylinder	t_cyl;

//#############################################
//############ TUPLES & MATRICES ##############
//#############################################

typedef enum tuple_type
{
	VECTOR,
	POINT,
}	t_tpl;

typedef struct s_tuple
{
	t_tpl		w;
	double		x;
	double		y;
	double		z;
}	t_tuple;

typedef struct s_matrix
{
	int			rows;
	int			cols;
	int			is_tuple;
	int			is_identity;
	int			is_invertible;
	double		det;
	double		**values;
}	t_matrix;

//#############################################
//############## pattS #####################
//#############################################

typedef struct s_colour
{
	double	r;
	double	g;
	double	b;
}	t_colour;

typedef enum e_pattern_type
{
	PATTERN_STRIPE,
	PATTERN_GRADIENT,
	PATTERN_RING,
	PATTERN_CHECKERS,
	PATTERN_UV_STRIPE,
	PATTERN_UV_GRADIENT,
	PATTERN_UV_CHECKERS,
	PATTERN_SOLID
}	t_patt_type;

typedef struct s_patt
{
	t_patt_type		type;
	t_colour		a;
	t_colour		b;
	t_matrix		*transform;
	double			frequency;
	int				width;
	int				height;
	struct s_patt	*a_patt;
	struct s_patt	*b_patt;
}	t_patt;

typedef struct s_uv
{
	double	u;
	double	v;
}	t_uv;

//#############################################
//################ OBJECTS ####################
//#############################################
typedef enum e_obj_type
{
	SPHERE,
	CYLINDER,
	PLANE,
	CONE,
}	t_obj;

typedef struct s_material
{
	t_colour	c;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	t_patt		*patt;
}	t_material;

typedef struct s_object
{
	t_obj		type;
	t_matrix	*transf;
	t_material	m;
}	t_object;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	d;
}	t_quad;

typedef struct s_sphere
{
	t_object	base;
	t_tuple		centre;
	double		radius;
	int			id;
}	t_sphere;

typedef struct s_cylinder
{
	t_object	base;
	t_tuple		centre;
	double		radius;
	double		min;
	double		max;
	bool		closed;
}	t_cylinder;

typedef struct s_cone
{
	t_object	base;
	double		min;
	double		max;
	bool		closed;
}	t_cone;

/**
 * @brief Stores the two t-values resulting from a ray-cone intersection.
 *
 * When a ray intersects the side of a cone, it produces up to two
 * solutions (t0 and t1) from the quadratic formula. This struct holds
 * those values for later validation against the cone’s height limits.
 */
typedef struct s_cone_vals
{
	double	t0;
	double	t1;
}	t_cone_vals;

typedef struct s_plane
{
	t_object	base;
}	t_plane;

//#############################################
//########## RAYS & INTERSECTIONS #############
//#############################################

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}	t_ray;

typedef struct s_hit
{
	double	t;
	void	*obj;
	t_obj	type;
}	t_hit;

typedef struct s_intersection
{
	int		count;
	int		capacity;
	t_hit	**hits;
}	t_inters;

typedef struct s_hitlist
{
	t_hit				*hit;
	struct s_hitlist	*next;
}	t_hitlist;

//#############################################
//########## LIGHTS & REFLECTIONS #############
//#############################################
typedef struct s_ambient
{
	double		ratio;
	t_colour	colour;
}	t_ambient;

typedef struct s_light
{
	t_tuple		pos;
	t_colour	lum;
	double		brightness;
}	t_light;

typedef struct s_shading
{
	t_material	m;
	t_light		*l;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_phong		*ph;
	void		*obj;
}	t_shading;

typedef struct s_phong
{
	t_colour	effective_colour;
	t_colour	ambient;
	t_colour	diffuse;
	t_colour	specular;
	t_tuple		lightv;
	t_tuple		reflectv;
	double		light_dot_normal;
	double		reflect_dot_eye;
	double		factor;
}	t_phong;

typedef struct s_computations
{
	bool		inside;
	double		t;
	void		*obj;
	t_tuple		point;
	t_tuple		over_point;
	t_tuple		eyev;
	t_tuple		normalv;
}	t_computations;

//#############################################
//################# WORLD #####################
//#############################################

typedef struct s_world
{
	void		**objects;
	int			object_count;
	t_light		**lights;
	int			light_count;
	t_ambient	ambient;
}	t_world;

typedef struct s_camera
{
	double		hsize;
	double		vsize;
	double		fov;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_matrix	*transf;
	t_matrix	*inverse_transf;
}	t_camera;

//#############################################
//################# OTHER #####################
//#############################################

typedef struct s_cyl_vals
{
	double	t0;
	double	t1;
	double	temp;
}	t_cyl_vals;

typedef struct s_render_ctx
{
	t_world		*world;
	t_tuple		ray_origin;
	t_sphere	*sph;
	double		pixel_size;
	double		half;
}	t_render_ctx;

//#############################################
//################ MAIN #######################
//#############################################
//main.c
// int			ft_main_render(int run);
// int			run_render_with(void (*render_func)(t_engine *));
// int			ft_main_engine(int run);

//#############################################
//################ MATRICES ###################
//#############################################
//determinant.c
double			minor(t_matrix *matrix, int row, int col);
double			cofactor(t_matrix *matrix, int row, int col);
double			determinant_base_case(t_matrix *matrix);
double			determinant(t_matrix *matrix);

//matrix_create.c
t_matrix		*create_matrix(int rows, int cols, int is_tuple);
void			fill_matrix(t_matrix *matrix);
t_matrix		*submatrix(t_matrix *matrix, int remove_row, int remove_col);
void			fill_submatrix(t_matrix *matrix, t_matrix *sub,
					int ignore_row, int ignore_col);
t_matrix		*create_identity_matrix(int size);

//matrix_invert.c
t_matrix		*compute_cofactor_matrix(t_matrix *matrix);
void			scale_matrix(t_matrix *matrix, double scalar);
bool			invertable(t_matrix *matrix);
t_matrix		*invert_matrix(t_matrix *matrix);

//matrix_utils.c
int				equal_matrix(t_matrix *a, t_matrix *b);
void			compute_product_matrix(t_matrix *a,
					t_matrix *b, t_matrix *result);
t_matrix		*multiply_matrices(t_matrix *a, t_matrix *b);
t_matrix		*multiply_and_free(t_matrix *a, t_matrix *b);
t_matrix		*multiply_by_identity(t_matrix *input);
t_matrix		*transpose_matrix(t_matrix *input);

//#############################################
//##############PATTERNS#######################
//#############################################
//nested_patterns.c
t_patt			*solid_patt(t_colour c);
t_patt			*make_diagonal_stripe(t_colour a, t_colour b, double angle);

//patterns.c
t_tuple			transform_world_to_object(t_tuple w_point, t_matrix *inverse);
t_colour		patt_at_object(t_patt *patt, t_object *object,
					t_tuple world_point);
t_colour		patt_colour_at(t_patt *patt, t_tuple patt_point,
					t_object *obj);
t_colour		patt_colour_at_world(t_patt *patt, t_object *object,
					t_tuple world_point);
// t_colour	test_patt_at(t_patt *patt, t_tuple point);//TEST
// t_patt	test_patt(void);//test

//math_patterns.c
t_colour		stripe_at(t_patt *patt, t_tuple point, t_object *obj);
t_colour		gradient_at(t_patt *patt, t_tuple point);
t_colour		ring_at(t_patt *patt, t_tuple point, t_object *obj);
t_colour		checkers_at(t_patt *patt, t_tuple point, t_object *obj);

//type_patts.c
t_patt			stripe_patt(t_colour a, t_colour b);
t_patt			gradient_patt(t_colour a, t_colour b);
t_patt			ring_patt(t_colour a, t_colour b);
t_patt			checkers_patt(t_colour a, t_colour b);

//type_uv_patts.c
t_patt			uv_stripe_patt(t_colour a, t_colour b, int width, int height);
t_patt			uv_gradient_patt(t_colour a, t_colour b, int width, int height);
t_patt			uv_checkers_patt(t_colour a, t_colour b, int width, int height);
//uv_mapping.c
t_uv			uv_spherical(t_tuple point);
t_uv			uv_planar(t_tuple point);
t_uv			uv_cylindrical(t_tuple point);
t_colour		uv_patt_at(t_patt *patt, t_tuple point, t_object *obj);

//type_uv_patts.c
t_colour		uv_checkers_at(t_patt *patt, t_uv uv);
t_colour		uv_stripe_at(t_patt *patt, t_uv uv);
t_colour		uv_gradient_at(t_patt *patt, t_uv uv);

//
//#############################################
//##################RAYS#######################
//#############################################
//hits.c
void			ft_swap(t_hit **a, t_hit **b);
void			sort_intersections(t_hit	**xs, int count);
t_hit			*find_visible_hit(t_hitlist **list);
double			find_hit(t_hit	**intersections, int count);

//intersect_cone_caps.c
void			intersect_cone_caps(t_hitlist **xs, t_cone *cone, t_ray *ray);
bool			check_cone_cap(t_ray ray, double t, t_cone *c);
t_tuple			normal_at_cone(t_object *obj, t_tuple world_point);

//intersect_cone.c
void			intersect_cone(t_object *shape, t_ray *ray, t_hitlist **xs);

//intersect_cyl.c
void			intersect_cyl(t_cylinder *cyl, t_ray *ray, t_hitlist **xs);

//intersect_pl.c
void			intersect_pl(t_plane *pl, t_ray *ray, t_hitlist **xs);

//intersect.c
t_inters		*init_intersections(int initial_capacity);
void			intersect(void *obj, t_ray *ray, t_hitlist **xs);
t_hit			*intersection(double t, void *object);

//ray_sphere.c
double			discriminant_sph(t_ray *ray, t_tuple sph_to_ray);
void			add_hit(t_hitlist **xs, t_hit *hit);
void			intersect_sph(t_sphere *sphere, t_ray *ray, t_hitlist **xs);

//rays.c
/**
 * @brief creates a ray with an origin and direction
 * @param origin the starting point of the ray
 * @param direction the direction the ray is pointing
 * @return a pointer to the newly created ray
 */
t_ray			*ft_ray(t_tuple origin, t_tuple direction);
t_tuple			get_point(t_ray *ray, double t);

//transform.c
void			set_transf(void *obj, t_matrix *trans);
t_ray			*transform(t_ray *r, t_matrix *mtx);

//#############################################
//############### REFLECTION ##################
//#############################################
//ft_material.c
t_material		ft_material(void);

//ft_reflect.c
/**
 * @brief reflects a given vector around the normal provided
 */
t_tuple			ft_reflect(t_tuple in, t_tuple normal);
t_light			*ft_light(t_tuple position, t_colour lum, double brightness);

//ft_shading.c
t_colour		ft_shading(t_shading L, bool in_shadow);

//normal_at.c
t_tuple			ft_world_normal(t_matrix *inverse, t_tuple obj_normal);
t_tuple			ft_local_point(t_matrix *inverse, t_tuple world_point);
t_tuple			normal_at(void *obj, t_tuple world_p);
t_tuple			local_normal_at(void *shape, t_tuple world_p);

//pre_compute.c
t_computations	pre_compute(t_hit	*hit, t_ray *ray);
t_colour		color_at(t_world *world, t_ray *ray, bool ignore_shadows);
bool			is_shadowed(t_world *w, t_tuple point, t_light *light);
void			add_light_to_world(t_world *world, t_light *light);

//shade_hit.c
t_colour		shade_hit(t_world *w, t_computations comps,
					bool ignore_shadows);

//#############################################
//############### SCENE #######################
//#############################################
//world.c
t_world			*ft_world(void);
t_world			*default_world(void);
void			copy_hits(t_inters *dst, t_inters *src);
t_hitlist		**new_hitlist(void);
void			intersect_world(t_world *w, t_ray *r, t_hitlist **xs);

//objects.c
/**
 * @brief creates and returns a sphere with a unique ID
 * @param radius the radius of the sphere
 */
t_sphere		*ft_sphere(double radius);
t_plane			*ft_plane(void);
t_cylinder		*ft_cylinder(void);
t_cone			*ft_cone(void);

//#############################################
//############ TRANSFORMATIONS ################
//#############################################
//transformations.c
/**
 * @brief creates and returns a translation matrix
 */
t_matrix		*translate(double x, double y, double z);
t_matrix		*scale(double x, double y, double z);
t_matrix		*rotate_x(double rad);
t_matrix		*rotate_y(double rad);
t_matrix		*rotate_z(double rad);

//operations_matrix.c
t_matrix		*tuple_to_matrix(t_tuple tup);
t_tuple			matrix_to_tuple(t_matrix *matrix);
t_matrix		*add_matrices(t_matrix *a, t_matrix *b);
void			add_matrices_inplace(t_matrix *a, t_matrix *b);
t_matrix		*add_matrices_free_first(t_matrix *a, t_matrix *b);

//#############################################
//################# TUPLE #####################
//#############################################
//operations.c
/**
 * @brief adds coordinates of two tuples
 * @return a new tuple created from the addition of t1 & t2
 */
t_tuple			add_tuple(t_tuple t1, t_tuple t2);
t_tuple			diff_tuple(t_tuple t1, t_tuple t2);
t_tuple			mult_tuple(t_tuple vector, double t);
double			ft_sqr(double x);
double			magnitude(t_tuple v);

//product.c
/**
 * @brief Calculates the dot product of two vectors
 * @note a dot of 1 means vectors are identical,
 * while a dot of -1 means they point in opposite directions.
 */
double			dot(t_tuple a, t_tuple b);
t_tuple			cross(t_tuple a, t_tuple b);

//tuples.c
/**
 * @brief Fills a tuple with provided data
 */
t_tuple			ft_tuple(double x, double y, double z, t_tpl type);
t_tuple			new_tuple(void);
t_tuple			normalize(t_tuple v);

//tuple_utils.c
bool			is_point(t_tuple tuple);
bool			is_vector(t_tuple tuple);
bool			equal_tuple(t_tuple t1, t_tuple t2);
bool			ft_equal(double a, double b);
t_tuple			ft_negate(t_tuple tup);

//#############################################
//################# UTILS #####################
//#############################################
//colours.c
t_colour		ft_colour(double r, double g, double b);
t_colour		add_colours(t_colour	a, t_colour b);
t_colour		diff_colours(t_colour a, t_colour b);
t_colour		mult_colour(t_colour c, double num);
t_colour		blend_colours(t_colour c1, t_colour c2);

//colours2.c
int				convert_colour_to_int(t_colour col);
t_colour		clamp_colour(t_colour c);

//free_objs.c
void			free_material(t_material *m);
void			free_sphere(t_sphere *sphere);
void			free_plane(t_plane *plane);
void			free_cylinder(t_cylinder *cyl);
void			free_cone(t_cone *cone);

//free_utils.c
void			free_ray(t_ray *ray);
void			free_matrix(t_matrix *matrix);
void			free_patt(t_patt *patt);
void			free_hitlist(t_hitlist **hs);

//free_world.c
void			free_world(t_world *w);

//ft_utils.c
void			ft_swap(t_hit **a, t_hit **b);
void			print_progress_bar(int y, int total);

//#############################################
//################# VIEW ######################
//#############################################
//camera.c
/**
 * @brief creates a new camera, calculating
 * pixel_size, half_width and half_height
 * according to given arguments. Also converts and stores fov in radians.
 * @param hsize the horizontal size in pixels of the canvas.
 * @param vsize the vertical size in pixels of the canvas.
 * @param fov Field of view or angle that describes how much the camera can see.
 */
t_camera		ft_camera(double hsize, double vsize, double fov_degrees);

//ray_for_pixel.c
/**
 * @brief calculates the ray that goes through a pixel on the canvas
 * @param cam the camera object
 * @param px the x coordinate of the pixel
 * @param py the y coordinate of the pixel
 * @return a pointer to the ray object
 */
t_ray			*ray_for_pixel(t_camera cam, int px, int py);

//view_transform.c
t_matrix		*orientation_matrix(t_tuple forward, t_tuple up);
t_matrix		*view_transform(t_tuple from, t_tuple to, t_tuple up);

# ifndef M_PI
#  define M_PI 3.1415926535897932384626433
# endif
# define EPSILON 0.00001

// Define window and view parameters
# define WIN_SIZE 500
# define VIEW_CHANGE_SIZE 60
# define MIN_ITERATIONS 256
# define MAX_ITERATIONS 256
# define DEFAULT_COLOR 265

# define WIDTH 1920
# define HEIGHT 1080

// Define circle parameters
# define SCALE 25
# define FIXED_RADIUS 1
# define MINIMUM_RADIUS 0.5
# define RADIUS 200
# define MARKER_SIZE 15

// Colors (Hex format: 0xRRGGBB)
# define COLOR_X 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

// Define Terminal Colors
# define BOLD "\033[1m"
# define RES  "\033[0m"

// Regular colors
// Red
# define AKA  "\033[0;31m"
// Green
# define GR   "\033[0;32m"
// Yellow
# define YEL  "\033[0;33m"
// Blue (dim)
# define LILA "\033[0;34m"
// Cyan
# define CYAN "\033[0;36m"

// Bold colors
// Bold Red
# define R_B  "\033[1;31m"
// Bold Green
# define G_B  "\033[1;32m"
// Bold Blue
# define B_B  "\033[1;34m"
// Bold Cyan
# define C_B "\033[1;36m"

#endif
