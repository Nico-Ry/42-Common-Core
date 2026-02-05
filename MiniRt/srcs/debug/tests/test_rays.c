/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:50:42 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:54:18 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	position_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int	i = 1;
// 	t_ray	*r = ft_ray(ft_tuple(2, 3, 4, POINT),
// ft_tuple(1, 0, 0, VECTOR));
// 	t_tuple	res;
// 	t_tuple	expected;

// 	print_test_banner("Computing a point from a distance");
// //TEST 1
// 	//print banners
// 	print_test_banner("get_point(r, 0)");
// 	print_test_number(&i);
// 	//initiate variables
// 	expected = ft_tuple(2, 3, 4, POINT);
// 	//run test
// 	res = get_point(r, 0);
// 	//print output
// 	printf(B_B"result: (%.0f, %.0f, %.0f, %d)\n"RES"",
	// res.x, res.y, res.z, res.w);
// 	printf(G_B"expected: (%.0f, %.0f, %.0f, %d)\n"RES"",
	// expected.x, expected.y, expected.z, expected.w);
// 	//check output
// 	if (equal_tuple(res, expected))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return (printf(AKA"❌ tuples don't match\n"RES));
// //TEST 2
// 	//print banners
// 	print_test_banner("get_point(r, 1)");
// 	print_test_number(&i);
// 	//initiate variables
// 	expected = ft_tuple(3, 3, 4, POINT);
// 	//run test
// 	res = get_point(r, 1);
// 	//print output
// 	printf(B_B"result: (%.0f, %.0f, %.0f, %d)\n"RES"",
	// res.x, res.y, res.z, res.w);
// 	printf(G_B"expected: (%.0f, %.0f, %.0f, %d)\n"RES"",
	// expected.x, expected.y, expected.z, expected.w);
// 	//check output
// 	if (equal_tuple(res, expected))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return (printf(AKA"❌ tuples don't match\n"RES));
// //TEST 3
// 	//print banners
// 	print_test_banner("get_point(r, -1)");
// 	print_test_number(&i);
// 	//initiate variables
// 	expected = ft_tuple(1, 3, 4, POINT);
// 	//run test
// 	res = get_point(r, -1);
// 	//print output
// 	printf(B_B"result: (%.0f, %.0f, %.0f, %d)\n"RES"",
	// res.x, res.y, res.z, res.w);
// 	printf(G_B"expected: (%.0f, %.0f, %.0f, %d)\n"RES"",
	// expected.x, expected.y, expected.z, expected.w);
// 	//check output
// 	if (equal_tuple(res, expected))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return (printf(AKA"❌ tuples don't match\n"RES));
// //TEST 4
// 	//print banners
// 	print_test_banner("get_point(r, 2.5)");
// 	print_test_number(&i);
// 	//initiate variables
// 	expected = ft_tuple(4.5, 3, 4, POINT);
// 	//run test
// 	res = get_point(r, 2.5);
// 	//print output
// 	printf(B_B"result: (%.0f, %.0f, %.0f, %d)\n"RES"",
	// res.x, res.y, res.z, res.w);
// 	printf(G_B"expected: (%.0f, %.0f, %.0f, %d)\n"RES"",
	// expected.x, expected.y, expected.z, expected.w);
// 	//check output
// 	if (equal_tuple(res, expected))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return (printf(AKA"❌ tuples don't match\n"RES));
// 	return (0);
// }
// /**
//  * @brief tests that each sphere is properly given a unique ID
//  * @param run 1 to run, 0 to skip
//  * @param num number of spheres to create
//  */
// int	sph_unique_id(int run, int num)
// {
// 	if (run == 0)
// 		return (0);
// 	int i = 0;
// 	int	test = 1;

// //TEST 1
// 	print_test_banner("SPHERE UNIQUE ID");
// 	print_test_number(&test);
// 	while (i < num)
// 	{
// 		t_sphere	*s0 = ft_sphere(1);
// 		printf("sphere ID: \t"YEL"%d"RES"\n", s0->id);
// 		i++;
// 	}
// 	printf(R_B"Attention: Manual check required!\n"RES"");
// 	printf(B_B"All spheres should have unique IDs\n"RES);
// 	return (0);
// }

