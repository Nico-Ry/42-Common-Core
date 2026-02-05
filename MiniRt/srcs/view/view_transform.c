/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:25:03 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:25:55 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Builds the orientation matrix used by view_transform()
 *
 * @param forward Normalized direction from camera to target
 * @param up Normalized "up" vector
 * @return Matrix that aligns world axes to the camera’s orientation
 */
t_matrix	*orientation_matrix(t_tuple forward, t_tuple up)
{
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	*orientation;

	left = cross(forward, up);
	true_up = cross(left, forward);
	orientation = create_identity_matrix(4);
	orientation->values[0][0] = left.x;
	orientation->values[0][1] = left.y;
	orientation->values[0][2] = left.z;
	orientation->values[1][0] = true_up.x;
	orientation->values[1][1] = true_up.y;
	orientation->values[1][2] = true_up.z;
	orientation->values[2][0] = -forward.x;
	orientation->values[2][1] = -forward.y;
	orientation->values[2][2] = -forward.z;
	return (orientation);
}

/**
 * @brief Computes a safe up vector to avoid singularities in view_transform()
 */
static t_tuple	safe_up(t_tuple forward)
{
	t_tuple	up;

	up = ft_tuple(0, 1, 0, VECTOR);
	if (fabs(dot(forward, up)) > 0.999)
		up = ft_tuple(1, 0, 0, VECTOR);
	return (up);
}

/**
 * @brief Computes a view transformation matrix from camera orientation.
 *
 * @param from Camera position
 * @param to Look-at point
 * @param up Up direction
 * @return The view transformation matrix (to align world to camera)
 */
t_matrix	*view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		upn;
	t_matrix	*orientation;
	t_matrix	*translation;
	t_matrix	*result;

	forward = normalize(diff_tuple(to, from));
	if (fabs(dot(forward, normalize(up))) > 0.999)
	{
		up = safe_up(forward);
		printf(AKA"Up vector was adjusted ,invalid camera orientation\n"RES);
	}
	upn = normalize(up);
	orientation = orientation_matrix(forward, upn);
	translation = translate(-from.x, -from.y, -from.z);
	result = multiply_matrices(orientation, translation);
	free_matrix(orientation);
	free_matrix(translation);
	return (result);
}
