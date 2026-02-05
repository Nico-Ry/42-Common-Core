/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:41:37 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 17:47:15 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tests.h"
#include "engine.h"

// int	list_size(t_hitlist *xs);
// int	equal_double(double a, double b);
// void	free_cone(t_cone *cone); // We’ll define this just below

// int	cone_intersection_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	int i = 1;
// 	t_cone *cone;
// 	t_ray *r;
// 	t_tuple origin, direction;
// 	t_hitlist *xs;

// 	print_test_banner("Intersecting a cone with a ray");
// 	print_test_number(&i);

// 	#define TEST_CONE_INTERSECT_2(O, D, T0, T1, LABEL) {
// 		cone = ft_cone();
// 		origin = O;
// 		direction = D;
// 		direction = normalize(direction);
// 		r = ft_ray(origin, direction);
// 		xs = NULL;
// 		intersect_cone((t_object *)cone, r, &xs);
// 		printf("→ %s\n", LABEL);
// 		if (list_size(xs) != 2) {
// 			printf("❌ Expected 2 hits, got %d\n\n", list_size(xs));
// 			return (1);
// 		}
// 		printf("  Expected t0 = %.5f, got %.5f\n", (double)(T0), xs->hit->t);
// 		if (!equal_double(xs->hit->t, T0))
			// return (printf(AKA"❌ Failed at t0\n"RES));
// 		printf("Expected t1 = %.5f,got %.5f\n",(double)(T1),xs->next->hit->t);
// 		if (!equal_double(xs->next->hit->t, T1))
			// return (printf(AKA"❌ Failed at t1\n"RES));
// 		printf(GR"✔ Passed\n\n"RES);
// 		free_ray(r); free_cone(cone); free_hitlist(&xs);
// 	}

// 	TEST_CONE_INTERSECT_2(ft_tuple(0, 0, -5, POINT),
	// ft_tuple(0, 0, 1, VECTOR), 5, 5, "Ray hits cone straight");
// 	TEST_CONE_INTERSECT_2(ft_tuple(0, 0, -5, POINT),
	// ft_tuple(1, 1, 1, VECTOR), 8.66025, 8.66025, "Ray hits cone diagonally");
// 	TEST_CONE_INTERSECT_2(ft_tuple(1, 1, -5, POINT),
// ft_tuple(-0.5, -1, 1, VECTOR), 4.55006, 49.44994, "Ray hits from the side");

// 	print_test_banner("Ray parallel to cone’s side");
// 	print_test_number(&i);

// 	cone = ft_cone();
// 	origin = ft_tuple(0, 0, -1, POINT);
// 	direction = normalize(ft_tuple(0, 1, 1, VECTOR));
// 	r = ft_ray(origin, direction);
// 	xs = NULL;
// 	intersect_cone((t_object *)cone, r, &xs);

// 	printf("→ Parallel ray test\n");
// 	if (list_size(xs) != 1)
// 	{
// 		printf("❌ Expected 1 hit, got %d\n\n", list_size(xs));
// 		return (1);
// 	}
// 	printf("  Expected t = 0.35355, got %.5f\n", xs->hit->t);
// 	if (!equal_double(xs->hit->t, 0.35355))
// 		return (printf(AKA"❌ Failed at t\n"RES));
// 	printf(GR"✔ Passed\n\n"RES);

// 	free_ray(r);
// 	free_cone(cone);
// 	free_hitlist(&xs);
// 	return (0);
// }

// int	list_size(t_hitlist *xs)
// {
// 	int count = 0;
// 	while (xs)
// 	{
// 		count++;
// 		xs = xs->next;
// 	}
// 	return (count);
// }
// int	equal_double(double a, double b)
// {
// 	return (fabs(a - b) < 1e-4);
// }

// int	cone_cap_intersection_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	int i = 1;
// 	t_cone *cone;
// 	t_ray *r;
// 	t_tuple origin, direction;
// 	t_hitlist *xs;
// 	int actual_count;

// 	print_test_banner("Intersecting a cone's end caps");
// 	print_test_number(&i);

// 	#define TEST_CONE_CAP(O, D, EXPECTED_COUNT, LABEL) {
// 		cone = ft_cone();
// 		cone->min = -0.5;
// 		cone->max = 0.5;
// 		cone->closed = true;
// 		origin = O;
// 		direction = normalize(D);
// 		printf("  Using direction = (%.5f, %.5f, %.5f)\n",
			// direction.x, direction.y, direction.z);
