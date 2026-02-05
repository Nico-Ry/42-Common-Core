/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cylinders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:40:27 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:41:12 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tests.h"

// static int	check_cyl_intersect_result(t_hitlist **xs,
					// int count, double t0, double t1)
// {
// 	if (count_hits(xs) == count)
// 		printf(GR"✔ ray intersects cylinder\n"RES);
// 	else
// 		return (printf(AKA"❌ ray does not intersect cylinder\n"RES));
// 	if (ft_equal((*xs)->next->hit->t, t0))
// 		printf(GR"✔ xs[0]->t is correct\n"RES);
// 	else
// 		return (printf(AKA"❌ xs[0]->t is incorrect\n"RES));
// 	if (ft_equal((*xs)->hit->t, t1))
// 		printf(GR"✔ xs[1]->t is correct\n\n"RES);
// 	else
// 		return (printf(AKA"❌ xs[1]->t is incorrect\n"RES));
// 	return (0);
// }

// int	test_intersect_cylinder(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	t_cylinder	*cyl;
// 	t_ray		*ray;
// 	t_tuple		direction;
// 	t_tuple		origin;
// 	t_hitlist	**xs = new_hitlist();
// 	int			i = 1;
// 	int			count;
// //TEST 1
// 	//print banners
// 	print_test_banner("Rays miss the cylinder");
// 	print_sub_header("ray -> origin (1,0,0) direction (0,1,0)", &i);
// 	//initialise variables
// 	cyl = ft_cylinder();
// 	origin = ft_tuple(1, 0, 0, VECTOR);
// 	direction = ft_tuple(0, 1, 0, VECTOR);
// 	ray = ft_ray(origin, direction);
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\n"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	//check result
// 	if (count == 0)
// 		printf(GR"✔ ray does not intersect cylinder\n\n"RES);
// 	else
// 		return (printf(AKA"❌ ray intersects cylinder\n"RES));
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);

// //TEST 2
// 	//print banners
// 	print_sub_header("ray -> origin (0,0,0) direction (0,1,0)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0, 0, 0, VECTOR);
// 	direction = ft_tuple(0, 1, 0, VECTOR);
// 	ray = ft_ray(origin, direction);
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\n"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	//check result
// 	if (count == 0)
// 		printf(GR"✔ ray does not intersect cylinder\n\n"RES);
// 	else
// 		return (printf(AKA"❌ ray intersects cylinder\n"RES));
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);

// //TEST 3
// 	//print banners
// 	print_sub_header("ray -> origin (0,0,-5) direction (1,1,1)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0, 0, -5, VECTOR);
// 	direction = normalize(ft_tuple(1, 1, 1, VECTOR));
// 	ray = ft_ray(origin, direction);
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\n"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	//check result
// 	if (count == 0)
// 		printf(GR"✔ ray does not intersect cylinder\n\n"RES);
// 	else
// 		return (printf(AKA"❌ ray intersects cylinder\n"RES));
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);

// //TEST 4
// 	//print banners
// 	print_test_banner("Rays intersect the cylinder");
// 	print_sub_header("ray -> origin (1,0,-5) direction (0,0,1)", &i);
// 	//redefine variables
// 	origin = ft_tuple(1, 0, -5, VECTOR);
// 	direction = normalize(ft_tuple(0, 0, 1, VECTOR));
// 	ray = ft_ray(origin, direction);
// 	double t0 = 5;
// 	double t1 = 5;
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\t"RES, count);
// 	printf(G_B"expected: 2\n"RES);
// 	printf(B_B"xs[0]->t: %.0f\t"RES, (*xs)->next->hit->t);
// 	printf(G_B"expected: %.0f\n"RES, t0);
// 	printf(B_B"xs[1]->t: %.0f\t"RES, (*xs)->hit->t);
// 	printf(G_B"expected: %.0f\n"RES, t1);
// 	//check result
// 	if (check_cyl_intersect_result(xs, 2, t0, t1))
// 		return (-1);
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);

