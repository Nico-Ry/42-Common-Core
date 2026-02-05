/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rodrigues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:36:30 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 20:36:46 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Builds a skew-symmetric matrix from a vector.
 *
 * This function constructs a 4x4 skew-symmetric matrix used in Rodrigues'
 * rotation formula. It encodes the cross product operation for the given vector.
 *
 * @param v The input vector used to build the skew matrix.
 * @return A newly allocated 4x4 skew-symmetric matrix.
 */
t_matrix	*build_skew_matrix(t_tuple v)
{
	t_matrix	*skew;

	skew = create_matrix(4, 4, 0);
	skew->values[0][0] = 0;
	skew->values[0][1] = -v.z;
	skew->values[0][2] = v.y;
	skew->values[1][0] = v.z;
	skew->values[1][1] = 0;
	skew->values[1][2] = -v.x;
	skew->values[2][0] = -v.y;
	skew->values[2][1] = v.x;
	skew->values[2][2] = 0;
	skew->values[3][3] = 1;
	return (skew);
}

/**
 * @brief Handles special cases in rotation matrix computation.
 *
 * This function returns a predefined rotation matrix
 * for the special cases where:
 * - from and to vectors are almost identical (dot product ≈ 1): identity matrix
 * - from and to vectors are nearly opposite (dot product ≈ -1): 180° rotation
 *
 * If the case is not special, it returns NULL.
 *
 * @param c The dot product of the normalized from and to vectors.
 * @param from The original direction vector.
 * @return A special-case rotation matrix or NULL.
 */
static t_matrix	*handle_special_case(double c, t_tuple from)
{
	t_tuple	axis;

	if (fabs(c - 1.0) < EPSILON)
		return (create_identity_matrix(4));
	if (fabs(c + 1.0) < EPSILON)
	{
		axis = cross(from, ft_tuple(1, 0, 0, VECTOR));
		if (magnitude(axis) < EPSILON)
			axis = cross(from, ft_tuple(0, 1, 0, VECTOR));
		axis = normalize(axis);
		return (multiply_matrices(rotate_x(M_PI), rotate_y(M_PI)));
	}
	return (NULL);
}

/**
 * @brief Builds the core rotation matrix using Rodrigues' rotation formula.
 *
 * This function computes the rotation matrix that rotates vector `from` to
 * vector `to`, using the cross product and dot product. Assumes `from` and `to`
 * are already normalized and not in a special case.
 *
 * @param from The normalized starting vector.
 * @param to The normalized target vector.
 * @param c The dot product of from and to.
 * @return A newly allocated rotation matrix.
 */
static t_matrix	*build_rotation_matrix_body(t_tuple from, t_tuple to, double c)
{
	t_tuple		v;
	double		k;
	t_matrix	*skew;
	t_matrix	*skew_sq;
	t_matrix	*result;

	v = cross(from, to);
	skew = build_skew_matrix(v);
	skew_sq = multiply_matrices(skew, skew);
	k = 1.0 / (1.0 + c);
	scale_matrix(skew_sq, k);
	result = add_matrices_free_first(create_identity_matrix(4), skew);
	add_matrices_inplace(result, skew_sq);
	free_matrix(skew);
	free_matrix(skew_sq);
	return (result);
}

/**
 * @brief Computes the rotation matrix from one direction vector to another.
 *
 * This function returns a transformation matrix that rotates `from` to `to`.
 * It handles special cases (parallel and anti-parallel vectors) and otherwise
 * uses Rodrigues' rotation formula for general cases.
 *
 * @param from The starting direction vector.
 * @param to The target direction vector.
 * @return A newly allocated rotation matrix that rotates from → to.
 */
t_matrix	*rotation_matrix(t_tuple from, t_tuple to)
{
	t_matrix	*special;
	double		c;

	from = normalize(from);
	to = normalize(to);
	c = dot(from, to);
	special = handle_special_case(c, from);
	if (special)
		return (special);
	return (build_rotation_matrix_body(from, to, c));
}