// //#################################################################//
// //########################## P59 - P62 #############################//
// //#################################################################//

// int	count_hits(t_hitlist **xs)
// {
// 	t_hitlist	*current;
// 	int			i = 0;

// 	if (!xs || !*xs)
// 		return (0);
// 	current = *xs;
// 	while (current)
// 	{
// 		i++;
// 		current = current->next;
// 	}
// 	return (i);
// }

// int	sph_ray_intersect(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int		i = 1;
// 	t_ray	*r = ft_ray(ft_tuple(-5, 0, 0, POINT), ft_tuple(1, 0, 0, VECTOR));
// 	t_sphere	*s = ft_sphere(1);
// 	double		d;
// 	t_hitlist	**xs = new_hitlist();
// 	double		t0;
// 	double		t1;
// 	int			count = 0;

// 	print_test_banner("Sphere Intersections");
// //TEST 1
// 	//print banners
// 	print_sub_header("two intersections", &i);
// 	//run test
// 	d = discriminant_sph(r, diff_tuple(r->origin, s->centre));
// 	intersect(s, r, xs);
// 	t0 = (*xs)->hit->t;
// 	t1 = (*xs)->next->hit->t;
// 	//print output
// 	printf(YEL"Discriminant: %.1f\n"RES, d);
// 	printf(B_B"t1:\t      %.1f\t"G_B"expected: 4.0\n"RES, t1);
// 	printf(B_B"t2:\t      %.1f\t"G_B"expected: 6.0\n"RES, t0);
// 	//check output
// 	count = count_hits(xs);
// 	if (count == 2)
// 		printf(GR"✔ xs.count == 2\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 2\n"RES));
// 	if (ft_equal(t1, 4.0) && ft_equal(t0, 6.0))
// 		printf(GR"✔ t1 and t2 are correct\n"RES);
// 	else
// 		return(printf(AKA"❌ t1 and t2 are incorrect\n"RES));
// 	free_hitlist(xs);
// 	free(r);
// //TEST 2
// 	//print banners
// 	print_test_banner("tangent");
// 	print_test_number(&i);
// 	//redefine ray
// 	r = ft_ray(ft_tuple(-5, 1, 0, POINT), ft_tuple(1, 0, 0, VECTOR));
// 	//run test
// 	d = discriminant_sph(r, diff_tuple(r->origin, s->centre));
// 	intersect(s, r, xs);
// 	t0 = (*xs)->hit->t;
// 	t1 = (*xs)->next->hit->t;
// 	//print output
// 	printf(YEL"Discriminant: %.1f\n"RES, d);
// 	printf(B_B"t1:\t      %.1f\t"G_B"expected: 5.0\n"RES, t1);
// 	printf(B_B"t2:\t      %.1f\t"G_B"expected: 5.0\n"RES, t0);
// 	//check output
// 	count = count_hits(xs);
// 	if (count == 2)
// 		printf(GR"✔ xs.count == 2\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 2\n"RES));
// 	if (ft_equal(t1, 5.0) && ft_equal(t0, 5.0))
// 		printf(GR"✔ t1 and t2 are correct\n"RES);
// 	else
// 		return(printf(AKA"❌ t1 and t2 are incorrect\n"RES));
// 	free_hitlist(xs);
// 	free(r);
// //TEST 3
// 	//print banners
// 	print_test_banner("no intersection");
// 	print_test_number(&i);
// 	//redifine ray
// 	r = ft_ray(ft_tuple(-5, 2, 0, POINT), ft_tuple(1, 0, 0, VECTOR));
// 	d = discriminant_sph(r, diff_tuple(r->origin, s->centre));
// 	printf(G_B"Discriminant: "RES"%.2f\n", d);
// 	//call function
// 	intersect(s, r, xs);
// 	//print output
// 	count = count_hits(xs);
// 	if (count == 0)
// 	{
// 		printf(GR"✔ NO INTERSECTIONS DETECTED!\n"RES"");
// 		printf(GR"xs.count: %d\n"RES, count);
// 	}
// 	else
// 		return(printf(AKA"❌xs.count != 0\txs.count: %d\n"RES, count));
// 	//free resources
// 	free_hitlist(xs);
// 	free(r);
// //TEST 4
// 	//print banners
// 	print_test_banner("ray originates inside sphere");
// 	print_test_number(&i);
// 	//redefine ray
// 	r = ft_ray(ft_tuple(0, 0, 0, POINT), ft_tuple(1, 0, 0, VECTOR));
// 	//run test
// 	d = discriminant_sph(r, diff_tuple(r->origin, s->centre));
// 	intersect(s, r, xs);
// 	t0 = (*xs)->hit->t;
// 	t1 = (*xs)->next->hit->t;
// 	//print output
// 	printf(YEL"Discriminant: %.1f\n"RES, d);
// 	printf(B_B"t1:\t      %.1f\t"G_B"expected: -1.0\n"RES, t1);
// 	printf(B_B"t2:\t      %.1f\t"G_B"expected:  1.0\n"RES, t0);
// 	//check output
// 	count = count_hits(xs);
// 	if (count == 2)
// 		printf(GR"✔ xs.count == 2\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 2\n"RES));
// 	if (ft_equal(t1, -1.0) && ft_equal(t0, 1.0))
// 		printf(GR"✔ t1 and t2 are correct\n"RES);
// 	else
// 		return(printf(AKA"❌ t1 and t2 are incorrect\n"RES));
// 	free_hitlist(xs);
// 	free(r);
// //TEST 5
// 	//print banners
// 	print_test_banner("sphere is behind ray");
// 	print_test_number(&i);
// 	//redefine ray
// 	r = ft_ray(ft_tuple(5, 0, 0, POINT), ft_tuple(1, 0, 0, VECTOR));
// 	//run test
// 	d = discriminant_sph(r, diff_tuple(r->origin, s->centre));
// 	intersect(s, r, xs);
// 	t0 = (*xs)->hit->t;
// 	t1 = (*xs)->next->hit->t;
// 	//print output
// 	printf(YEL"Discriminant: %.1f\n"RES, d);
// 	printf(B_B"t1:\t      %.1f\t"G_B"expected: -6.0\n"RES, t1);
// 	printf(B_B"t2:\t      %.1f\t"G_B"expected: -4.0\n"RES, t0);
// 	//check output
// 	count = count_hits(xs);
// 	if (count == 2)
// 		printf(GR"✔ xs.count == 2\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 2\n"RES));
// 	if (ft_equal(t1, -6.0) && ft_equal(t0, -4.0))
// 		printf(GR"✔ t1 and t2 are correct\n"RES);
// 	else
// 		return(printf(AKA"❌ t1 and t2 are incorrect\n"RES));
// 	free_hitlist(xs);
// 	free(r);
// 	return (0);
// }

