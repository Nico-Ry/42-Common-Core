/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_normal_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:34:56 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:35:02 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	normal_at_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	t_sphere	*s;
// 	t_tuple		world_point;
// 	t_tuple		normal;
// 	t_tuple		expected;
// 	t_matrix	*transf;
// 	int			i = 1;

// //TEST 1
// 	//print banners
// 	print_test_banner("normal on a translated sphere");
// 	print_test_number(&i);
// 	//initiate variables
// 	s = ft_sphere(1);
// 	transf = translate(0, 1, 0);
// 	set_transf(s, transf);
// 	world_point = ft_tuple(0, 1.70711, -0.707111, POINT);
// 	expected = ft_tuple(0, 0.70711, -0.707111, VECTOR);
// 	//run test
// 	normal = normal_at(s, world_point);
// 	//print output and free relevant vars
// 	print_normal(normal, expected, SPHERE);
// 	//check output
// 	if (equal_tuple(normal, expected))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));

// //TEST 2
// 	//print banners
// 	print_test_banner("normal on a transformed sphere");
// 	print_test_number(&i);
// 	//initiate variables
// 	transf = multiply_matrices(scale(1, 0.5, 1), rotate_z(M_PI/5));
// 	set_transf(s, transf);
// 	world_point = ft_tuple(0, sqrt(2)/2, -(sqrt(2)/2), POINT);
// 	expected = ft_tuple(0, 0.97014, -0.24254, VECTOR);
// 	//run test
// 	normal = normal_at(s, world_point);
// 	//print output and free relevant vars
// 	print_normal(normal, expected, SPHERE);
// 	//check output
// 	if (equal_tuple(normal, expected))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));
// 	//free all unused variables hereafter
// 	free_sphere(s);

// //define new variables for reflection tests
// 	t_tuple	v;
// 	t_tuple	n;
// 	t_tuple	r;

// //TEST 3
// 	//print_banners
// 	print_test_banner("Reflecting a vector approaching at 45°");
// 	print_test_number(&i);
// 	//initiate variables
// 	v = ft_tuple(1, -1, 0, VECTOR);
// 	n = ft_tuple(0, 1, 0, VECTOR);
// 	expected = ft_tuple(1, 1, 0, VECTOR);
// 	//run test
// 	r = ft_reflect(v, n);
// 	//print ouput
// 	print_reflected(r, expected);
// 	//check output
// 	if (equal_tuple(r, expected))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));

// //TEST 4
// 	//print_banners
// 	print_test_banner("Reflecting a vector off a slanted surface");
// 	print_test_number(&i);
// 	//initiate variables
// 	v = ft_tuple(0, -1, 0, VECTOR);
// 	n = ft_tuple(sqrt(2)/2, sqrt(2)/2, 0, VECTOR);
// 	expected = ft_tuple(1, 0, 0, VECTOR);
// 	//run test
// 	r = ft_reflect(v, n);
// 	//print ouput
// 	print_reflected(r, expected);
// 	//check output
// 	if (equal_tuple(r, expected))
// 		printf(GR"✔ tuples match\n"RES);
// 	else
// 		return(printf(AKA"❌ tuples don't match\n"RES));
// 	return (0);
// }
