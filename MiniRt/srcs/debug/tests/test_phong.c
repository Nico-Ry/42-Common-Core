/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_phong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:29:05 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:31:11 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// //#################################################################//
// ///////////////////////////// LIGHT /////////////////////////////////
// //#################################################################//

// int	light_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	t_colour	lum;
// 	t_tuple		pos;
// 	t_light		*light;
// 	int			i = 1;

// //TEST 1
// 	//print banners
// 	print_test_banner("light has a position and intensity (lum)");
// 	print_test_number(&i);
// 	//initiate variables
// 	lum = ft_colour(1, 1, 1);
// 	pos = ft_tuple(0, 0, 0, POINT);
// 	//run test;
// 	light = ft_light(pos, lum, 1.0);
// 	//print output
// 	print_light(light, "light");
// 	//check output
// 	if (light->lum.r == lum.r && light->lum.g == lum.g && light->lum.b == lum.b)
// 		printf(GR"✔ lum values match\n"RES);
// 	else
// 		return (printf(AKA"❌ lum values don't match\n"RES));
// 	if (equal_tuple(light->pos, pos))
// 		printf(GR"✔ pos values match\n"RES);
// 	else
// 		return (printf(AKA"❌ pos values don't match\n"RES));
// 	return (0);
// }

// //#################################################################//
// //////////////////////////// MATERIAL ///////////////////////////////
// //#################################################################//

// int	material_test(int run)
// {
// 	if (run == 0)
// 	return (0);
// 	int			i = 1;
// 	t_material	m;
// 	t_material	expected;
// 	t_sphere	*sph;

// //TEST 1
// 	//print banners
// 	print_test_banner("Default value of ft_material");
// 	print_test_number(&i);
// 	expected.c = ft_colour(1, 1, 1);
// 	expected.ambient = 0.1;
// 	expected.diffuse = 0.9;
// 	expected.specular = 0.9;
// 	expected.shininess = 200.0;
// 	//run test;
// 	m = ft_material();
// 	//print output
// 	print_material(m);
// 	//check output
// 	if (equal_material(m, expected))
// 		printf(GR"✔ Default material is correct\n"RES);
// 	else
// 		return (printf(AKA"❌ Default material is incorrect\n"RES));

// //TEST 2
// 	//print banners
// 	print_test_banner("Assign default material to sphere");
// 	print_test_number(&i);
// 	//initiate variables
// 	sph = ft_sphere(1);// ft_sphere assigns default material
// 	//print output
// 	printf(B_B"Sphere->m:\n"RES);
// 	print_material(sph->base.m);
// 	//check output
// 	if (equal_material(sph->base.m, expected))
// 		printf(GR"✔ sphere->m matches default material\n"RES);
// 	else
// 		return (printf(AKA"❌ sphere->m doesn't match default material\n"RES));
// 	//free memory
// 	free_sphere(sph);
// //TEST 3
// 	//print banners
// 	print_test_banner("Assign material to sphere");
// 	print_test_number(&i);
// 	//initiate variables
// 	sph = ft_sphere(1);
// 	m = ft_material();
// 	m.ambient = 1;
// 	expected.ambient = 1;
// 	//print run test
// 	sph->base.m = m;
// 	//print output
// 	printf(B_B"Sphere->m:\n"RES);
// 	print_material(sph->base.m);
// 	//check output
// 	if (equal_material(sph->base.m, expected))
// 		printf(GR"✔ sphere->m.ambient == 1\n"RES);
// 	else
// 		return (printf(AKA"❌ sphere->m.ambient != 1\n"RES));
// 	//free memory
// 	free_sphere(sph);
// 	return (0);
// }

// //#################################################################//
// //////////////////////////// SHADING ///////////////////////////////
// //#################################################################//

// int	shading_test(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	int			i = 1;
// 	t_shading	L;
// 	t_colour	result;
// 	t_colour	expected;

// //TEST 1
// 	//print banners
// 	print_test_banner("Eye between light and surface");
// 	print_test_number(&i);
// 	//initiate variables
// 	L.m = ft_material();
// 	L.point = ft_tuple(0, 0, 0, POINT);
// 	L.eyev = ft_tuple(0, 0, -1, VECTOR);
// 	L.normalv = ft_tuple(0, 0, -1, VECTOR);
// 	L.l = ft_light(ft_tuple(0, 0, -10, POINT), ft_colour(1, 1, 1), 1.0);
// 	expected = ft_colour(1.9, 1.9, 1.9);
// 	//run test
// 	result = ft_shading(L, false);
// 	//print output
// 	printf(B_B"result:(%.1f, %.1f, %.1f)\n"RES"",result.r, result.g, result.b);
// 	printf(G_B"expected:(%.1f, %.1f, %.1f)\n"RES"",
			// expected.r,expected.g,expected.b);