// //TEST 5
// 	//print banners
// 	print_sub_header("ray -> origin (0,0,-5) direction (0,0,1)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0, 0, -5, VECTOR);
// 	direction = normalize(ft_tuple(0, 0, 1, VECTOR));
// 	ray = ft_ray(origin, direction);
// 	t0 = 4;
// 	t1 = 6;
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\t"RES, count);
// 	printf(G_B"expected: 2\n"RES);
// 	printf(B_B"xs[0]->t: %.0f\t"RES, (*xs)->next->hit->t);
// 	printf(G_B"expected: %.0f\n"RES, t0);
// 	printf(B_B"xs[1]->t: %.0f\t"RES, (*xs)->hit->t);
// 	printf(G_B"expected: %.0f\n"RES, t1);
// 	//check result
// 	if (check_cyl_intersect_result(xs, 2, t0, t1))
// 		return (-1);
// 	free_hitlist(xs);
// //TEST 6
// 	//print banners
// 	print_sub_header("ray -> origin (0.5,0,-5) direction (0.1,1,1)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0.5, 0, -5, VECTOR);
// 	direction = normalize(ft_tuple(0.1, 1, 1, VECTOR));
// 	ray = ft_ray(origin, direction);
// 	t0 = 6.80798;
// 	t1 = 7.08872;
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\t\t"RES, count);
// 	printf(G_B"expected: 2\n"RES);
// 	printf(B_B"xs[0]->t: %.5f\t"RES, (*xs)->next->hit->t);
// 	printf(G_B"expected: %.5f\n"RES, t0);
// 	printf(B_B"xs[1]->t: %.5f\t"RES, (*xs)->hit->t);
// 	printf(G_B"expected: %.5f\n"RES, t1);
// 	//check result
// 	if (check_cyl_intersect_result(xs, 2, t0, t1))
// 		return (-1);
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);
// 	return (0);
// }

// int	test_normal_at_cylinder(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	t_cylinder	*cyl;
// 	t_tuple		p;
// 	t_tuple		n;
// 	t_tuple		expected_normal;
// 	int			i = 1;

// //TEST 1
// 	//print banners
// 	print_test_banner("Normal at cylinder");
// 	print_sub_header("point -> (1,0,0)", &i);
// 	//initialise variables
// 	cyl = ft_cylinder();
// 	p = ft_tuple(1, 0, 0, POINT);
// 	expected_normal = ft_tuple(1, 0, 0, VECTOR);
// 	//run test
// 	n = local_normal_at(cyl, p);
// 	//print output
// 	print_normal(n, expected_normal, CYLINDER);
// 	//check result
// 	if (equal_tuple(n, expected_normal))
// 		printf(GR"✔ normal is correct\n\n"RES);
// 	else
// 		return (printf(AKA"❌ normal is incorrect\n"RES));

// //TEST 2
// 	//print banners
// 	print_sub_header("point -> (0,5,-1)", &i);
// 	//redefine variables
// 	p = ft_tuple(0, 5, -1, POINT);
// 	expected_normal = ft_tuple(0, 0, -1, VECTOR);
// 	//run test
// 	n = local_normal_at(cyl, p);
// 	//print output
// 	print_normal(n, expected_normal, CYLINDER);
// 	//check result
// 	if (equal_tuple(n, expected_normal))
// 		printf(GR"✔ normal is correct\n\n"RES);
// 	else
// 		return (printf(AKA"❌ normal is incorrect\n"RES));

// //TEST 3
// 	//print banners
// 	print_sub_header("point -> (0,-2,1)", &i);
// 	//redefine variables
// 	p = ft_tuple(0, -2, 1, POINT);
// 	expected_normal = ft_tuple(0, 0, 1, VECTOR);
// 	//run test
// 	n = local_normal_at(cyl, p);
// 	//print output
// 	print_normal(n, expected_normal, CYLINDER);
// 	//check result
// 	if (equal_tuple(n, expected_normal))
// 		printf(GR"✔ normal is correct\n\n"RES);
// 	else
// 		return (printf(AKA"❌ normal is incorrect\n"RES));

// //TEST 4
// 	//print banners
// 	print_sub_header("point -> (-1,1,0)", &i);
// 	//redefine variables
// 	p = ft_tuple(-1, 1, 0, POINT);
// 	expected_normal = ft_tuple(-1, 0, 0, VECTOR);
// 	//run test
// 	n = local_normal_at(cyl, p);
// 	//print output
// 	print_normal(n, expected_normal, CYLINDER);
// 	//check result
// 	if (equal_tuple(n, expected_normal))
// 		printf(GR"✔ normal is correct\n\n"RES);
// 	else
// 		return (printf(AKA"❌ normal is incorrect\n"RES));
// 	return (0);
// }

// static int	check_truncated_result(bool intersect,
					// int expected, int xs_count)
// {
// 	if (intersect == false)
// 	{

// 		if (xs_count == expected)
// 			printf(GR"✔ ray does not intersect truncated cylinder\n\n"RES);
// 		else
// 			return (printf(AKA"❌ ray intersects truncated cylinder\n"RES));
// 	}
// 	else
// 	{
// 		if (xs_count == expected)
// 			printf(GR"✔ ray intersects truncated cylinder\n\n"RES);
// 		else
// 			return (
	// printf(AKA"❌ ray does not intersect truncated cylinder\n"RES));
