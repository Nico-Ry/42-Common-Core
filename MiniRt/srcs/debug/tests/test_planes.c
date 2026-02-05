/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:25:07 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:25:07 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	local_normal_plane_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	t_plane	*plane;
// 	t_tuple	n1;
// 	t_tuple	n2;
// 	t_tuple	n3;
// 	t_tuple	p1;
// 	t_tuple	p2;
// 	t_tuple	p3;
// 	t_tuple	expected = ft_tuple(0, 1, 0, VECTOR);
// 	int		i = 1;

// //TEST 1
// 	//print banners
// 	print_test_banner("The normal of a plane is constant");
// 	print_test_number(&i);
// 	//initiate variables
// 	plane = ft_plane();
// 	p1 = ft_tuple(0, 0, 0, POINT);
// 	p2 = ft_tuple(10, 0, -10, POINT);
// 	p3 = ft_tuple(-5, 0, 150, POINT);
// 	//run test
// 	n1 = local_normal_at(plane, p1);
// 	n2 = local_normal_at(plane, p2);
// 	n3 = local_normal_at(plane, p3);
// 	//print output
// 	printf(YEL"point:    (%.0f, %.0f, %.0f)\n"RES, p1.x, p1.y, p1.z);
// 	print_normal(n1, expected, PLANE);
// 	if (equal_tuple(n1, expected))
// 		printf(GR"✔ normal is correct\n\n"RES);
// 	else
// 		return(printf(AKA"❌ normal is incorrect\n"RES));
// 	printf(YEL"point:    (%.0f, %.0f, %.0f)\n"RES, p2.x, p2.y, p2.z);
// 	print_normal(n2, expected, PLANE);
// 	if (equal_tuple(n2, expected))
// 		printf(GR"✔ normal is correct\n\n"RES);
// 	else
// 		return(printf(AKA"❌ normal is incorrect\n"RES));
// 	printf(YEL"point:    (%.0f, %.0f, %.0f)\n"RES, p3.x, p3.y, p3.z);
// 	print_normal(n3, expected, PLANE);
// 	if (equal_tuple(n3, expected))
// 		printf(GR"✔ normal is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ normal is incorrect\n"RES));
// 	return (0);
// }

// int	intersect_plane_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	t_plane		*plane;
// 	t_ray		*ray;
// 	t_hitlist	**xs = new_hitlist();
// 	int			i = 1;
// 	int			count;

// //TEST 1
// 	//print banners
// 	print_test_banner("Intersecting rays with planes");
// 	print_sub_header("Ray parallel to the plane", &i);
// 	//initiate variables
// 	plane = ft_plane();
// 	ray = ft_ray(ft_tuple(0, 10, 0, POINT), ft_tuple(0, 0, 1, VECTOR));
// 	//run test
// 	intersect(plane, ray, xs);
// 	//print output
// 	count = count_hits(xs);
// 	printf(B_B"xs.count: %d\n"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	if (count == 0)
// 		printf(GR"✔ No intersections!\n\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 0\n"RES));
// 	//free resources
// 	free_ray(ray);
// 	free_hitlist(xs);

// //TEST 2
// 	//print banners
// 	print_sub_header("Ray coplanar to the plane",&i);
// 	//redefine ray
// 	ray = ft_ray(ft_tuple(0, 0, 0, POINT), ft_tuple(0, 0, 1, VECTOR));
// 	//run test
// 	intersect(plane, ray, xs);
// 	//print output
// 	count = count_hits(xs);
// 	printf(B_B"xs.count: %d\n"RES, count);
// 	printf(G_B"expected: 0\n"RES);
// 	if (count == 0)
// 		printf(GR"✔ No intersections!\n\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 0\n"RES));
// 	//free resources
// 	free_ray(ray);
// 	free_hitlist(xs);

// //TEST 3
// 	//print banners
// 	print_sub_header("Ray intersecting from above",&i);
// 	//redefine ray
// 	ray = ft_ray(ft_tuple(0, 1, 0, POINT), ft_tuple(0, -1, 0, VECTOR));
// 	//run test
// 	intersect(plane, ray, xs);
// 	//print output
// 	count = count_hits(xs);
// 	printf(B_B"xs.count: %d\n"RES, count);
// 	printf(G_B"expected: 1\n"RES);
// 	printf(B_B"xs[0]->t: %.1f\n"RES, (*xs)->hit->t);
// 	printf(G_B"expected: 1.0\n"RES);
// 	if (count == 1 && ft_equal((*xs)->hit->t, 1))
// 		printf(GR"✔ Intersection at t=1\n\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 1 or t != 1\n"RES));
// 	//free resources
// 	free_ray(ray);
// 	free_hitlist(xs);

// //TEST 4
// 	//print banners
// 	print_sub_header("Ray intersecting from below",&i);
// 	//redefine ray
// 	ray = ft_ray(ft_tuple(0, -1, 0, POINT), ft_tuple(0, 1, 0, VECTOR));
// 	//run test
// 	intersect(plane, ray, xs);
// 	//print output
// 	count = count_hits(xs);
// 	printf(B_B"xs.count: %d\n"RES, count);
// 	printf(G_B"expected: 1\n"RES);
// 	printf(B_B"xs[0]->t: %.1f\n"RES, (*xs)->hit->t);
// 	printf(G_B"expected: 1.0\n"RES);
// 	if (count == 1 && ft_equal((*xs)->hit->t, 1))
// 		printf(GR"✔ Intersection at t=1\n\n"RES);
// 	else
// 		return(printf(AKA"❌ xs.count != 1 or t != 1\n"RES));
// 	//free resources
// 	free_ray(ray);
// 	free_hitlist(xs);
// 	return (0);
// }
