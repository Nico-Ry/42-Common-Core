/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:38:10 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:38:10 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// static int	rotate_x_test()
// {
// 	int	i = 1;
// 	t_matrix	*half_quarter = rotate_x(M_PI / 4);
// 	t_matrix	*full_quarter = rotate_x(M_PI / 2);
// 	t_matrix	*inverse = invert_matrix(half_quarter);
// 	t_tuple		point = ft_tuple(0, 1, 0, POINT);
// 	t_matrix	*p;
// 	t_matrix	*result = NULL;
// 	t_tuple		expected;

// //TEST 1
// 	//print banners
// 	print_test_banner("X ROTATION");
// 	print_test_banner("Rotating a point half a quarter around the x-axis\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	p = tuple_to_matrix(point);
// 	expected = ft_tuple(0, sqrt(2) / 2, sqrt(2) / 2, POINT);
// 	//run test
// 	result = multiply_matrices(half_quarter, p);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected));
// 	//check output
// 	if (equal_matrix(result, tuple_to_matrix(expected)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// //TEST 2
// 	//print banners
// 	print_test_banner("Rotating a point full quarter around the x-axis\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	free_matrix(result);
// 	expected = ft_tuple(0, 0, 1, POINT);
// 	//run test
// 	result = multiply_matrices(full_quarter, p);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected));
// 	//check output
// 	if (equal_matrix(result, tuple_to_matrix(expected)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// //TEST 3
// 	//print banners
// 	print_test_banner(R_B"[INVERSE]"B_B" Rotating a point half a quarter\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	free_matrix(result);
// 	expected = ft_tuple(0, sqrt(2) / 2, -(sqrt(2) / 2), POINT);
// 	//run test
// 	result = multiply_matrices(inverse, p);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected));
// 	//check output
// 	if (equal_matrix(result, tuple_to_matrix(expected)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	//free resources
// 	free_matrix(p);
// 	free_matrix(result);
// 	free_matrix(half_quarter);
// 	free_matrix(full_quarter);
// 	free_matrix(inverse);
// 	return (0);
// }

// static int	rotate_y_test()
// {
// 	int	i = 1;
// 	t_matrix	*half_quarter = rotate_y(M_PI / 4);
// 	t_matrix	*full_quarter = rotate_y(M_PI / 2);
// 	t_tuple		point = ft_tuple(0, 0, 1, POINT);
// 	t_matrix	*p = tuple_to_matrix(point);
// 	t_matrix	*result = NULL;
// 	t_tuple		expected;

// //TEST 1
// 	//print banners
// 	print_test_banner("Y ROTATION");
// 	print_test_banner("[Y] Rotating a point half a quarter\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	expected = ft_tuple(sqrt(2) / 2, 0, sqrt(2) / 2, POINT);
// 	//run test
// 	result = multiply_matrices(half_quarter, p);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected));
// 	//check output
// 	if (equal_matrix(result, tuple_to_matrix(expected)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// //TEST 2
// 	//print banners
// 	print_test_banner("[Y] Rotating a point full quarter\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	free_matrix(result);
// 	expected = ft_tuple(1, 0, 0, POINT);
// 	//run test
// 	result = multiply_matrices(full_quarter, p);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected));
// 	//check output
// 	if (equal_matrix(result, tuple_to_matrix(expected)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	//free resources
// 	free_matrix(p);
// 	free_matrix(result);
// 	free_matrix(half_quarter);
// 	free_matrix(full_quarter);
// 	return (0);
// }

// static int	rotate_z_test()
// {
// 	int	i = 1;
// 	t_matrix	*half_quarter = rotate_z(M_PI / 4);
// 	t_matrix	*full_quarter = rotate_z(M_PI / 2);
// 	t_tuple		point = ft_tuple(0, 1, 0, POINT);
// 	t_matrix	*p = tuple_to_matrix(point);
// 	t_matrix	*result = NULL;
// 	t_tuple		expected;

