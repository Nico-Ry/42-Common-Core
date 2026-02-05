/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:02:04 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:02:56 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	zero_matrix_row(double *row, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		row[i] = 0.0;
		i++;
	}
}

t_matrix	*create_matrix(int rows, int cols, int is_tuple)
{
	t_matrix	*matrix;
	int			i;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (!matrix)
		exit(1);
	matrix->rows = rows;
	matrix->cols = cols;
	matrix->is_tuple = is_tuple;
	matrix->is_identity = 0;
	matrix->values = (double **)malloc(rows * sizeof(double *));
	if (!matrix->values)
		exit(1);
	i = 0;
	while (i < rows)
	{
		matrix->values[i] = (double *)malloc(cols * sizeof(double));
		if (!matrix->values[i])
			exit(1);
		zero_matrix_row(matrix->values[i], cols);
		i++;
	}
	return (matrix);
}

t_matrix	*submatrix(t_matrix *matrix, int remove_row, int remove_col)
{
	t_matrix	*result;

	if (matrix->rows < 2 || matrix->cols < 2)
	{
		printf("Error:not valid matrix smaller than 2x2.\n");
		return (NULL);
	}
	result = create_matrix(matrix->rows - 1, matrix->cols - 1, 0);
	fill_submatrix(matrix, result, remove_row, remove_col);
	return (result);
}

void	fill_submatrix(t_matrix *matrix, t_matrix *sub,
	int ignore_row, int ignore_col)
{
	int	i;
	int	j;
	int	sub_i;
	int	sub_j;

	sub_i = 0;
	i = 0;
	while (i < matrix->rows)
	{
		if (i == ignore_row)
		{
			i++;
			continue ;
		}
		sub_j = 0;
		j = 0;
		while (j < matrix->cols)
		{
			if (j != ignore_col)
				sub->values[sub_i][sub_j++] = matrix->values[i][j];
			j++;
		}
		sub_i++;
		i++;
	}
}

t_matrix	*create_identity_matrix(int size)
{
	int			i;
	int			j;
	t_matrix	*identity;

	identity = create_matrix(size, size, 0);
	if (!identity || !identity->values)
		exit(1);
	identity->is_identity = 1;
	identity->is_invertible = 1;
	identity->det = 1.0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				identity->values[i][j] = 1.0;
			else
				identity->values[i][j] = 0.0;
			j++;
		}
		i++;
	}
	return (identity);
}