// //#################################################################//
// //########################## P63 - P66 #############################//
// //#################################################################//

// int	intersection_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int			i = 1;
// 	int			count = 0;
// 	t_sphere	*s = ft_sphere(1);
// 	t_ray		*r = ft_ray(ft_tuple(-5, 0, 0, POINT),
	// ft_tuple(1, 0, 0, VECTOR));
// 	t_hit		*i1 = NULL;
// 	t_hit		*i2 = NULL;
// 	t_hit		*i3 = NULL;
// 	t_hit		*i4 = NULL;
// 	t_hit		*hit;

// //TEST 1
// 	//print banners
// 	print_test_banner("Intersection encapsulates t and object");
// 	print_test_number(&i);
// 	//call function
// 	i1 = intersection(3.5, s);
// 	//print ouput
// 	printf(BOLD"%15s "GR"%14f\n"RES, "i.t:", i1->t);
// 	printf(BOLD"%15s "GR"%20p"RES"\n", "i.object:", i1->obj);
// 	printf(BOLD"%15s "LILA"%20p\n"RES"", "Sphere:", s);
// 	//check output
// 	if (ft_equal(i1->t, 3.5))
// 		printf(GR"✔ i.t == 3.5\n"RES);
// 	else
// 		return(printf(AKA"❌ i.t != 3.5\n"RES));
// 	if (i1->obj == s)
// 		printf(GR"✔ i.object == Sphere\n"RES);
// 	else
// 		return(printf(AKA"❌ i.object != Sphere\n"RES));
// 	//free variables
// 	free(i1);
// //TEST 2
// 	//print banners
// 	print_test_banner("`intersect` sets the object on the intersection");
// 	print_test_number(&i);
// 	//redefine variables
// 	t_sphere	*s2 = ft_sphere(1);
// 	t_hitlist	**xs = new_hitlist();
// 	//check output
// 	intersect(s2, r, xs);
// 	count = count_hits(xs);
// 	printf(BOLD"%15s "GR"%7d\n"RES, "xs.count:", count);
// 	printf(BOLD"%15s "GR"%20p\n"RES, "xs[0].object:", (*xs)->next->hit->obj);
// 	printf(BOLD"%15s "GR"%20p\n"RES, "xs[1].object:", (*xs)->hit->obj);
// 	printf(BOLD"%15s "LILA"%20p\n"RES, "Sphere:", s2);
// 	if (count == 2)
// 		printf(GR"✔ xs.count == 2\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 2\n"RES));
// 	if ((*xs)->next->hit->obj == s2)
// 		printf(GR"✔ xs[0].object == Sphere\n"RES);
// 	else
// 		return(printf(AKA"❌ xs[0].object != Sphere\n"RES));
// 	if ((*xs)->hit->obj == s2)
// 		printf(GR"✔ xs[1].object == Sphere\n"RES);
// 	else
// 		return(printf(AKA"❌ xs[1].object != Sphere\n"RES));
// 	//free variables
// 	free_hitlist(xs);
// 	//TEST 3
// 	print_test_banner("hit when all inters have positive `t`");
// 	print_test_number(&i);
// 	printf(BOLD"_________________________________\n\n"RES);
// 	i1 = intersection(1, s);
// 	i2 = intersection(2, s);