// 	}
// 	return (0);
// }

// int	test_truncate_cylinder(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	//define variables
// 	t_cylinder	*cyl;
// 	t_ray		*ray;
// 	t_tuple		origin;
// 	t_tuple		direction;
// 	t_hitlist	**xs = new_hitlist();
// 	int			i = 1;

// //TEST 1
// 	//print banners
// 	print_test_banner("Truncating cylinders");
// 	print_sub_header("default cylinder", &i);
// 	//initialise variables
// 	cyl = ft_cylinder();
// 	//print output
// 	printf(B_B"cylinder max: %.0f\t"RES, cyl->max);
// 	printf(G_B"expected: inf\n"RES);
// 	printf(B_B"cylinder min: %.0f\t"RES, cyl->min);
// 	printf(G_B"expected: -inf\n"RES);
// 	//check result
// 	if (cyl->min == -INFINITY && cyl->max == INFINITY)
// 		printf(GR"✔ cylinder is not truncated\n\n"RES);
// 	else
// 		return (printf(AKA"❌ cylinder is truncated\n"RES));

// //TEST 2
// 	//print banners
// 	print_sub_header("cylinder max = 2, min = 1", &i);
// 	//redefine variables
// 	cyl->min = 1;
// 	cyl->max = 2;
// 	//print output
// 	printf(B_B"cylinder max: %.0f\t"RES, cyl->max);
// 	printf(G_B"expected: 2\n"RES);
// 	printf(B_B"cylinder min: %.0f\t"RES, cyl->min);
// 	printf(G_B"expected: 1\n"RES);
// 	//check result
// 	if (cyl->min == 1 && cyl->max == 2)
// 		printf(GR"✔ cylinder is truncated\n\n"RES);
// 	else
// 		return (printf(AKA"❌ cylinder is not truncated\n"RES));

// //TEST 3
// 	//print banners
// 	print_sub_header("ray -> origin (0, 1.5, 0) direction (0.1, 1, 0)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0, 1.5, 0, VECTOR);
// 	direction = normalize(ft_tuple(0.1, 1, 0, VECTOR));
// 	ray = ft_ray(origin, direction);
// 	int		count = 0;
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\t"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	//check result
// 	if (check_truncated_result(false, count, count))
// 		return (-1);
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);

// //TEST 4
// 	//print banners
// 	print_sub_header("ray -> origin (0, 3, -5) direction (0, 0, 1)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0, 3, -5, VECTOR);
// 	direction = normalize(ft_tuple(0, 0, 1, VECTOR));
// 	ray = ft_ray(origin, direction);
// 	count = 0;
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\t"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	//check result
// 	if (check_truncated_result(false, count, count))
// 		return (-1);
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);

// //TEST 5
// 	print_sub_header("ray -> origin (0, 0, -5) direction (0, 0, 1)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0, 0, -5, VECTOR);
// 	ray = ft_ray(origin, direction);
// 	count = 0;
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\t"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	//check result
// 	if (check_truncated_result(false, count, count))
// 		return (-1);
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);

// //TEST 6
// 	print_sub_header("ray -> origin (0, 2, -5) direction (0, 0, 1)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0, 2, -5, VECTOR);
// 	ray = ft_ray(origin, direction);
// 	count = 0;
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\t"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	//check result
// 	if (check_truncated_result(false, count, count))
// 		return (-1);
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);

// //TEST 7
// 	print_sub_header("ray -> origin (0, 1, -5) direction (0, 0, 1)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0, 1, -5, VECTOR);
// 	ray = ft_ray(origin, direction);
// 	count = 0;
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\t"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	//check result
// 	if (check_truncated_result(false, count, count))
// 		return (-1);
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);

// //TEST 8
// 	print_sub_header("ray -> origin (0, 1.5, -2) direction (0, 0, 1)", &i);
// 	//redefine variables
// 	origin = ft_tuple(0, 1.5, -2, VECTOR);
// 	ray = ft_ray(origin, direction);
// 	count = 2;
// 	//run test
// 	intersect(cyl, ray, xs);
// 	count = count_hits(xs);
// 	//print output
// 	printf(B_B"xs.count: %d\t"RES, count);
// 	printf(G_B"expected: 2\n"RES);
// 	//check result
// 	if (check_truncated_result(true, count, count))
// 	return (-1);
// 	//free memory
// 	free_hitlist(xs);
// 	free_ray(ray);
// 	return (0);
// }
