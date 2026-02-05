/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray_for_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:35:22 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:37:41 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	ray_for_pixel_test(int run)
// {
// 	if (!run)
// 		return (0);
// 	int i = 1;
// 	t_camera	c;
// 	t_ray		*ray;
// 	t_ray		*expected;

// // TEST 1
// 	//print banners
// 	print_test_banner("Constructing a ray through the centre of the canvas");
// 	print_test_number(&i);
// 	//define variables
// 	c = ft_camera(201, 101, 90);
// 	expected = ft_ray(ft_tuple(0, 0, 0, POINT), ft_tuple(0, 0, -1, VECTOR));
// 	//run test
// 	ray = ray_for_pixel(c, 100, 50);
// 	//print output
// 	printf(B_B
// "ray.origin: (%.2f, %.2f, %.2f)\n"G_B"expected: (%.2f, %.2f, %.2f)\n\n"RES,
// 		ray->origin.x, ray->origin.y, ray->origin.z,
// 		expected->origin.x, expected->origin.y, expected->origin.z);
// 	printf(B_B
// "ray.direction: (%.2f, %.2f, %.2f)\n"G_B"expected: (%.2f, %.2f, %.2f)\n"RES,
// 		ray->direction.x, ray->direction.y, ray->direction.z,
// 		expected->direction.x, expected->direction.y, expected->direction.z);
// 	//check output
// 	if (equal_tuple(ray->origin, expected->origin))
// 		printf(GR"✔ origin matches\n"RES);
// 	else
// 		return(printf(AKA"❌ origin doesn't match\n"RES));
// 	if (equal_tuple(ray->direction, expected->direction))
// 		printf(GR"✔ direction matches\n"RES);
// 	else
// 		return(printf(AKA"❌ direction doesn't match\n"RES));
// 	//free memory
// 	free_ray(ray);
// 	free_ray(expected);
// // TEST 2
// 	//print banners
// 	print_test_banner("Constructing a ray through a corner of the canvas");
// 	print_test_number(&i);
// 	//define variables
// 	expected = ft_ray(ft_tuple(0, 0, 0, POINT),
		// ft_tuple(0.66519, 0.33259, -0.66851, VECTOR));
// 	//run test
// 	ray = ray_for_pixel(c, 0, 0);
// 	//print output
// 	printf(B_B
// "ray.origin: (%.5f, %.5f, %.5f)\n"G_B"expected: (%.5f, %.5f, %.5f)\n\n"RES,
// 		ray->origin.x, ray->origin.y, ray->origin.z,
// 		expected->origin.x, expected->origin.y, expected->origin.z);
// 	printf(B_B
// "ray.direction:(%.5f, %.5f, %.5f)\n"G_B"expected: (%.5f, %.5f, %.5f)\n"RES,
// 		ray->direction.x, ray->direction.y, ray->direction.z,
// 		expected->direction.x, expected->direction.y, expected->direction.z);
// 	//check output
// 	if (equal_tuple(ray->origin, expected->origin))
// 		printf(GR"✔ origin matches\n"RES);
// 	else
// 		return(printf(AKA"❌ origin doesn't match\n"RES));
// 	if (equal_tuple(ray->direction, expected->direction))
// 		printf(GR"✔ direction matches\n"RES);
// 	else
// 		return(printf(AKA"❌ direction doesn't match\n"RES));
// 	//free memory
// 	free_ray(ray);
// 	free_ray(expected);
// // TEST 3
// 	//print banners
// 	print_test_banner("Constructing a ray when the camera is transformed");
// 	print_test_number(&i);
// 	//define variables
// 	t_matrix	*transf = multiply_matrices(rotate_y(M_PI/4),
							// translate(0, -2, 5));
// 	free_matrix(c.transf);
// 	c.transf = transf;
// 	expected = ft_ray(ft_tuple(0, 2, -5, POINT),
			// ft_tuple(sqrt(2)/2, 0, -sqrt(2)/2, VECTOR));
// 	//run test
// 	ray = ray_for_pixel(c, 100, 50);
// 	//print output
// 	printf(B_B
// "ray.origin: (%.0f, %.0f, %.0f)\n"G_B"expected: (%.0f, %.0f, %.0f)\n\n"RES,
// 		ray->origin.x, ray->origin.y, ray->origin.z,
// 		expected->origin.x, expected->origin.y, expected->origin.z);
// 	printf(B_B
// "ray.direction: (%.5f, %.5f, %.5f)\n"G_B"expected: (%.5f, %.5f, %.5f)\n"RES,
// 		ray->direction.x, ray->direction.y, ray->direction.z,
// 		expected->direction.x, expected->direction.y, expected->direction.z);
// 	//check output
// 	if (equal_tuple(ray->origin, expected->origin))
// 		printf(GR"✔ origin matches\n"RES);
// 	else
// 		return(printf(AKA"❌ origin doesn't match\n"RES));
// 	if (equal_tuple(ray->direction, expected->direction))
// 		printf(GR"✔ direction matches\n"RES);
// 	else
// 		return(printf(AKA"❌ direction doesn't match\n"RES));
// 	return (0);
// }
