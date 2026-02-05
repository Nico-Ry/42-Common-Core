/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shadows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:54:38 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:55:14 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// int	shadows_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int			i = 1;
// 	t_shading	L;
// 	t_colour	result;
// 	t_colour	expected;
// 	t_world		*w;
// 	t_tuple		p;
// 	bool		in_shadow;

// 	// TEST 1
// 	print_test_banner("Lighting with the surface in shadow");
// 	print_test_number(&i);
// 	L.eyev = ft_tuple(0, 0, -1, VECTOR);
// 	L.normalv = ft_tuple(0, 0, -1, VECTOR);
// 	L.l = ft_light(ft_tuple(0, 0, -10, POINT), ft_colour(1, 1, 1), 1.0);
// 	L.m = ft_material();
// 	L.point = ft_tuple(0, 0, 0, POINT);
// 	expected = ft_colour(0.1, 0.1, 0.1);
// 	result = ft_shading(L, true);
// 	printf(B_B"result:   (%.1f, %.1f, %.1f)\n"RES"",
	// result.r, result.g, result.b);
// 	printf(G_B"expected: (%.1f, %.1f, %.1f)\n"RES"",
	// expected.r, expected.g, expected.b);
// 	if (equal_colour(result, expected))
// 		printf(GR"✔ result matches expected\n"RES);
// 	else
// 		return (printf(AKA"❌ result doesn't match expected\n"RES));
// 	free(L.l);

// 	// TEST 2
// 	print_test_banner(
	// "No shadow when nothing is colinear with point and light");
// 	print_test_number(&i);
// 	w = default_world();
// 	p = ft_tuple(0, 10, 0, POINT);
// 	in_shadow = is_shadowed(w, p, w->lights[0]);
// 	if (in_shadow == false)
// 		printf(GR"✔ point is not in shadow\n"RES);
// 	else
// 		return (printf(AKA"❌ point is in shadow\n"RES));

// 	// TEST 3
// 	print_test_banner("Shadow when an object is between point and light");
// 	print_test_number(&i);
// 	p = ft_tuple(10, -10, 10, POINT);
// 	in_shadow = is_shadowed(w, p, w->lights[0]);
// 	if (in_shadow == true)
// 		printf(GR"✔ point is in shadow\n"RES);
// 	else
// 		return (printf(AKA"❌ point is not in shadow\n"RES));

// 	// TEST 4
// 	print_test_banner("No shadow when an object is behind the light");
// 	print_test_number(&i);
// 	p = ft_tuple(-20, 20, -20, POINT);
// 	in_shadow = is_shadowed(w, p, w->lights[0]);
// 	if (in_shadow == false)
// 		printf(GR"✔ point is not in shadow\n"RES);
// 	else
// 		return (printf(AKA"❌ point is in shadow\n"RES));

// 	// TEST 5
// 	print_test_banner("No shadow when an object is behind the point");
// 	print_test_number(&i);
// 	p = ft_tuple(-2, 2, -2, POINT);
// 	in_shadow = is_shadowed(w, p, w->lights[0]);
// 	if (in_shadow == false)
// 		printf(GR"✔ point is not in shadow\n"RES);
// 	else
// 		return (printf(AKA"❌ point is in shadow\n"RES));

// 	free_world(w);
// 	return (0);
// }
