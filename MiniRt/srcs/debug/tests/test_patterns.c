/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_patterns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:55:36 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:57:51 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	stripe_patt_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	int			i;
// 	t_patt	p;
// 	t_tuple		pt;
// 	t_colour	expected;
// 	t_colour	actual;

// 	i = 1;
// 	print_test_banner("Stripe patt is constant in Y");
// 	print_test_number(&i);

// 	p.type = PATTERN_STRIPE;
// 	p.a = ft_colour(1, 1, 1);
// 	p.b = ft_colour(0, 0, 0);
// 	p.transform = create_identity_matrix(4);

// 	// Helper macro
	// #define TEST_STRIPE_AT(x, y, z, exp_col, label) {
// 		pt = ft_tuple((double)(x), (double)(y), (double)(z), POINT);
// 		expected = exp_col;
// 		actual = stripe_at(&p, pt, NULL);
// 		printf("→ %s at point (%.1f, %.1f, %.1f)\n",
	// label, (double)(x), (double)(y), (double)(z));
// 		printf("Expected: (%.1f, %.1f, %.1f)\n",
	// expected.r, expected.g, expected.b);
// 		printf("Actual:   (%.1f, %.1f, %.1f)\n",
	// actual.r, actual.g, actual.b);
// 		if (equal_colour(actual, expected))
// 			printf(GR"✔ Passed\n\n"RES);
// 		else
// 			return (printf(AKA"❌ Failed\n\n"RES));
// 	}

// 	// Constant in Y
// 	TEST_STRIPE_AT(0, 0, 0, p.a, "Constant Y");
// 	TEST_STRIPE_AT(0, 1, 0, p.a, "Constant Y");
// 	TEST_STRIPE_AT(0, 2, 0, p.a, "Constant Y");

// 	print_test_banner("Stripe patt is constant in Z");
// 	print_test_number(&i);

// 	// Constant in Z
// 	TEST_STRIPE_AT(0, 0, 0, p.a, "Constant Z");
// 	TEST_STRIPE_AT(0, 0, 1, p.a, "Constant Z");
// 	TEST_STRIPE_AT(0, 0, 2, p.a, "Constant Z");

// 	print_test_banner("Stripe patt alternates in X");
// 	print_test_number(&i);

// 	// Alternates in X
// 	TEST_STRIPE_AT(0, 0, 0, p.a, "Stripe X");
// 	TEST_STRIPE_AT(0.9, 0, 0, p.a, "Stripe X");
// 	TEST_STRIPE_AT(1.0, 0, 0, p.b, "Stripe X");
// 	TEST_STRIPE_AT(-0.1, 0, 0, p.b, "Stripe X");
// 	TEST_STRIPE_AT(-1.0, 0, 0, p.b, "Stripe X");
// 	TEST_STRIPE_AT(-1.1, 0, 0, p.a, "Stripe X");

// 	printf(G_B"✔ All stripe patt tests passed\n"RES);
// 	free_matrix(p.transform);
// 	return (0);
// }

// int	patt_lighting_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	int			i;
// 	t_material	m;
// 	t_patt	patt;
// 	t_tuple		eyev;
// 	t_tuple		normalv;
// 	t_tuple		point;
// 	t_light		*light;
// 	t_colour	expected;
// 	t_colour	actual;
// 	t_shading	L;

// 	i = 1;
// 	print_test_banner("Lighting with a patt applied");
// 	print_test_number(&i);

// 	// Setup patt
// 	patt.type = PATTERN_STRIPE;
// 	patt.a = ft_colour(1, 1, 1); // white
// 	patt.b = ft_colour(0, 0, 0); // black
// 	patt.transform = create_identity_matrix(4);

// 	// Setup material
// 	m.c = ft_colour(1, 1, 1); // will be overridden by patt
// 	m.ambient = 1.0;
// 	m.diffuse = 0.0;
// 	m.specular = 0.0;
// 	m.shininess = 0.0;
// 	m.patt = &patt;

// 	// Common vectors and light
// 	eyev = ft_tuple(0, 0, -1, VECTOR);
// 	normalv = ft_tuple(0, 0, -1, VECTOR);
// 	light = ft_light(ft_tuple(0, 0, -10, POINT), ft_colour(1, 1, 1), 1.0);

// 	// Test point 0.9 → should be white
// 	point = ft_tuple(0.9, 0, 0, POINT);
// 	L.m = m;
// 	L.l = light;
// 	L.point = point;
// 	L.eyev = eyev;
// 	L.normalv = normalv;
// 	actual = ft_shading(L, false);
// 	expected = ft_colour(1, 1, 1);

