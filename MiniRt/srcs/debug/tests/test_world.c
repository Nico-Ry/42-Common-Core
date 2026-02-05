/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:31:38 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:34:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	world_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int			i;
// 	t_world		*w;

// 	i = 1;
// 	// TEST 1: Creating an empty world
// 	print_test_banner("Creating an empty world");
// 	print_test_number(&i);
// 	w = ft_world();
// 	if (!w)
// 	{
// 		printf(AKA"❌ Failed to allocate world\n"RES);
// 		return (1);
// 	}
// 	if (w->objects == NULL && w->object_count == 0)
// 		printf(GR"✔ No objects in the world\n"RES);
// 	else
// 		printf(AKA"❌ World has unexpected objects\n"RES);
// 	if (w->lights == NULL)
// 		printf(GR"✔ No light in the world\n"RES);
// 	else
// 		printf(AKA"❌ World has a light source when it shouldn't\n"RES);
// 	free_world(w);
// 	return (0);
// }

// int	default_world_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int			i = 2;
// 	t_world		*w;
// 	t_light		*expected_light;
// 	t_sphere	*s1;
// 	t_sphere	*s2;
// 	t_matrix	*expected_scale;

// 	print_test_banner("Default world contains two spheres and a light");
// 	print_test_number(&i);
// 	w = default_world();
// 	// Check the light
// 	expected_light = ft_light(ft_tuple(-10, 10, -10, POINT),
						// ft_colour(1, 1, 1), 1.0);
// 	printf("Expected Light Position: (%.1f, %.1f, %.1f)\n",
// 		expected_light->pos.x, expected_light->pos.y, expected_light->pos.z);
// 	printf("Actual Light Position:   (%.1f, %.1f, %.1f)\n",
// 		w->lights[0]->pos.x, w->lights[0]->pos.y, w->lights[0]->pos.z);
// 	printf("Expected Light Color: (%.1f, %.1f, %.1f)\n",
// 		expected_light->lum.r, expected_light->lum.g, expected_light->lum.b);
// 	printf("Actual Light Color:   (%.1f, %.1f, %.1f)\n",
// 		w->lights[0]->lum.r, w->lights[0]->lum.g, w->lights[0]->lum.b);
// 	if (equal_tuple(w->lights[0]->pos, expected_light->pos) &&
// 		ft_equal(w->lights[0]->lum.r, expected_light->lum.r) &&
// 		ft_equal(w->lights[0]->lum.g, expected_light->lum.g) &&
// 		ft_equal(w->lights[0]->lum.b, expected_light->lum.b))
// 		printf(G_B"✔ Light is correctly initialized\n"RES);
// 	else
// 		return (printf(AKA"❌ Light does not match expected values\n"RES));
// 	free(expected_light);
// 	// Check object count
// 	printf("World object count: %d\n", w->object_count);
// 	if (w->object_count == 2)
// 		printf(G_B"✔ World has 2 objects\n"RES);
// 	else
// 		return (printf(AKA"❌ World object count is incorrect\n"RES));
// 	// Check first sphere's material
// 	s1 = w->objects[0];
// 	printf("First sphere material color: (%.1f, %.1f, %.1f)\n",
// 		s1->base.m.c.r, s1->base.m.c.g, s1->base.m.c.b);
// 	printf("Diffuse: %.1f | Specular: %.1f\n",
// 		s1->base.m.diffuse, s1->base.m.specular);
// 	if (ft_equal(s1->base.m.c.r, 0.8) &&
// 		ft_equal(s1->base.m.c.g, 1.0) &&
// 		ft_equal(s1->base.m.c.b, 0.6) &&
// 		ft_equal(s1->base.m.diffuse, 0.7) &&
// 		ft_equal(s1->base.m.specular, 0.2))
// 		printf(G_B"✔ First sphere material matches expected values\n"RES);
// 	else
// 		return (printf(
		// AKA"❌ First sphere material does not match expected values\n"RES));