// //TEST 1
// 	//print banners
// 	print_test_banner("Z ROTATION");
// 	print_test_banner("[Z] Rotating a point half a quarter\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	expected = ft_tuple(-sqrt(2) / 2, sqrt(2) / 2, 0, POINT);
// 	//run test
// 	result = multiply_matrices(half_quarter, p);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected));
// 	//check output
// 	if (equal_matrix(result, tuple_to_matrix(expected)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// //TEST 2
// 	//print banners
// 	print_test_banner("[Z] Rotating a point full quarter\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	free_matrix(result);
// 	expected = ft_tuple(-1, 0, 0, POINT);
// 	//run test
// 	result = multiply_matrices(full_quarter, p);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected));
// 	//check output
// 	if (equal_matrix(result, tuple_to_matrix(expected)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	//free resources
// 	free_matrix(p);
// 	free_matrix(result);
// 	free_matrix(half_quarter);
// 	free_matrix(full_quarter);
// 	return (0);
// }

// int	rotate_test(int x, int y, int z)
// {
// 	if (x)
// 	{
// 		if (rotate_x_test())
// 		{
// 			printf("Error: rotate_x_test failed\n");
// 			return (1);
// 		}
// 	}
// 	if (y)
// 	{
// 		if (rotate_y_test())
// 		{
// 			printf("Error: rotate_y_test failed\n");
// 			return (1);
// 		}
// 	}
// 	if (z)
// 	{
// 		if (rotate_z_test())
// 		{
// 			printf("Error: rotate_z_test failed\n");
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

// //############################################################
// //############################################################
// //################# SCALE & TRANSLATE ########################
// //############################################################
// //############################################################

// //TRANSLATE TEST
// int	translate_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int	i = 1;
// 	t_matrix	*transform = translate(5, -3, 2);
// 	t_matrix	*inverse;
// 	t_matrix	*result = NULL;
// 	t_tuple		point = ft_tuple(-3, 4, 5, POINT);
// 	t_tuple		vector = ft_tuple(-3, 4, 5, VECTOR);
// 	t_matrix	*p = tuple_to_matrix(point);
// 	t_matrix	*expected_p = create_matrix(4, 1, 0);
// 	t_matrix	*v;
// 	t_matrix	*expected_v = create_matrix(4, 1, 0);

// //TEST 1
// 	//print banners
// 	print_test_banner("TRANSLATION");
// 	print_test_number(&i);
// 	//initiate variables
// 	expected_p->values[0][0] = 2;
// 	expected_p->values[1][0] = 1;
// 	expected_p->values[2][0] = 7;
// 	expected_p->values[3][0] = 1;
// 	//run test
// 	result = multiply_matrices(transform, p);
// 	//print output
// 	printf("Multiplying `p` by translation matrix\n");
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(expected_p);
// 	//check output
// 	if (equal_matrix(result, expected_p))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// //TEST 2
// 	//print banner
// 	print_test_number(&i);
// 	//redfine variables
// 	inverse = invert_matrix(transform);
// 	//run test
// 	result = multiply_matrices(inverse, result);
// 	//print output
// 	printf("multiplying by inverse matrix:\n");
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(p);
// 	//check output
// 	if (equal_matrix(result, p))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	//free resources
// 	free_matrix(result);
// 	free_matrix(p);
// 	free_matrix(expected_p);
// //TEST 3
// 	//print banners
// 	print_test_number(&i);
// 	//initiate variables
// 	v = tuple_to_matrix(vector);
// 	expected_v->values[0][0] = -3;
// 	expected_v->values[1][0] = 4;
// 	expected_v->values[2][0] = 5;
// 	expected_v->values[3][0] = 0;
// 	//run test
// 	result = multiply_matrices(transform, v);
// 	//print ou tput
// 	printf("Multiplying vector by tranlation matrix:\n");
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(expected_v);
// 	//check output
// 	if (equal_matrix(result, expected_v))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	//free resources
// 	free_matrix(transform);
// 	free_matrix(inverse);
// 	return (0);
// }

// //SCALE TEST
// int	scale_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int	i = 1;
// 	t_tuple		point;
// 	t_tuple		vector;

// 	t_matrix	*transform = scale(2, 3, 4);
// 	t_matrix	*inverse = invert_matrix(transform);

// 	t_matrix	*result_p = NULL;
// 	t_matrix	*result_v = NULL;