// 	add_hit(xs, i2);
// 	add_hit(xs, i1);
// 	hit = find_visible_hit(xs);
// 	printf("hit_list:\n\t%f\n\t%f\n", (*xs)->hit->t, (*xs)->next->hit->t);
// 	if (hit)
// 		printf(G_B"%6s "GR"%7.1f\n"RES, "hit:", hit->t);
// 	else
// 		printf(AKA"❌ no visible hit found\n"RES);
// 	printf(R_B"Attention: Manual check required!\n"RES"");
// 	printf(B_B"hit should be 1.0\n"RES);
// 	free_hitlist(xs);

// 	//TEST 4
// 	print_test_banner("hit when some inters have nagative `t`");
// 	print_test_number(&i);
// 	printf(BOLD"_________________________________\n\n"RES);
// 	i1 = intersection(-1, s);
// 	i2 = intersection(1, s);
// 	add_hit(xs, i1);
// 	add_hit(xs, i2);
// 	hit = find_visible_hit(xs);
// 	printf("hit_list:\n\t%f\n\t%f\n", (*xs)->hit->t, (*xs)->next->hit->t);
// 	if (hit)
// 		printf(G_B"%6s "GR"%7.1f\n"RES, "hit:", hit->t);
// 	else
// 		printf(AKA"❌ no visible hit found\n"RES);
// 	printf(R_B"Attention: Manual check required!\n"RES"");
// 	printf(B_B"hit should be 1.0\n"RES);
// 	free_hitlist(xs);

// 	//TEST 5
// 	print_test_banner("hit when all inters have nagative `t`");
// 	print_test_number(&i);
// 	printf(BOLD"_________________________________\n\n"RES);
// 	i1 = intersection(-2, s);
// 	i2 = intersection(-1, s);
// 	add_hit(xs, i1);
// 	add_hit(xs, i2);
// 	hit = find_visible_hit(xs);
// 	printf("hit_list:\n\t%f\n\t%f\n", (*xs)->hit->t, (*xs)->next->hit->t);
// 	if (hit)
// 		printf(G_B"%6s "GR"%7.1f\n"RES, "hit:", hit->t);
// 	else
// 		printf(GR"✔ no hit found (correct)\n"RES);
// 	printf(R_B"Attention: Manual check required!\n"RES"");
// 	printf(B_B"hit should be -999 (indicates no hit)\n"RES);
// 	free_hitlist(xs);