// 	printf("Point: (%.1f, %.1f, %.1f)\n", point.x, point.y, point.z);
// 	printf("Expected: (%.1f, %.1f, %.1f)\n",
		// expected.r, expected.g, expected.b);
// 	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Lighting is correct at point 0.9 (white stripe)\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Lighting failed at point 0.9\n\n"RES));

// 	// Test point 1.1 → should be black
// 	point = ft_tuple(1.1, 0, 0, POINT);
// 	L.point = point;
// 	actual = ft_shading(L, false);
// 	expected = ft_colour(0, 0, 0);

// 	printf("Point: (%.1f, %.1f, %.1f)\n", point.x, point.y, point.z);
// 	printf("Expected: (%.1f, %.1f, %.1f)\n",
		// expected.r, expected.g, expected.b);
// 	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Lighting is correct at point 1.1 (black stripe)\n"RES);
// 	else
// 		return (printf(AKA"❌ Lighting failed at point 1.1\n"RES));

// 	free(light);
// 	free_matrix(patt.transform);
// 	return (0);
// }

// int	stripe_transform_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	int			i;
// 	t_patt	patt;
// 	t_sphere	*s;
// 	t_tuple		world_point;
// 	t_colour	expected;
// 	t_colour	actual;

// 	i = 1;
// 	print_test_banner("Stripes with object transformation");
// 	print_test_number(&i);

// 	s = ft_sphere(1);
// 	patt = stripe_patt(ft_colour(1, 1, 1), ft_colour(0, 0, 0));
// 	set_transf(s, scale(2, 2, 2));

// 	world_point = ft_tuple(1.5, 0, 0, POINT);
// 	expected = ft_colour(1, 1, 1);
// 	actual = patt_colour_at_world(&patt, (t_object *)s, world_point);

// 	printf("Point: (%.1f, %.1f, %.1f)\n",
	// world_point.x, world_point.y, world_point.z);
// 	printf("Expected: (%.1f, %.1f, %.1f)\n",
		// expected.r, expected.g, expected.b);
// 	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: object transform\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: object transform\n\n"RES));

// 	print_test_banner("Stripes with patt transformation");
// 	print_test_number(&i);

// 	s = ft_sphere(1);
// 	set_transf(s, create_identity_matrix(4));
// 	patt = stripe_patt(ft_colour(1, 1, 1), ft_colour(0, 0, 0));
// 	free_matrix(patt.transform);
// 	patt.transform = scale(2, 2, 2);

// 	world_point = ft_tuple(1.5, 0, 0, POINT);
// 	expected = ft_colour(1, 1, 1);
// 	actual = patt_colour_at_world(&patt, (t_object *)s, world_point);

// 	printf("Point: (%.1f, %.1f, %.1f)\n",
		// world_point.x, world_point.y, world_point.z);
// 	printf("Expected: (%.1f, %.1f, %.1f)\n",
		// expected.r, expected.g, expected.b);
// 	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: patt transform\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: patt transform\n\n"RES));

// 	print_test_banner("Stripes with object and patt transformations");
// 	print_test_number(&i);

// 	s = ft_sphere(1);
// 	set_transf(s, scale(2, 2, 2));
// 	patt = stripe_patt(ft_colour(1, 1, 1), ft_colour(0, 0, 0));
// 	free_matrix(patt.transform);
// 	patt.transform = translate(0.5, 0, 0);

// 	world_point = ft_tuple(2.5, 0, 0, POINT);
// 	expected = ft_colour(1, 1, 1);
// 	actual = patt_colour_at_world(&patt, (t_object *)s, world_point);

// 	printf("Point: (%.1f, %.1f, %.1f)\n", world_point.x,
		// world_point.y, world_point.z);
// 	printf("Expected: (%.1f, %.1f, %.1f)\n",
		// expected.r, expected.g, expected.b);
// 	printf("Actual:   (%.1f, %.1f, %.1f)\n", actual.r, actual.g, actual.b);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: object + patt transform\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: object + patt transform\n\n"RES));

// 	free_matrix(patt.transform);
// 	free_sphere(s);
// 	return (0);
// }

// int	patt_generalization_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	// int			i;
// 	// t_patt	patt;
// 	// t_sphere	*s;
// 	// t_tuple		world_point;
// 	// t_colour	expected;
// 	// t_colour	actual;

// 	// i = 1;
// 	// print_test_banner("patt with object transformation");
// 	// print_test_number(&i);

// 	// s = ft_sphere(1);
// 	// patt = test_patt();
// 	// set_transf(s, scale(2, 2, 2));