// //TEST 1
// 	//print banners
// 	print_test_banner("SCALE");
// 	print_test_banner("Multiplying a POINT by scaling matrix\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	point = ft_tuple(-4, 6, 8, POINT);
// 	t_matrix	*p = tuple_to_matrix(point);
// 	t_tuple		expected_p = ft_tuple(-8,18,32,POINT);
// 	//run test
// 	result_p = multiply_matrices(transform, p);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result_p);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected_p));
// 	//check output
// 	if (equal_matrix(result_p, tuple_to_matrix(expected_p)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// //TEST 2
// 	//print banners
// 	print_test_banner("Multiplying a VECTOR by scaling matrix\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	vector = ft_tuple(-4, 6, 8, VECTOR);
// 	t_matrix	*v = tuple_to_matrix(vector);
// 	t_tuple		expected_v = ft_tuple(-8,18,32,VECTOR);
// 	//run test
// 	result_v = multiply_matrices(transform, v);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result_v);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected_v));
// 	//check output
// 	if (equal_matrix(result_v, tuple_to_matrix(expected_v)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// //TEST 3
// 	//print banners
// 	print_test_banner("Multiplying a VECTOR by inverse scaling matrix\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	free_matrix(result_v);
// 	expected_v = ft_tuple(-2, 2, 2, VECTOR);
// 	//run test
// 	result_v = multiply_matrices(inverse, v);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result_v);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected_v));
// 	//check output
// 	if (equal_matrix(result_v, tuple_to_matrix(expected_v)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// //TEST 4
// 	//print banners
// 	print_test_banner("Reflection is scaling a POINT by a negative value\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	free_matrix(transform);
// 	free_matrix(result_p);
// 	free_matrix(p);
// 	transform = scale(-1, 1, 1);
// 	point = ft_tuple(2, 3, 4, POINT);
// 	p = tuple_to_matrix(point);
// 	expected_p = ft_tuple(-2, 3, 4, POINT);
// 	//run test
// 	result_p = multiply_matrices(transform, p);
// 	//print output
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(result_p);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected_p));
// 	//check output
// 	if (equal_matrix(result_p, tuple_to_matrix(expected_p)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	//free resources
// 	free_matrix(p);
// 	free_matrix(v);
// 	free_matrix(result_p);
// 	free_matrix(result_v);
// 	free_matrix(transform);
// 	free_matrix(inverse);
// 	return (0);
// }

// //############################################################
// //############################################################
// //################# CHAINED TRANSFORM ########################
// //############################################################
// //############################################################

// int	chained_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	//define variables
// 	int	i = 1;
// 	t_matrix	*p = tuple_to_matrix(ft_tuple(1, 0, 1, POINT));
// 	t_matrix	*A = rotate_x(M_PI/2);
// 	t_matrix	*B = scale(5, 5, 5);
// 	t_matrix	*C = translate(10, 5, 7);
// 	t_tuple		expected = ft_tuple(15, 0, 7, POINT);

// //TEST 1
// 	//print banners
// 	print_test_banner("CHAINED");
// 	print_test_banner("Applying transformations one by one\n");
// 	print_test_number(&i);
// 	//run test
// 	printf(B_B"STARTING POINT:\n"RES);
// 	print_matrix(p);
// 	printf(B_B"rotating..\n"RES);
// 	t_matrix	*p2 = multiply_matrices(A, p);
// 	print_matrix(p2);
// 	printf(B_B"scaling..\n"RES);
// 	t_matrix	*p3 = multiply_matrices(B, p2);
// 	print_matrix(p3);
// 	printf(B_B"translating..\n"RES);
// 	printf(B_B"FINAL RESULT:\n"RES);
// 	t_matrix	*p4 = multiply_matrices(C, p3);
// 	print_matrix(p4);
// 	//print output
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected));
// 	//check output
// 	if (equal_matrix(p4, tuple_to_matrix(expected)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// //TEST 2
// 	//print banners
// 	print_test_banner("Chaining transformations in one\n");
// 	print_test_number(&i);
// 	//initiate variables
// 	t_matrix	*chained = multiply_matrices(C, multiply_matrices(B, A));
// 	//run test
// 	p = multiply_matrices(chained, p);
// 	//print output
// 	printf("Chained Matrix:\n");
// 	print_matrix(chained);
// 	printf("applying chained matrix to p..\n");
// 	printf(B_B"RESULT:\n"RES);
// 	print_matrix(p);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(tuple_to_matrix(expected));
// 	//check output
// 	if (equal_matrix(p, tuple_to_matrix(expected)))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	//free resources
// 	free_matrix(p);
// 	free_matrix(p2);
// 	free_matrix(p3);
// 	free_matrix(p4);
// 	free_matrix(chained);
// 	free_matrix(A);
// 	free_matrix(B);
// 	free_matrix(C);
// 	return (0);
// }
