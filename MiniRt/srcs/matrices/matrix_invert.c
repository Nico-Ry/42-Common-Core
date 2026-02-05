/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:03:44 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:04:32 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*compute_cofactor_matrix(t_matrix *matrix)
{
	int			i;
	int			j;
	t_matrix	*cofactor_matrix;

	cofactor_matrix = create_matrix(matrix->rows, matrix->cols, 0);
	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->cols)
		{
			cofactor_matrix->values[i][j] = cofactor(matrix, i, j);
			j++;
		}
		i++;
	}
	return (cofactor_matrix);
}

void	scale_matrix(t_matrix *matrix, double scalar)
{
	int		i;
	int		j;

	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->cols)
		{
			matrix->values[i][j] *= scalar;
			j++;
		}
		i++;
	}
}

/*
** NOTE:
** This function used to modify the input matrix by
** setting its `det` and `is_invertible` fields.
** That caused serious side effects when the matrix
** was part of shared data (e.g., pattern->transform),
** leading to undefined behavior, invalid writes, and
** segmentation faults during rendering.
**
** To avoid side effects, this version of `invertable()`
** is now read-only and purely checks
** whether the matrix is invertible based on its
** determinant, without altering the input.
*/
bool	invertable(t_matrix *matrix)
{
	if (matrix->rows != matrix->cols)
		return (false);
	return (determinant(matrix) != 0);
}

t_matrix	*invert_matrix(t_matrix *matrix)
{
	t_matrix	*cofactor_matrix;
	t_matrix	*inverse;
	double		d;

	d = determinant(matrix);
	if (fabs(d) < EPSILON)
		return (NULL);
	cofactor_matrix = compute_cofactor_matrix(matrix);
	if (!cofactor_matrix)
		return (NULL);
	inverse = transpose_matrix(cofactor_matrix);
	free_matrix(cofactor_matrix);
	if (!inverse)
		return (NULL);
	scale_matrix(inverse, 1.0 / d);
	return (inverse);
}

// int	main()
// {
// 	//main to test matrix inversion
// 	t_matrix	*a;
// 	t_matrix	*inverse;

// 	printf("Enter size of square matrix A: ");
// 	int size;
// 	scanf("%d", &size);
// 	if (size < 2)
// 	{
// 		printf("Error: Matrix must be at least 2x2.\n");
// 		return (1);
// 	}
// 	a = create_matrix(size, size, 0);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a);

// 	invertable(a);
// 	if (!a->is_invertible)
// 	{
// 		printf("\nMatrix A is not invertible (determinant is 0).\n");
// 		free_matrix(a);
// 		return (1);
// 	}

// 	inverse = invert_matrix(a);
// 	if (!inverse)
// 	{
// 		printf("\nError: Could not compute inverse.\n");
// 		free_matrix(a);
// 		return (1);
// 	}

// 	printf("\nInverse of A:\n");
// 	print_matrix(inverse);
// 	free_matrix(a);
// 	free_matrix(inverse);
// 	return (0);
// }

// int	main()
// {
// 	//main to test matrix multiplication and inversion check
// 	t_matrix	*a;
// 	t_matrix	*b;
// 	t_matrix	*c;
// 	t_matrix	*inv_b;
// 	t_matrix	*result;

// 	printf("Creating 4x4 matrices A and B...\n");
// 	a = create_matrix(4, 4, 0);
// 	b = create_matrix(4, 4, 0);

// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a);
// 	printf("\nFill matrix B:\n");
// 	fill_matrix(b);

// 	printf("\nMatrix A:\n");
// 	print_matrix(a);
// 	printf("\nMatrix B:\n");
// 	print_matrix(b);

// 	// Step 1: Compute C = A * B
// 	c = multiply_matrices(a, b);
// 	if (!c)
// 	{
// 		printf("\nError: A * B could not be computed.\n");
// 		free_matrix(a);
// 		free_matrix(b);
// 		return (1);
// 	}
// 	printf("\nMatrix C (A * B):\n");
// 	print_matrix(c);

// 	// Step 2: Compute inverse(B)
// 	invertable(b);
// 	if (!b->is_invertible)
// 	{
// 		printf("\nMatrix B is not invertible.\n");
// 		free_matrix(a);
// 		free_matrix(b);
// 		free_matrix(c);
// 		return (1);
// 	}

// 	inv_b = invert_matrix(b);
// 	if (!inv_b)
// 	{
// 		printf("\nError: Could not compute inverse(B).\n");
// 		free_matrix(a);
// 		free_matrix(b);
// 		free_matrix(c);
// 		return (1);
// 	}
// 	printf("\nInverse of B:\n");
// 	print_matrix(inv_b);

// 	// Step 3: Compute result = C * inverse(B)
// 	result = multiply_matrices(c, inv_b);
// 	if (!result)
// 	{
// 		printf("\nError: C * inverse(B) could not be computed.\n");
// 		free_matrix(a);
// 		free_matrix(b);
// 		free_matrix(c);
// 		free_matrix(inv_b);
// 		return (1);
// 	}
// 	printf("\nMatrix C * inverse(B):\n");
// 	print_matrix(result);

// 	// Step 4: Check if result == A
// 	if (equal_matrix(result, a))
// 		printf("\n✅ C * inverse(B) is equal to A.\n");
// 	else
// 		printf("\n❌ C * inverse(B) is NOT equal to A.\n");

// 	// Free all matrices
// 	free_matrix(a);
// 	free_matrix(b);
// 	free_matrix(c);
// 	free_matrix(inv_b);
// 	free_matrix(result);
// 	return (0);
// }
