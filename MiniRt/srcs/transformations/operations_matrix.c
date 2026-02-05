/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:52:20 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 20:52:20 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Converts a tuple to a 4x1 matrix representation.
 *
 * This function creates a new matrix where each row corresponds to one
 * component of the tuple. The matrix can be used in vector/matrix operations.
 *
 * @param tup The tuple to convert.
 * @return A dynamically allocated 4x1 matrix representing the tuple.
 */
t_matrix	*tuple_to_matrix(t_tuple tup)
{
	t_matrix	*matrix;

	matrix = create_matrix(4, 1, 1);
	matrix->values[0][0] = tup.x;
	matrix->values[1][0] = tup.y;
	matrix->values[2][0] = tup.z;
	matrix->values[3][0] = tup.w;
	return (matrix);
}

/**
 * @brief Converts a 4x1 matrix back into a tuple.
 *
 * This function extracts each component from the matrix and returns a
 * corresponding tuple. The matrix must be 4x1, where each row holds x, y, z, w.
 *
 * @param matrix The matrix to convert.
 * @return A tuple containing the same components as the matrix.
 */
t_tuple	matrix_to_tuple(t_matrix *matrix)
{
	t_tuple	tuple;
	double	x;
	double	y;
	double	z;

	x = matrix->values[0][0];
	y = matrix->values[1][0];
	z = matrix->values[2][0];
	tuple = ft_tuple(x, y, z, matrix->values[3][0]);
	return (tuple);
}

/**
 * @brief Adds two matrices and returns the result.
 *
 * This function creates a new matrix that holds the element-wise sum
 * of the two input matrices. The input matrices must have the same dimensions.
 *
 * @param a The first matrix operand.
 * @param b The second matrix operand.
 * @return A newly allocated matrix containing the result of a + b.
 */
t_matrix	*add_matrices(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			i;
	int			j;

	result = create_matrix(a->rows, a->cols, 0);
	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < a->cols)
		{
			result->values[i][j] = a->values[i][j] + b->values[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

/**
 * @brief Adds matrix b to matrix a in-place.
 *
 * This function performs an element-wise addition of matrix b into matrix a,
 * modifying matrix a directly. Both matrices must have the same dimensions.
 *
 * @param a The matrix to be modified (accumulator).
 * @param b The matrix to add to matrix a.
 */
void	add_matrices_inplace(t_matrix *a, t_matrix *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < a->cols)
		{
			a->values[i][j] += b->values[i][j];
			j++;
		}
		i++;
	}
}

t_matrix	*add_matrices_free_first(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;

	result = add_matrices(a, b);
	free_matrix(a);
	return (result);
}
