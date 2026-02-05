/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:38:47 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:40:10 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	view_transform_test(int run)
// {
// 	if (!run)
// 		return (0);
// 	int i = 1;
// 	t_tuple from, to, up;
// 	t_matrix *t, *expected;

// 	// TEST 1 — Default orientation
// 	print_test_banner("View transform: default orientation");
// 	print_test_number(&i);
// 	from = ft_tuple(0, 0, 0, POINT);
// 	to = ft_tuple(0, 0, -1, POINT);
// 	up = ft_tuple(0, 1, 0, VECTOR);
// 	t = view_transform(from, to, up);
// 	expected = create_identity_matrix(4);
// 	printf(B_B"computed:\n"RES); print_matrix(t);
// 	printf(G_B"expected:\n"RES); print_matrix(expected);
// 	if (equal_matrix(t, expected))
// 		printf(GR"✔ transformation is identity\n"RES);
// 	else
// 		printf(AKA"❌ transformation is not identity\n"RES);
// 	printf("________________________________________________\n");
// 	free_matrix(t);
// 	free_matrix(expected);

// 	// TEST 2 — Looking in positive z direction
// 	print_test_banner("View transform: looking in positive Z");
// 	print_test_number(&i);
// 	from = ft_tuple(0, 0, 0, POINT);
// 	to = ft_tuple(0, 0, 1, POINT);
// 	up = ft_tuple(0, 1, 0, VECTOR);
// 	t = view_transform(from, to, up);
// 	expected = scale(-1, 1, -1);
// 	printf(B_B"computed:\n"RES); print_matrix(t);
// 	printf(G_B"expected:\n"RES); print_matrix(expected);
// 	if (equal_matrix(t, expected))
// 		printf(GR"✔ transformation matches scaling(-1, 1, -1)\n"RES);
// 	else
// 		printf(AKA"❌ transformation does not match expected\n"RES);
// 	printf("________________________________________________\n");
// 	free_matrix(t);
// 	free_matrix(expected);

// 	// TEST 3 — View transformation moves the world
// 	print_test_banner("View transform: moving the world");
// 	print_test_number(&i);
// 	from = ft_tuple(0, 0, 8, POINT);
// 	to = ft_tuple(0, 0, 0, POINT);
// 	up = ft_tuple(0, 1, 0, VECTOR);
// 	t = view_transform(from, to, up);
// 	expected = translate(0, 0, -8);
// 	printf(B_B"computed:\n"RES); print_matrix(t);
// 	printf(G_B"expected:\n"RES); print_matrix(expected);
// 	if (equal_matrix(t, expected))
// 		printf(GR"✔ transformation matches translation(0,0,-8)\n"RES);
// 	else
// 		printf(AKA"❌ transformation does not match expected\n"RES);
// 	printf("________________________________________________\n");
// 	free_matrix(t);
// 	free_matrix(expected);

// 	// TEST 4 — Arbitrary view transformation
// 	print_test_banner("View transform: arbitrary orientation");
// 	print_test_number(&i);
// 	from = ft_tuple(1, 3, 2, POINT);
// 	to = ft_tuple(4, -2, 8, POINT);
// 	up = ft_tuple(1, 1, 0, VECTOR);
// 	t = view_transform(from, to, up);
// 	expected = create_matrix(4, 4, 0);
// 	expected->values[0][0] = -0.50709;
// 	expected->values[0][1] = 0.50709;
// 	expected->values[0][2] = 0.67612;
// 	expected->values[0][3] = -2.36643;
// 	expected->values[1][0] = 0.76772;
// 	expected->values[1][1] = 0.60609;
// 	expected->values[1][2] = 0.12122;
// 	expected->values[1][3] = -2.82843;
// 	expected->values[2][0] = -0.35857;
// 	expected->values[2][1] = 0.59761;
// 	expected->values[2][2] = -0.71714;
// 	expected->values[2][3] = 0.00000;
// 	expected->values[3][0] = 0.00000;
// 	expected->values[3][1] = 0.00000;
// 	expected->values[3][2] = 0.00000;
// 	expected->values[3][3] = 1.00000;
// 	printf(B_B"computed:\n"RES); print_matrix(t);
// 	printf(G_B"expected:\n"RES); print_matrix(expected);
// 	if (equal_matrix(t, expected))
// 		printf(GR"✔ transformation matches expected matrix\n"RES);
// 	else
// 		printf(AKA"❌ transformation does not match expected\n"RES);
// 	printf("________________________________________________\n");
// 	free_matrix(t);
// 	free_matrix(expected);