// 		r = ft_ray(origin, direction);
// 		xs = NULL;
// 		intersect_cone((t_object *)cone, r, &xs);
// 		printf("→ %s\n", LABEL);
// 		/* Analyze all hits and label them */
// 		actual_count = 0;
// 		t_hitlist *tmp = xs;
// 		int k = 0;
// 		while (tmp) {
// 			t_hit *hit = tmp->hit;
// 			t_tuple p = get_point(r, hit->t);
// 			const char *label = NULL;
// 			if (hit->t < 0)
// 				label = "PAST HIT";
// 			else if (fabs(p.y - cone->min) < EPSILON ||
					// fabs(p.y - cone->max) < EPSILON) {
// 				label = "CAP HIT";
// 				actual_count++;
// 			} else
// 				label = "SIDE HIT";
// 			printf("HIT %d:t = %.5f→%s(y=%.5f)\n",k++,hit->t,label,p.y);
// 			tmp = tmp->next;
// 		}
// 		printf("  Expected hit count: %d\n", EXPECTED_COUNT);
// 		printf("  Actual hit count:   %d\n", actual_count);
// 		if (actual_count != EXPECTED_COUNT)
// 			return (printf(AKA"❌ Failed\n\n"RES));
// 		printf(GR"✔ Passed\n\n"RES);
// 		free_ray(r); free_cone(cone); free_hitlist(&xs);
// 	}
// 	printf("First test ##################\n");
// 	TEST_CONE_CAP(ft_tuple(0, 0, -5, POINT),
	// ft_tuple(0, 1, 0, VECTOR), 0,
		// "Ray misses end caps (too far away)");
// 	printf("Second test #######################\n");
// 	TEST_CONE_CAP(ft_tuple(0, 1, 0, POINT),
	// ft_tuple(0, -1, 0, VECTOR), 2,
		// "Ray goes vertically through both end caps");
// 	printf("Third test ####################\n");
// 	TEST_CONE_CAP(ft_tuple(0, -1, 0, POINT),
	// ft_tuple(0, 1, 0, VECTOR), 2,
		// "Ray goes vertically through both end caps (reversed)");
// 	printf("Fourth test ###################\n");
// 	TEST_CONE_CAP(ft_tuple(0, 0, -0.25, POINT),
	// ft_tuple(0, 1, 0, VECTOR), 1, "Ray intersects upper cap vertically");

// 	return (0);
// }

// int	cone_normal_vector_test(int run)
// {
// 	if (run == 0)
// 		return (0);

// 	int i = 1;
// 	t_cone *cone = ft_cone();
// 	t_tuple p, expected, actual;
// 	double sqrt2 = sqrt(2);

// 	print_test_banner("Computing the normal vector on a cone");
// 	print_test_number(&i);

// 	#define TEST_CONE_NORMAL(P, N, LABEL) {
// 		p = P;
// 		if (N.x == 0 && N.y == 0 && N.z == 0)
// 			expected = N;
// 		else
// 			expected = normalize(N);
// 		actual = normal_at_cone((t_object *)cone, p);
// 		printf("→ %s\n", LABEL);
// 		printf("  Point:   (%.2f, %.2f, %.2f)\n", p.x, p.y, p.z);
// 		printf("  Normal:  (%.5f, %.5f, %.5f)\n",
			// actual.x, actual.y, actual.z);
// 		printf("  Expect:  (%.5f, %.5f, %.5f)\n",
			// expected.x, expected.y, expected.z);
// 		if (!equal_double(actual.x, expected.x) ||
		// !equal_double(actual.y, expected.y) ||
				// !equal_double(actual.z, expected.z))
// 			return (printf(AKA"❌ Failed\n\n"RES));
// 		printf(GR"✔ Passed\n\n"RES);
// 	}

// 	TEST_CONE_NORMAL(ft_tuple(0, 0, 0, POINT),
		// ft_tuple(0, 0, 0, VECTOR), "Undefined normal at the tip (0,0,0)");
// 	TEST_CONE_NORMAL(ft_tuple(1, 1, 1, POINT),
			// ft_tuple(1, -sqrt2, 1, VECTOR), "Point on side (1,1,1)");
// 	TEST_CONE_NORMAL(ft_tuple(-1, -1, 0, POINT),
		// ft_tuple(-1, 1, 0, VECTOR), "Point on side (-1,-1,0)");

// 	free_cone(cone);
// 	return (0);
// }