// 	//check output
// 	if (equal_colour(result, expected))
// 		printf(GR"✔ result matches expected\n"RES);
// 	else
// 		return (printf(AKA"❌ result doesn't match expected\n"RES));

// //TEST 2
// 	//print banners
// 	print_test_banner("Eye between light and surface, eye offset 45°");
// 	print_test_number(&i);
// 	//redefine variables
// 	double	x = sqrt(2)/2;
// 	L.eyev = ft_tuple(0, x, -x, VECTOR);
// 	expected = ft_colour(1.0, 1.0, 1.0);
// 	//run test
// 	result = ft_shading(L, false);
// 	//print output
// 	printf(B_B"result:   (%.1f, %.1f, %.1f)\n"RES"",
			// result.r, result.g, result.b);
// 	printf(G_B"expected: (%.1f, %.1f, %.1f)\n"RES"",
			// expected.r, expected.g, expected.b);
// 	//check output
// 	if (equal_colour(result, expected))
// 		printf(GR"✔ result matches expected\n"RES);
// 	else
// 		return (printf(AKA"❌ result doesn't match expected\n"RES));

// //TEST 3
// 	//print banners
// 	print_test_banner("Eye opposite surface, light offset 45°");
// 	print_test_number(&i);
// 	//redefine variables
// 	L.eyev = ft_tuple(0, 0, -1, VECTOR);
// 	L.l->pos = ft_tuple(0, 10, -10, POINT);
// 	expected = ft_colour(0.7364, 0.7364, 0.7364);
// 	//run test
// 	result = ft_shading(L, false);
// 	//print output
// 	printf(B_B"result:   (%.4f, %.4f, %.4f)\n"RES"",
			// result.r, result.g, result.b);
// 	printf(G_B"expected: (%.4f, %.4f, %.4f)\n"RES"",
				// expected.r, expected.g, expected.b);
// 	//check output
// 	if (equal_colour(result, expected))
// 		printf(GR"✔ result matches expected\n"RES);
// 	else
// 		return (printf(AKA"❌ result doesn't match expected\n"RES));

// //TEST 4
// 	//print banners
// 	print_test_banner("Eye in path of the reflection vector of light");
// 	print_test_number(&i);
// 	//redefine variables
// 	L.eyev = ft_tuple(0, -x, -x, VECTOR);
// 	expected = ft_colour(1.6364, 1.6364, 1.6364);
// 	//run test
// 	result = ft_shading(L, false);
// 	//print output
// 	printf(B_B"result:   (%.4f, %.4f, %.4f)\n"RES"",
			// result.r, result.g, result.b);
// 	printf(G_B"expected: (%.4f, %.4f, %.4f)\n"RES"",
			// expected.r, expected.g, expected.b);
// 	//check output
// 	if (equal_colour(result, expected))
// 		printf(GR"✔ result matches expected\n"RES);
// 	else
// 		return (printf(AKA"❌ result doesn't match expected\n"RES));

// //TEST 5
// 	//print banners
// 	print_test_banner("Light behind the surface");
// 	print_test_number(&i);
// 	//redefine variables
// 	L.eyev = ft_tuple(0, 0, -1, VECTOR);
// 	L.l->pos = ft_tuple(0, 0, 10, POINT);
// 	expected = ft_colour(0.1, 0.1, 0.1);
// 	//run test
// 	result = ft_shading(L, false);
// 	//print output
// 	printf(B_B"result:   (%.1f, %.1f, %.1f)\n"RES"",
			// result.r, result.g, result.b);
// 	printf(G_B"expected: (%.1f, %.1f, %.1f)\n"RES"",
			// expected.r, expected.g, expected.b);
// 	//check output
// 	if (equal_colour(result, expected))
// 		printf(GR"✔ result matches expected\n"RES);
// 	else
// 		return (printf(AKA"❌ result doesn't match expected\n"RES));
// 	return (0);
// }