// 	// world_point = ft_tuple(2, 3, 4, POINT);
// 	// expected = ft_colour(1, 1.5, 2);
// 	// actual = patt_colour_at_world(&patt, (t_object *)s, world_point);

// 	// printf("Expected: (%.2f, %.2f, %.2f)\n",
		// expected.r, expected.g, expected.b);
// 	// printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
// 	// if (equal_colour(actual, expected))
// 	// 	printf(GR"✔ Passed: object transformation\n\n"RES);
// 	// else
// 	// 	return (printf(AKA"❌ Failed: object transformation\n\n"RES));

// 	// print_test_banner("patt with patt transformation");
// 	// print_test_number(&i);

// 	// s = ft_sphere(1);
// 	// patt = test_patt();
// 	// free_matrix(patt.transform);
// 	// patt.transform = scale(2, 2, 2);

// 	// world_point = ft_tuple(2, 3, 4, POINT);
// 	// expected = ft_colour(1, 1.5, 2);
// 	// actual = patt_colour_at_world(&patt, (t_object *)s, world_point);

// 	// printf("Expected: (%.2f, %.2f, %.2f)\n",
			// expected.r, expected.g, expected.b);
// 	// printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
// 	// if (equal_colour(actual, expected))
// 	// 	printf(GR"✔ Passed: patt transformation\n\n"RES);
// 	// else
// 	// 	return (printf(AKA"❌ Failed: patt transformation\n\n"RES));

// 	// print_test_banner("patt with object and patt transformation");
// 	// print_test_number(&i);

// 	// s = ft_sphere(1);
// 	// patt = test_patt();
// 	// set_transf(s, scale(2, 2, 2));
// 	// free_matrix(patt.transform);
// 	// patt.transform = translate(0.5, 1, 1.5);

// 	// world_point = ft_tuple(2.5, 3, 3.5, POINT);
// 	// expected = ft_colour(0.75, 0.5, 0.25);
// 	// actual = patt_colour_at_world(&patt, (t_object *)s, world_point);

// 	// printf("Expected: (%.2f, %.2f, %.2f)\n",
		// expected.r, expected.g, expected.b);
// 	// printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
// 	// if (equal_colour(actual, expected))
// 	// 	printf(GR"✔ Passed: object + patt transformation\n"RES);
// 	// else
// 	// 	return (printf(AKA"❌ Failed: object + patt transformation\n"RES));

// 	// free_matrix(patt.transform);
// 	// free_sphere(s);
// 	return (0);
// }

// int	gradient_patt_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	int			i = 1;
// 	t_patt	patt;
// 	t_tuple		p;
// 	t_colour	expected;
// 	t_colour	actual;

// 	print_test_banner("Gradient patt Linearly Interpolates Between Colors");

// 	// Setup
// 	patt.type = PATTERN_GRADIENT;
// 	patt.a = ft_colour(1, 1, 1); // white
// 	patt.b = ft_colour(0, 0, 0); // black
// 	patt.transform = create_identity_matrix(4);

// 	// Test 1
// 	print_test_number(&i);
// 	p = ft_tuple(0, 0, 0, POINT);
// 	expected = ft_colour(1, 1, 1);
// 	actual = gradient_at(&patt, p);
// 	printf("Expected: (%.2f, %.2f, %.2f)\n",
		// expected.r, expected.g, expected.b);
// 	printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: point(0,0,0) = white\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: point(0,0,0)\n\n"RES));

// 	// Test 2
// 	print_test_number(&i);
// 	p = ft_tuple(0.25, 0, 0, POINT);
// 	expected = ft_colour(0.75, 0.75, 0.75);
// 	actual = gradient_at(&patt, p);
// 	printf("Expected: (%.2f, %.2f, %.2f)\n",
		// expected.r, expected.g, expected.b);
// 	printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: point(0.25,0,0)\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: point(0.25,0,0)\n\n"RES));

// 	// Test 3
// 	print_test_number(&i);
// 	p = ft_tuple(0.5, 0, 0, POINT);
// 	expected = ft_colour(0.5, 0.5, 0.5);
// 	actual = gradient_at(&patt, p);
// 	printf("Expected: (%.2f, %.2f, %.2f)\n",
		// expected.r, expected.g, expected.b);
// 	printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: point(0.5,0,0)\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: point(0.5,0,0)\n\n"RES));

// 	// Test 4
// 	print_test_number(&i);
// 	p = ft_tuple(0.75, 0, 0, POINT);
// 	expected = ft_colour(0.25, 0.25, 0.25);
// 	actual = gradient_at(&patt, p);
// 	printf("Expected: (%.2f, %.2f, %.2f)\n",
// 		expected.r, expected.g, expected.b);
// 	printf("Actual:   (%.2f, %.2f, %.2f)\n", actual.r, actual.g, actual.b);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: point(0.75,0,0)\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: point(0.75,0,0)\n\n"RES));

