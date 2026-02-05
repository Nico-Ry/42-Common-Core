/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:26:32 by nryser            #+#    #+#             */
/*   Updated: 2025/02/24 20:26:32 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

double	minor(t_matrix *matrix, int row, int col)
{
	t_matrix	*sub;
	double		det;

	if (matrix->rows < 2 || matrix->cols < 2)
	{
		printf(R_B""X"Cannot compute minor for a matrix smaller than 2x2.\n");
		return (0);
	}
	sub = submatrix(matrix, row, col);
	if (!sub)
		return (0);
	det = determinant(sub);
	free_matrix(sub);
	return (det);
}

double	cofactor(t_matrix *matrix, int row, int col)
{
	double	minor_value;
	double	sign;

	minor_value = minor(matrix, row, col);
	sign = 1;
	if ((row + col) % 2 != 0)
		sign = -1;
	return (sign * minor_value);
}

double	determinant_base_case(t_matrix *matrix)
{
	return ((matrix->values[0][0] * matrix->values[1][1]) -
			(matrix->values[0][1] * matrix->values[1][0]));
}

double	determinant(t_matrix *matrix)
{
	int			col;
	double		det;

	if (matrix->rows != matrix->cols)
	{
		printf(R_B""X""RES);
		printf("Determinant can only be computed for square matrices.\n");
		exit (1);
	}
	if (matrix->rows == 2)
		return (determinant_base_case(matrix));
	det = 0;
	col = 0;
	while (col < matrix->cols)
	{
		det += matrix->values[0][col] * cofactor(matrix, 0, col);
		col++;
	}
	return (det);
}

// int	main()
// {
// 	//main to test invertibility of a square matrix
// 	t_matrix	*a;

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
// 	invertable(a); // ✅ Check if matrix is invertible
// 	free_matrix(a);
// 	printf("Matrix A is %s invertible.\n", a->is_invertible ? "" : "NOT");
// 	return (0);
// }

// int	main()
// {
// 	//main to test determinant any square matrix
// 	t_matrix	*a;
// 	double		det;

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
// 	det = determinant(a);
// 	printf("And determinant(A) = %.0f\n", det);

// 	free_matrix(a);
// 	return (0);
// }

// int	main()
// {

// 	//main to test cofactor
// 	t_matrix	*a;
// 	double		cofactor_value;
// 	int			row, col;

// 	printf("Enter size of square matrix A (must be at least 2x2): ");
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
// 	printf("\nEnter row and column for cofactor calculation: ");
// 	scanf("%d %d", &row, &col);
// 	if (row < 0 || row >= size || col < 0 || col >= size)
// 	{
// 		printf("\nError: Row or column out of bounds.\n");
// 		free_matrix(a);
// 		return (1);
// 	}
// 	cofactor_value = cofactor(a, row, col);
// 	printf("\nCofactor of A at (%d, %d): %.1f\n", row, col, cofactor_value);
// 	free_matrix(a);
// 	return (0);
// }

// int	main()
// {
// 	//main to test minor with 3x3 matrix
// 	t_matrix	*a;
// 	double		minor_value;
// 	int			row, col;

// 	printf("Enter size of square matrix A (must be at least 2x2): ");
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
// 	printf("\nEnter row and column for minor calculation: ");
// 	scanf("%d %d", &row, &col);
// 	if (row < 0 || row >= size || col < 0 || col >= size)
// 	{
// 		printf("\nError: Row or column out of bounds.\n");
// 		free_matrix(a);
// 		return (1);
// 	}
// 	minor_value = minor(a, row, col);
// 	printf("\nMinor of A at (%d, %d): %.1f\n", row, col, minor_value);
// 	free_matrix(a);
// 	return (0);
// }
//
//
// int	main()
// {
// 	//main to test submatrix
// 	t_matrix	*a;
// 	t_matrix	*sub;
// 	int			rows;
// 	int			cols;
// 	int			remove_row;
// 	int			remove_col;

// 	printf("Enter number of rows for matrix A: ");
// 	scanf("%d", &rows);
// 	printf("Enter number of columns for matrix A: ");
// 	scanf("%d", &cols);
// 	a = create_matrix(rows, cols, 0);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a);
// 	if (rows < 2 || cols < 2)
// 	{
// 		printf("\nError: Cannot extract a
// submatrix from a matrix smaller than 2x2.\n");
// 		free_matrix(a);
// 		return (1);
// 	}
// 	printf("\nEnter the row and column to remove: ");
// 	scanf("%d %d", &remove_row, &remove_col);
// 	if (remove_row < 0 || remove_row >= rows
// 			|| remove_col < 0 || remove_col >= cols)
// 	{
// 		printf("\nError: Row or column out of bounds.\n");
// 		free_matrix(a);
// 		return (1);
// 	}
// 	sub = submatrix(a, remove_row, remove_col);
// 	if (sub)
// 	{
// 		printf("\nSubmatrix (without row %d and column %d):\n",
// 			remove_row, remove_col);
// 		print_matrix(sub);
// 		free_matrix(sub);
// 	}
// 	free_matrix(a);
// 	return (0);
// }

/////////////////////////////////////////////////////
// int	main()
// {
// 	//main to test matrix multiplication
// 	int			rows_a;
// 	int			cols_a;
// 	int			cols_b;
// 	t_matrix	*a;
// 	t_matrix	*b;
// 	t_matrix	*result;

// 	printf("Enter number of rows for matrix A: ");
// 	scanf("%d", &rows_a);
// 	printf("Enter number of columns for matrix A (must match rows of B): ");
// 	scanf("%d", &cols_a);
// 	printf("Enter number of columns for matrix B: ");
// 	scanf("%d", &cols_b);
// 	a = create_matrix(rows_a, cols_a, 0);
// 	b = create_matrix(cols_a, cols_b, 0);
// 	printf("\nFill matrix A:\n");
// 	fill_matrix(a);
// 	printf("\nFill matrix B:\n");
// 	fill_matrix(b);
// 	printf("\nMatrix A:\n");
// 	print_matrix(a);
// 	printf("\nMatrix B:\n");
// 	print_matrix(b);
// 	result = multiply_matrices(a, b);
// 	if (result)
// 	{
// 		printf("\nResult of A * B:\n");
// 		print_matrix(result);
// 		free_matrix(result);
// 	}
// 	free_matrix(a);
// 	free_matrix(b);
// 	return (0);
// }