// 	//TEST 6
// 	print_test_banner("hit when unsorted array of inters");
// 	print_test_number(&i);
// 	printf(BOLD"_________________________________\n\n"RES);
// 	i1 = intersection(5, s);
// 	i2 = intersection(7, s);
// 	i3 = intersection(-3, s);
// 	i4 = intersection(2, s);
// 	add_hit(xs, i1);
// 	add_hit(xs, i2);
// 	add_hit(xs, i3);
// 	add_hit(xs, i4);
// 	print_hitlist(xs);
// 	hit = find_visible_hit(xs);
// 	if (hit)
// 		printf(G_B"%6s "GR"%7.1f\n"RES, "hit:", hit->t);
// 	else
// 		printf(AKA"❌ no visible hit found\n"RES);
// 	printf(R_B"Attention: Manual check required!\n"RES"");
// 	printf(B_B"hit should be 2.0\n"RES);
// 	free_hitlist(xs);

// 	return (0);
// }

// //#################################################################//
// //########################## P69 - Pxx #############################//
// //#################################################################//

// int	ray_transform_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	t_ray		*r = ft_ray(ft_tuple(1, 2, 3, POINT),
// 				ft_tuple(0, 1, 0, VECTOR));
// 	t_ray		*transformed_ray = NULL;
// 	t_matrix	*transf = translate(3, 4, 5);
// 	int			i = 1;

// //TEST 1
// 	//print banners
// 	print_test_banner("Translating a ray");
// 	print_test_number(&i);
// 	//initiate variables
// 	t_tuple	expected_origin = ft_tuple(4, 6, 8, POINT);
// 	t_tuple	expected_direction = ft_tuple(0, 1, 0, VECTOR);
// 	//call function
// 	transformed_ray = transform(r, transf);
// 	//print output
// 	printf(B_B"origin:    (%.0f, %.0f, %.0f, %d) \t "G_B
	// "expected: (4, 6, 8, 1)\n"RES"", transformed_ray->origin.x,
	// transformed_ray->origin.y, transformed_ray->origin.z,
	// transformed_ray->origin.w);
// 	printf(B_B"direction: (%.0f, %.0f, %.0f, %d) \t "G_B
	// "expected: (0, 1, 0, 0)\n"RES"", transformed_ray->direction.x,
	// transformed_ray->direction.y,
	// transformed_ray->direction.z, transformed_ray->direction.w);
// 	//check output
// 	if (equal_tuple(transformed_ray->origin, expected_origin))
// 		printf(GR"✔ origin is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ origin is incorrect\n"RES));
// 	if (equal_tuple(transformed_ray->direction, expected_direction))
// 		printf(GR"✔ direction is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ direction is incorrect\n"RES));
// 	//free variables
// 	free_ray(transformed_ray);
// 	free_matrix(transf);

// //TEST 2
// 	//print banners
// 	print_test_banner("Scaling a ray");
// 	print_test_number(&i);
// 	//redefine variables
// 	transf = scale(2, 3, 4);
// 	expected_origin = ft_tuple(2, 6, 12, POINT);
// 	expected_direction = ft_tuple(0, 3, 0, VECTOR);
// 	//call function
// 	transformed_ray = transform(r, transf);
// 	//print output
// 	printf(B_B"origin:(%.0f, %.0f, %.0f, %d)\t "G_B
	// "expected: (2, 6, 12, 1)\n"RES"", transformed_ray->origin.x,
	// transformed_ray->origin.y, transformed_ray->origin.z,
	// transformed_ray->origin.w);
// 	printf(B_B"direction: (%.0f, %.0f, %.0f, %d) \t "G_B
	// "expected: (0, 3, 0, 0)\n"RES"", transformed_ray->direction.x,
	// transformed_ray->direction.y, transformed_ray->direction.z,
	// transformed_ray->direction.w);
// 	//check output
// 	if (equal_tuple(transformed_ray->origin, expected_origin))
// 		printf(GR"✔ origin is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ origin is incorrect\n"RES));
// 	if (equal_tuple(transformed_ray->direction, expected_direction))
// 		printf(GR"✔ direction is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ direction is incorrect\n"RES));
// 	//free variables
// 	free_ray(transformed_ray);
// 	free_matrix(transf);
// 	return (0);
// }