// 	// Check second sphere’s scale (0.5, 0.5, 0.5)
// 	s2 = w->objects[1];
// 	expected_scale = scale(0.5, 0.5, 0.5);
// 	printf("Second sphere transform:\n");
// 	print_matrix(s2->base.transf);
// 	printf("Expected transform:\n");
// 	print_matrix(expected_scale);
// 	if (equal_matrix(s2->base.transf, expected_scale))
// 		printf(G_B"✔ Second sphere transform is scaled correctly\n"RES);
// 	else
// 		return (printf(AKA"❌ Second sphere transform is incorrect\n"RES));
// 	free_matrix(expected_scale);
// 	free_world(w);
// 	return (0);
// }

// int	intersect_world_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int			i = 3;
// 	t_world		*w = default_world();
// 	t_ray		*r = ft_ray(ft_tuple(0, 0, -5, POINT),
					// ft_tuple(0, 0, 1, VECTOR));
// 	t_hitlist	**xs = new_hitlist();
// 	double		expected[] = {5.5, 4.5, 6.0, 4.0};
// 	int			count;

// 	print_test_banner("Intersecting a world with a ray");
// 	print_test_number(&i);
// 	intersect_world(w, r, xs);
// 	print_hitlist(xs);
// 	// Check count
// 	count = count_hits(xs);
// 	printf("Intersections count: %d\n", count);
// 	if (count == 4)
// 		printf(G_B"✔ xs.count == 4\n"RES);
// 	else
// 		printf(AKA"❌ xs.count != 4\n"RES);

// 	for (int j = 0; j < count; j++)
// 	{
// 		printf("xs[%d].t = %.1f (expected %.1f)\n", j,
			// (*xs)->hit->t, expected[j]);
// 		if (ft_equal((*xs)->hit->t, expected[j]))
// 			printf(GR"✔ t%d is correct\n"RES, j);
// 		else
// 			printf(AKA"❌ t%d is incorrect\n"RES, j);
// 		(*xs) = (*xs)->next;
// 	}
// 	free_hitlist(xs);
// 	free_ray(r);
// 	free_world(w);
// 	return (0);
// }

// int	ft_pre_compute_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int				i = 1;
// 	t_computations	comps;
// 	t_sphere		*shape;
// 	t_hit			*hit;
// 	t_ray			*r;

// //TEST 1
// 	//print banners
// 	print_test_banner("Precomputing the state of an intersection");
// 	print_test_number(&i);
// 	//initiate variables
// 	r = ft_ray(ft_tuple(0,0,-5,POINT), ft_tuple(0,0,1,VECTOR));
// 	shape = ft_sphere(1);
// 	hit = intersection(4, shape);
// 	//run test
// 	comps = pre_compute(hit, r);
// 	//check & print output
// 	//t value
// 	printf(B_B"comps.t:   %.0f\n"RES"", comps.t);
// 	printf(G_B"expected:  %.0f\n"RES"", hit->t);
// 	if (ft_equal(comps.t, hit->t))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	printf("________________________________________________\n");

// 	//object
// 	printf(B_B"comps.object:   %p\n"RES"", comps.obj);
// 	printf(G_B"expected: \t%p\n"RES"", hit->obj);
// 	if (comps.obj == hit->obj)
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	printf("________________________________________________\n");

// 	//point
// 	printf(B_B"comps.point: (%.0f,%.0f,%.0f,%d)\n"RES"",
		// comps.point.x, comps.point.y, comps.point.z, comps.point.w);
// 	printf(G_B"expected:    (0,0,-1,1)\n"RES"");
// 	if (equal_tuple(comps.point, ft_tuple(0,0,-1,POINT)))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));
// 	printf("________________________________________________\n");

// 	//eyev
// 	printf(B_B"comps.eyev: (%.0f,%.0f,%.0f,%d)\n"RES"",
		// comps.eyev.x, comps.eyev.y, comps.eyev.z, comps.eyev.w);
// 	printf(G_B"expected:   (0,0,-1,0)\n"RES"");
// 	if (equal_tuple(comps.eyev, ft_tuple(0,0,-1,VECTOR)))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));
// 	printf("________________________________________________\n");

// 	//normalv
// 	printf(B_B"comps.normalv: (%.0f,%.0f,%.0f,%d)\n"RES"",
		// comps.normalv.x, comps.normalv.y, comps.normalv.z, comps.normalv.w);
// 	printf(G_B"expected:      (0,0,-1,0)\n"RES"");
// 	if (equal_tuple(comps.normalv, ft_tuple(0,0,-1,VECTOR)))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));
// 	printf("________________________________________________\n");