// 	return (0);
// }

// int	camera_test(int run)
// {
// 	if (!run)
// 		return (0);

// 	int i = 1;
// 	t_camera	c;
// 	double		expected_hsize;
// 	double		expected_vsize;
// 	double		expected_fov;
// 	t_matrix	*expected_transf = create_identity_matrix(4);

// //TEST 1
// 	//print banners
// 	print_test_banner("Constructing a camera");
// 	print_test_number(&i);
// 	//define variables
// 	expected_hsize = 160;
// 	expected_vsize = 120;
// 	expected_fov = M_PI / 2;
// 	//run test
// 	c = ft_camera(160, 120, 90);
// 	//print output
// 	printf(B_B"c.hsize:%.0f\t"G_B"expected: %.0f\n"RES,c.hsize, expected_hsize);
// 	printf(B_B"c.vsize: %.0f\t"G_B"expected:%.0f\n"RES,c.vsize, expected_vsize);
// 	printf(B_B"c.fov:   %.2f\t"G_B"expected: %.2f\n"RES,c.fov, expected_fov);
// 	printf(B_B"c.transf:\n"RES);
// 	print_matrix(c.transf);
// 	printf(G_B"expected:\n"RES);
// 	print_matrix(expected_transf);
// 	//check output
// 	if (ft_equal(c.hsize, expected_hsize) &&
		// ft_equal(c.vsize, expected_vsize) && ft_equal(c.fov, expected_fov))
// 		printf(GR"✔ camera created successfully\n"RES);
// 	else
// 		return(printf(AKA"❌ camera creation failed\n"RES));
// 	if (equal_matrix(c.transf, expected_transf))
// 		printf(GR"✔ camera transformation is identity\n"RES);
// 	else
// 		return(printf(AKA"❌ camera transformation is not identity\n"RES));
// //TEST 2
// 	//print banners
// 	print_test_banner("Pixel size for horizontal canvas");
// 	print_test_number(&i);
// 	//define variables
// 	double expected_pixel_size = 0.01;
// 	//run test
// 	c = ft_camera(200, 125, 90);
// 	//print output
// 	printf(B_B
// "c.pixel_size:%.2f\t"G_B
// "expected:%.2f\n"RES,c.pixel_size,expected_pixel_size);
// 	//check output
// 	if (ft_equal(c.pixel_size, expected_pixel_size))
// 		printf(GR"✔ pixel size is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ pixel size is incorrect\n"RES));
// //TEST 3
// 	//print banners
// 	print_test_banner("Pixel size for vertical canvas");
// 	print_test_number(&i);
// 	//define variables
// 	expected_pixel_size = 0.01;
// 	//run test
// 	c = ft_camera(125, 200, 90);
// 	//print output
// 	printf(B_B
// "c.pixel_size: %.2f\t"G_B
// "expected: %.2f\n"RES, c.pixel_size, expected_pixel_size);
// 	//check output
// 	if (ft_equal(c.pixel_size, expected_pixel_size))
// 		printf(GR"✔ pixel size is correct\n"RES);
// 	else
// 		return(printf(AKA"❌ pixel size is incorrect\n"RES));
// //FREE RESOURCES
// 	free_matrix(expected_transf);
// 	free_matrix(c.transf);
// 	return (0);
// }