// int	ray_transform_test2(int run)
// {
// 	if (run == 0)
// 		return (0);
// //initiate variables
// 	int			i = 1;
// 	int			count = 0;
// 	t_sphere	*s;
// 	t_matrix	*t;
// 	t_ray		*r;
// 	t_hitlist	**xs = new_hitlist();
// 	t_matrix	*identity = create_identity_matrix(4);

// //TEST 1
// 	print_test_banner("Sphere Default `transf`");
// 	print_test_number(&i);
// 	//run test
// 	s = ft_sphere(1);
// 	//print output
// 	printf(LILA"s->transf:\n"RES);
// 	print_matrix(s->base.transf);
// 	printf(G_B"expected:\n"RES);
// 	print_matrix(identity);
// 	//check output
// 	if (equal_matrix(s->base.transf, identity))
// 		printf(GR"✔ transf is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ transf is incorrect\n"RES));
// 	//free resources
// 	free_hitlist(xs);
// //TEST 2
// 	print_test_banner("Changing a sphere's transf (translation)");
// 	print_test_number(&i);
// 	//define variables
// 	t = translate(2, 3, 4);
// 	identity->values[0][3] = 2;
// 	identity->values[1][3] = 3;
// 	identity->values[2][3] = 4;
// 	//print input
// 	printf(LILA"s->transf BEFORE:\n"RES);
// 	print_matrix(s->base.transf);
// 	printf("\n");
// 	//run test
// 	set_transf(s, t);
// 	//print output
// 	printf(LILA"s->transf AFTER:\n"RES);
// 	print_matrix(s->base.transf);
// 	printf(G_B"expected:\n"RES);
// 	print_matrix(identity);
// 	//check output
// 	if (equal_matrix(s->base.transf, identity))
// 		printf(GR"✔ transf is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ transf is incorrect\n"RES));
// 	//free resources
// 	free_hitlist(xs);
// //TEST 3
// 	print_test_banner("Intersecting a scaled sphere with a ray");
// 	print_test_number(&i);
// 	//define variables
// 	free(s);
// 	s = ft_sphere(1);
// 	r = ft_ray(ft_tuple(0, 0, -5, POINT), ft_tuple(0, 0, 1, VECTOR));
// 	t = scale(2, 2 ,2);
// 	//run tests
// 	set_transf(s, t);
// 	intersect(s, r, xs);
// 	//print output
// 	printf(LILA"xs.count: "RES"%8d \t"G_B"expected: 2\n", count_hits(xs));
// 	printf(LILA"t1: "RES"%16.1f \t"G_B"expected: 3.0\n", (*xs)->next->hit->t);
// 	printf(LILA"t2: "RES"%16.1f \t"G_B"expected: 7.0\n", (*xs)->hit->t);
// 	//check output
// 	count = count_hits(xs);
// 	if (count == 2)
// 	printf(GR"✔ xs.count == 2\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 2\n"RES));
// 	if (ft_equal((*xs)->next->hit->t, 3.0))
// 		printf(GR"✔ t1 is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ t1 is incorrect\n"RES));
// 	if (ft_equal((*xs)->hit->t, 7.0))
// 		printf(GR"✔ t2 is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ t2 is incorrect\n"RES));
// 	//free resources
// 	free_hitlist(xs);

// //TEST 4
// 	print_test_banner("Intersecting a translated sphere with a ray");
// 	print_test_number(&i);
// 	//define variables
// 	free(s);
// 	s = ft_sphere(1);
// 	r = ft_ray(ft_tuple(0, 0, -5, POINT), ft_tuple(0, 0, 1, VECTOR));
// 	t = translate(5, 0 ,0);
// 	//run tests
// 	set_transf(s, t);
// 	intersect(s, r, xs);
// 	//print output
// 	printf(LILA"xs.count: "RES"%8d \t"G_B"expected: 0\n", count_hits(xs));
// 	//check output
// 	if (count_hits(xs) == 0)
// 	{
// 		printf(GR"✔ NO INTERSECTIONS DETECTED!\n"RES"");
// 		printf(GR"✔ xs.count == 0\n"RES);
// 	}
// 	else
// 		return(printf(AKA"❌ xs.count != 0\n"RES));
// 	//free resources
// 	free_hitlist(xs);
// 	return (0);
// }