// //TEST 2
// 	//print banners
// 	print_test_banner("Hit when intersection occurs on the outside");
// 	print_test_number(&i);
// 	//inside
// 	if (comps.inside == false)
// 		printf(GR"✔ comps.inside properly set to FALSE\n"RES);
// 	else
// 		return(
	// printf(AKA"❌ comps.inside is set to TRUE when it should be FALSE\n"RES));

// //TEST 3
// 	//print banners
// 	print_test_banner("Hit when intersection occurs on the inside");
// 	print_test_number(&i);
// 	//redefine variables
// 	r->origin = ft_tuple(0,0,0,POINT);
// 	r->direction = ft_tuple(0,0,1,VECTOR);
// 	hit = intersection(1, shape);
// 	//run test
// 	comps = pre_compute(hit, r);
// 	//check & print output
// 	//point
// 	printf(B_B"comps.point: (%.0f,%.0f,%.0f,%d)\n"RES"",
	// comps.point.x, comps.point.y, comps.point.z, comps.point.w);
// 	printf(G_B"expected:    (0,0,1,1)\n"RES"");
// 	if (equal_tuple(comps.point, ft_tuple(0,0,1,POINT)))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));
// 	printf("________________________________________________\n");

// 	//eyev
// 	printf(B_B"comps.eyev: (%.0f,%.0f,%.0f,%d)\n"RES"",
	// comps.eyev.x, comps.eyev.y, comps.eyev.z, comps.eyev.w);
// 	printf(G_B"expected:   (0,0,-1,0)\n"RES"");
// 	if (equal_tuple(comps.eyev, ft_tuple(0,0,-1,VECTOR)))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));
// 	printf("________________________________________________\n");

// 	//inside
// 	if (comps.inside == true)
// 		printf(GR"✔ intersection properly occurs on the inside\n"RES);
// 	else
// 		return(
	// printf(AKA"❌ intersection incorrectly occurs on the outside\n"RES));

// 	//normalv
// 	printf(B_B"comps.normalv: (%.0f,%.0f,%.0f,%d)\n"RES"",
	// comps.normalv.x, comps.normalv.y, comps.normalv.z, comps.normalv.w);
// 	printf(G_B"expected:      (0,0,-1,0)\n"RES"");
// 	if (equal_tuple(comps.normalv, ft_tuple(0,0,-1,VECTOR)))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));
// 	printf("________________________________________________\n");
// 	return (0);
// }

// int	shade_hit_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	int i = 1;
// 	t_world	*w;
// 	t_ray	*r;
// 	t_hit	*hit;
// 	t_computations comps;
// 	t_colour col;

// 	// TEST 1 — shading an intersection from the outside
// 	print_test_banner("Shading an intersection (outside)");
// 	print_test_number(&i);
// 	// setup
// 	w = default_world();
// 	r = ft_ray(ft_tuple(0, 0, -5, POINT), ft_tuple(0, 0, 1, VECTOR));
// 	hit = intersection(4.0, w->objects[0]);
// 	comps = pre_compute(hit, r);
// 	col = shade_hit(w, comps, false);
// 	// color check
// 	printf(B_B"computed colour: (%.5f, %.5f, %.5f)\n"RES"",
				// col.r, col.g, col.b);
// 	printf(G_B"expected:        (0.38066, 0.47583, 0.28550)\n"RES"");
// 	if (ft_equal(col.r, 0.38066) && ft_equal(col.g, 0.47583) &&
	// ft_equal(col.b, 0.2855))
// 		printf(GR"✔ color matches expected value\n"RES);
// 	else
// 		return (printf(AKA"❌ color does not match expected value\n"RES));
// 	printf("________________________________________________\n");
// 	free_ray(r);
// 	free(hit);
// 	free_world(w);
// 	// TEST 2 — shading an intersection from the inside
// 	print_test_banner("Shading an intersection (inside)");
// 	print_test_number(&i);
// 	w = default_world();
// 	add_light_to_world(w, ft_light(ft_tuple(-10, 10, -10, POINT),
							// ft_colour(1, 1, 1), 1.0));
