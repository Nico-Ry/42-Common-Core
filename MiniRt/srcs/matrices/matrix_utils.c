/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:04:48 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:06:47 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	equal_matrix(t_matrix *a, t_matrix *b)
{
	int		i;
	int		j;

	if (a->rows != b->rows || a->cols != b->cols)
	{
		return (0);
	}
	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < a->cols)
		{
			if (!ft_equal(a->values[i][j], b->values[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	compute_product_matrix(t_matrix *a, t_matrix *b, t_matrix *result)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < b->cols)
		{
			result->values[i][j] = 0;
			k = 0;
			while (k < a->cols)
			{
				result->values[i][j] += a->values[i][k] * b->values[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

t_matrix	*multiply_matrices(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;

	if (a->cols != b->rows)
	{
		printf("Error: Matrices cannot be multiplied (A columns != B rows)\n");
		return (NULL);
	}
	result = create_matrix(a->rows, b->cols, 0);
	compute_product_matrix(a, b, result);
	if (!result)
	{
		printf("❌ Failed to allocate result matrix\n");
		exit(1);
	}
	return (result);
}

t_matrix	*multiply_and_free(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;

	if (a->cols != b->rows)
	{
		printf("Error: Matrices cannot be multiplied (A columns != B rows)\n");
		return (NULL);
	}
	result = create_matrix(a->rows, b->cols, 0);
	if (!result)
	{
		printf("❌ Failed to allocate result matrix\n");
		exit(1);
	}
	compute_product_matrix(a, b, result);
	free_matrix(a);
	free_matrix(b);
	return (result);
}

t_matrix	*transpose_matrix(t_matrix *input)
{
	int			i;
	int			j;
	t_matrix	*transposed;

	transposed = create_matrix(input->cols, input->rows, input->is_tuple);
	i = 0;
	while (i < input->rows)
	{
		j = 0;
		while (j < input->cols)
		{
			transposed->values[j][i] = input->values[i][j];
			j++;
		}
		i++;
	}
	return (transposed);
}
// t_matrix	*multiply_by_identity(t_matrix *input)
// {
// 	int			i;
// 	t_matrix	*result;
// 	t_matrix	*identity;

// 	if (input->is_tuple == 1)
// 	{
// 		result = create_matrix(1, input->cols, 1);
// 		i = 0;
// 		while (i < input->cols)
// 		{
// 			result->values[0][i] = input->values[0][i];
// 			i++;
// 		}
// 		return (result);
// 	}
// 	identity = create_identity_matrix(input->rows);
// 	result = multiply_matrices(input, identity);
// 	free_matrix(identity);
// 	return (result);
// }

// int	main()
// {
// 	t_matrix	*a;
// 	t_matrix	*b;
// 	int			result;

// 	a = create_matrix(3, 3, 0);
// 	b = create_matrix(3, 3, 0);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a);
// 	printf("\nFill matrix B:\n");
// 	fill_matrix(b);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a);
// 	printf("\nMatrix B:\n");
// 	print_matrix(b);
// 	result = equal_matrix(a, b);
// 	if (result == 1)
// 		printf("\nMatrices are equal.\n");
// 	else
// 		printf("\nMatrices are NOT equal.\n");
// 	free_matrix(a);
// 	free_matrix(b);
// 	return (0);
// }
