/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:38:31 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:38:31 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	test_matrix_to_tuple(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int			i = 1;
// 	t_tuple		expectedv = ft_tuple(1, 2, 3, VECTOR);
// 	t_tuple		expectedp = ft_tuple(3, 4, 5, POINT);
// 	t_tuple		resv;
// 	t_tuple		resp;
// 	t_matrix	*v = create_matrix(4, 1, 0);
// 	t_matrix	*p = create_matrix(4, 1, 0);

// //TEST 1
// 	print_test_banner("Matrix to Tuple (Vector)");
// 	print_test_number(&i);
// 	v->values[0][0] = 1;
// 	v->values[1][0] = 2;
// 	v->values[2][0] = 3;
// 	v->values[3][0] = 0;
// 	printf(YEL"Matrix to be converted:\n"RES);
// 	print_matrix(v);
// 	printf(B_B"converting matrix to tuple\n");
// 	resv = matrix_to_tuple(v);
// 	print_tuple(expectedv, "EXPECTED");
// 	print_tuple(resv, "RESULT");
// 	if (equal_tuple(resv, expectedv))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));

// //TEST 2
// 	print_test_banner("Matrix to Tuple (Point)");
// 	print_test_number(&i);
// 	p->values[0][0] = 3;
// 	p->values[1][0] = 4;
// 	p->values[2][0] = 5;
// 	p->values[3][0] = 1;
// 	printf(YEL"Matrix to be converted:\n"RES);
// 	print_matrix(p);
// 	printf(B_B"converting matrix to tuple\n");
// 	resp = matrix_to_tuple(p);
// 	print_tuple(expectedp, "EXPECTED");
// 	print_tuple(resp, "RESULT");
// 	if (equal_tuple(resp, expectedp))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	free_matrix(v);
// 	free_matrix(p);
// 	return (0);
// }

// int	test_tuple_to_matrix(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	t_tuple 	a = ft_tuple(89, -20, 69, VECTOR);
// 	t_matrix	*mat = NULL;
// 	t_matrix	*expected = create_matrix(4, 1, 0);

// 	expected->values[0][0] = 89;
// 	expected->values[1][0] = -20;
// 	expected->values[2][0] = 69;
// 	expected->values[3][0] = 0;
// 	print_test_banner("Tuple to Matrix");
// 	print_tuple(a, "a");
// 	printf(B_B"converting tuple `a` to matrix..\n"RES);
// 	mat = tuple_to_matrix(a);
// 	printf(GR"EXPECTED:\n"RES);
// 	print_matrix(expected);
// 	printf(GR"RESULT:\n"RES);
// 	print_matrix(mat);
// 	if (equal_matrix(expected, mat))
// 		printf(GR"✔ values match\n"RES);
// 	else
// 		return(printf(AKA"❌ values don't match\n"RES));
// 	return (0);
// }
