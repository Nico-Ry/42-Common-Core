/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rodrigues.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:48:33 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:50:04 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	rodrigues_rotation_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	int i = 1;
// 	t_tuple	from, to;
// 	t_matrix *rotation;
// 	t_matrix *from_mtx;
// 	t_matrix *rotated_mtx;
// 	t_tuple	rotated;

// 	print_test_banner("Rodrigues rotation tests");
// 	print_test_number(&i);

// 	#define TEST_RODRIGUES(FROM, TO, LABEL) {
// 		from = FROM;
// 		to = TO;
// 		rotation = rotation_matrix(from, to);
// 		from_mtx = tuple_to_matrix(from);
// 		rotated_mtx = multiply_matrices(rotation, from_mtx);
// 		rotated = matrix_to_tuple(rotated_mtx);
// 		printf("→ %s\n", LABEL);
// 		printf("  Rotated result: (%.5f, %.5f, %.5f)\n",
			// rotated.x, rotated.y, rotated.z);
// 		printf("  Expected:       (%.5f, %.5f, %.5f)\n",
			// to.x, to.y, to.z);
// 		if (fabs(rotated.x - to.x) > 0.01 ||
		// fabs(rotated.y - to.y) > 0.01 || fabs(rotated.z - to.z) > 0.01)
// 			return (printf(AKA"❌ Failed\n\n"RES));
// 		printf(GR"✔ Passed\n\n"RES);
// 		free_matrix(rotation);
// 		free_matrix(from_mtx);
// 		free_matrix(rotated_mtx);
// 	}

// 	// Now the actual tests
// 	printf("First test #############\n");
// 	TEST_RODRIGUES(ft_tuple(0, 1, 0, VECTOR),
	// ft_tuple(1, 0, 0, VECTOR), "Rotate UP → RIGHT");

// 	printf("Second test ##################\n");
// 	TEST_RODRIGUES(ft_tuple(0, 0, 1, VECTOR),
	// ft_tuple(0, 1, 0, VECTOR), "Rotate FORWARD → UP");

// 	printf("Third test ####################\n");
// 	TEST_RODRIGUES(ft_tuple(1, 0, 0, VECTOR),
	// ft_tuple(0, 0, -1, VECTOR), "Rotate RIGHT → BACKWARD");

// 	return (0);
// }