// 	free_matrix(patt.transform);
// 	return (0);
// }

// int	ring_patt_test(int run)
// {
// 	if (!run)
// 		return (0);

// 	int i = 1;
// 	t_patt patt;
// 	t_colour expected, actual;

// 	print_test_banner("Ring patt Should Extend in Both X and Z");

// 	patt.type = PATTERN_RING;
// 	patt.a = ft_colour(1, 1, 1); // white
// 	patt.b = ft_colour(0, 0, 0); // black
// 	patt.transform = create_identity_matrix(4);

// 	// point at origin
// 	print_test_number(&i);
// 	expected = ft_colour(1, 1, 1);
// 	actual = ring_at(&patt, ft_tuple(0, 0, 0, POINT),NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (0,0,0) = white\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (0,0,0)\n\n"RES));

// 	// point on X ring edge
// 	print_test_number(&i);
// 	expected = ft_colour(0, 0, 0);
// 	actual = ring_at(&patt, ft_tuple(1, 0, 0, POINT), NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (1,0,0) = black\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (1,0,0)\n\n"RES));

// 	// point just outside first ring
// 	print_test_number(&i);
// 	expected = ft_colour(0, 0, 0);
// 	actual = ring_at(&patt, ft_tuple(0, 0, 1, POINT), NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (0,0,1) = black\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (0,0,1)\n\n"RES));

// 	// diagonally at √2 ≈ 1.41 -> floor(1.41) == 1 -> black
// 	print_test_number(&i);
// 	expected = ft_colour(0, 0, 0);
// 	actual = ring_at(&patt, ft_tuple(0.708, 0, 0.708, POINT), NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: diagonal (0.708,0,0.708) = black\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: diagonal point\n\n"RES));

// 	free_matrix(patt.transform);
// 	return (0);
// }

// int	checkers_patt_test(int run)
// {
// 	if (!run)
// 		return (0);

// 	int i = 1;
// 	t_patt patt;
// 	t_colour expected, actual;

// 	print_test_banner("Checkers patt Should Repeat in 3D");

// 	patt.type = PATTERN_CHECKERS;
// 	patt.a = ft_colour(1, 1, 1); // white
// 	patt.b = ft_colour(0, 0, 0); // black
// 	patt.transform = create_identity_matrix(4);

// 	// x changes
// 	print_test_number(&i);
// 	expected = ft_colour(1, 1, 1);
// 	actual = checkers_at(&patt, ft_tuple(0, 0, 0, POINT),NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (0,0,0) = white\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (0,0,0)\n\n"RES));

// 	print_test_number(&i);
// 	expected = ft_colour(1, 1, 1);
// 	actual = checkers_at(&patt, ft_tuple(0.99, 0, 0, POINT), NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (0.99,0,0) = white\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (0.99,0,0)\n\n"RES));

// 	print_test_number(&i);
// 	expected = ft_colour(0, 0, 0);
// 	actual = checkers_at(&patt, ft_tuple(1.01, 0, 0, POINT), NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (1.01,0,0) = black\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (1.01,0,0)\n\n"RES));

// 	// y changes
// 	print_test_number(&i);
// 	expected = ft_colour(1, 1, 1);
// 	actual = checkers_at(&patt, ft_tuple(0, 0.99, 0, POINT), NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (0,0.99,0) = white\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (0,0.99,0)\n\n"RES));

// 	print_test_number(&i);
// 	expected = ft_colour(0, 0, 0);
// 	actual = checkers_at(&patt, ft_tuple(0, 1.01, 0, POINT), NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (0,1.01,0) = black\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (0,1.01,0)\n\n"RES));

// 	// z changes
// 	print_test_number(&i);
// 	expected = ft_colour(1, 1, 1);
// 	actual = checkers_at(&patt, ft_tuple(0, 0, 0.99, POINT), NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (0,0,0.99) = white\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (0,0,0.99)\n\n"RES));

// 	print_test_number(&i);
// 	expected = ft_colour(0, 0, 0);
// 	actual = checkers_at(&patt, ft_tuple(0, 0, 1.01, POINT), NULL);
// 	if (equal_colour(actual, expected))
// 		printf(GR"✔ Passed: (0,0,1.01) = black\n\n"RES);
// 	else
// 		return (printf(AKA"❌ Failed: (0,0,1.01)\n\n"RES));

// 	free_matrix(patt.transform);
// 	return (0);
// }