// 	r = ft_ray(ft_tuple(0, 0, 0, POINT), ft_tuple(0, 0, 1, VECTOR));
// 	hit = intersection(0.5, w->objects[1]);
// 	comps = pre_compute(hit, r);
// 	col = shade_hit(w, comps, false);
// 	// color check
// 	printf(B_B"computed colour: (%.5f, %.5f, %.5f)\n"RES"",
			// col.r, col.g, col.b);
// 	printf(G_B"expected:        (0.90498, 0.90498, 0.90498)\n"RES"");
// 	if (ft_equal(col.r, 0.90498) && ft_equal(col.g, 0.90498) &&
			// ft_equal(col.b, 0.90498))
// 		printf(GR"✔ color matches expected value\n"RES);
// 	else
// 		return (printf(AKA"❌ color does not match expected value\n"RES));
// 	printf("________________________________________________\n");
// 	free_ray(r);
// 	free(hit);
// 	free_world(w);
// 	return (0);
// }

// int	color_at_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int i = 1;
// 	t_world *w;
// 	t_ray *r;
// 	t_colour col;

// 	// TEST 1 — Ray misses everything
// 	print_test_banner(" The color when a ray misses all objects");
// 	print_test_number(&i);
// 	w = default_world();
// 	r = ft_ray(ft_tuple(0, 0, -5, POINT), ft_tuple(0, 1, 0, VECTOR));
// 	col = color_at(w, r, false);

// 	printf(B_B"returned color: (%.0f, %.0f, %.0f)\n"RES"", col.r, col.g, col.b);
// 	printf(G_B"expected:       (0, 0, 0)\n"RES"");
// 	if (ft_equal(col.r, 0) && ft_equal(col.g, 0) && ft_equal(col.b, 0))
// 		printf(GR"✔ background color is correct (black)\n"RES);
// 	else
// 		return (printf(AKA"❌ background color is incorrect\n"RES));
// 	printf("________________________________________________\n");
// 	free_ray(r);
// 	free_world(w);

// 	// TEST 2 — Ray hits object
// 	print_test_banner("The color when a ray hits an object");
// 	print_test_number(&i);
// 	w = default_world();
// 	r = ft_ray(ft_tuple(0, 0, -5, POINT), ft_tuple(0, 0, 1, VECTOR));
// 	col = color_at(w, r, false);

// 	printf(B_B"returned color: (%.5f, %.5f, %.5f)\n"RES"", col.r, col.g, col.b);
// 	printf(G_B"expected:       (0.38066, 0.47583, 0.28550)\n"RES"");
// 	if (ft_equal(col.r, 0.38066) && ft_equal(col.g, 0.47583) &&
				// ft_equal(col.b, 0.2855))
// 		printf(GR"✔ color matches expected surface color\n"RES);
// 	else
// 		return (printf(AKA"❌ color does not match expected\n"RES));
// 	printf("________________________________________________\n");
// 	free_ray(r);
// 	free_world(w);

// 	// TEST 3 — The color with an intersection behind the ray
// 	print_test_banner("The color with an intersection behind the ray");
// 	print_test_number(&i);
// 	w = default_world();
// 	t_object *outer = w->objects[0];
// 	t_object *inner = w->objects[1];
// 	outer->m.ambient = 1;
// 	inner->m.ambient = 1;
// 	inner->m.c = ft_colour(1, 1, 1);
// 	outer->m.c = ft_colour(0, 0, 0);
// 	// Ray starts between the two objects, heading toward the camera
// 	r = ft_ray(ft_tuple(0, 0, 0.75, POINT), ft_tuple(0, 0, -1, VECTOR));
// 	col = color_at(w, r, false);
// 	printf(B_B"returned color: (%.2f, %.2f, %.2f)\n"RES"", col.r, col.g, col.b);
// 	printf(G_B"expected:       (1.00, 1.00, 1.00)\n"RES"");
// 	if (ft_equal(col.r, 1.0) && ft_equal(col.g, 1.0) && ft_equal(col.b, 1.0))
// 		printf(GR"✔ correct: inner sphere is shaded\n"RES);
// 	else
// 		return (printf(AKA"❌ incorrect: wrong sphere is shaded\n"RES));
// 	printf("________________________________________________\n");
// 	free_ray(r);
// 	free_world(w);
// 	return (0);
// }
