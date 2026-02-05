/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:58:32 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:00:55 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// void	print_normal(t_tuple tuple, t_tuple expected, t_obj type)

// {
// 	if ((type == PLANE || type == CYLINDER) && tuple.w == 0)
// 	{
// 		printf(B_B"normal:   (%.0f, %.0f, %.0f)\n"RES,
			// tuple.x, tuple.y, tuple.z);
// 		printf(G_B"expected: (%.0f, %.0f, %.0f)\n"RES,
			// expected.x, expected.y, expected.z);
// 	}
// 	else if (type == SPHERE && tuple.w == 0)
// 	{
// 		printf(B_B"normal:   (%.5f, %.5f, %.5f)\n"RES,
			// tuple.x, tuple.y, tuple.z);
// 		printf(G_B"expected: (%.5f, %.5f, %.5f)\n"RES,
			// expected.x, expected.y, expected.z);
// 	}
// 	else
// 	{
// 		printf(R_B"ERROR:"RES" normal is a point\n");
// 		return ;
// 	}
// }

// void	print_reflected(t_tuple tuple, t_tuple expected)
// {
// 	if (tuple.w == 0)
// 	{
// 		printf(BOLD"reflected: (%.0f, %.5f, %.5f)\n"RES,
			// tuple.x, tuple.y, tuple.z);
// 		printf(G_B"expected:(%.0f, %.5f, %.5f)\n"RES,
			// expected.x, expected.y, expected.z);
// 	}
// 	else
// 	{
// 		printf(R_B"ERROR:"RES" normal is a point\n");
// 		return ;
// 	}
// }

// void	print_light(t_light *l, char *name)
// {
// 	if (l)
// 		printf(YEL"%s:\n"RES, name);
// 	else
// 		printf(R_B"ERROR:"RES" %s undefined\n", name);
// 	printf(G_B"\tLUM:\n"RES);
// 	printf(YEL"\tr:"RES" %.5f\n", l->lum.r);
// 	printf(YEL"\tg:"RES" %.5f\n", l->lum.g);
// 	printf(YEL"\tb:"RES" %.5f\n", l->lum.b);
// 	printf("\t");
// 	print_tuple(l->pos, "POS:");
// }

// void	print_material(t_material m)
// {
// 	printf(G_B"Material:\n"RES);
// 	printf(YEL"\tr:"RES" %.1f\n", m.c.r);
// 	printf(YEL"\tg:"RES" %.1f\n", m.c.g);
// 	printf(YEL"\tb:"RES" %.1f\n", m.c.b);
// 	printf(YEL"\tambient:"RES" %.1f\n", m.ambient);
// 	printf(YEL"\tdiffuse:"RES" %.1f\n", m.diffuse);
// 	printf(YEL"\tspecular:"RES" %.1f\n", m.specular);
// 	printf(YEL"\tshininess:"RES" %.1f\n", m.shininess);
// }

// int	equal_material(t_material m, t_material expected)
// {
// 	if (equal_colour(m.c, expected.c) &&
// 		ft_equal(m.ambient, expected.ambient) &&
// 		ft_equal(m.diffuse, expected.diffuse) &&
// 		ft_equal(m.specular, expected.specular) &&
// 		ft_equal(m.shininess, expected.shininess))
// 		return (1);
// 	else
// 		return (0);
// }

// int	equal_colour(t_colour c1, t_colour c2)
// {
// 	if (ft_equal(c1.r, c2.r) && ft_equal(c1.g, c2.g) && ft_equal(c1.b, c2.b))
// 		return (1);
// 	else
// 		return (0);
// }

// int		printable_material(t_material m)
// {
// 	if (m.ambient && m.diffuse && m.specular && m.shininess)
// 		{
// 		printf(G_B"Material:\n"RES);
// 		return (1);
// 		}
// 	else
// 	{
// 			printf(G_B"Material:\n"RES);
// 			if (!m.ambient)
// 				printf(YEL"\tmaterial ambient "AKA"undefined\n");
// 			if (!m.diffuse)
// 				printf(YEL"\tmaterial diffuse "AKA"undefined\n");
// 			if (!m.specular)
// 				printf(YEL"\tmaterial specular "AKA"undefined\n");
// 			if (!m.shininess)
// 				printf(YEL"\tmaterial shininess "AKA"undefined\n");
// 	}
// 	return (0);
// }

// void	print_matrix(t_matrix *matrix)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	if (!matrix)
// 	{
// 		printf(YEL"Matrix is Null\n");
// 		return;
// 	}
// 	if (matrix->cols == 4)
// 		printf(" -----------------------------------\n");
// 	while (i < matrix->rows)
// 	{
// 		printf("|");
// 		j = 0;
// 		while (j < matrix->cols)
// 		{
// 			if (matrix->values[i][j] == (int)matrix->values[i][j])
// 				printf(" %6.0f |", matrix->values[i][j]);
// 			else
// 				printf(" %10.5f |", matrix->values[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	if (matrix->cols == 4)
// 		printf(" -----------------------------------\n");
// }

// void	print_test_banner(const char *word)
// {
// 	int total_width = 62;  // Adjust if needed
// 	int word_length = ft_strlen(word);
// 	int padding = (total_width - word_length - 4) / 2;
// 	int extra = (total_width - word_length - 4) % 2;

// 	printf(B_B"########################\n");
// 	printf("#%*s%s%*s#\n", padding, "", word, padding + extra, "");
// 	printf("##################\n"RES);
// }

// // void	print_test_number(int *i)
// // {
// // 	printf(CYAN"##### TEST %d #####\n"RES, (*i)++);
// // }
// void	print_test_number(int *i)
// {
// 	int total_width = 57;  // Adjust if needed
// 	int word_length = 1;
// 	int padding = (total_width - word_length - 4) / 2;
// 	int extra = (total_width - word_length - 4) % 2;
// 	char *word = "TEST";

// 	printf(C_B"%*s%s %d%*s \n"RES, padding, ""
		// word, (*i)++, padding + extra, "");
// }

// void	print_sub_header(const char *word, int *i)
// {
// 	int total_width = 62;  // Adjust if needed
// 	int word_length = strlen(word);
// 	int padding = (total_width - word_length - 4) / 2;
// 	int extra = (total_width - word_length - 4) % 2;

// 	if (*i != 0)
// 		print_test_number(i);
// 	printf(CYAN"#%*s%s%*s#\n"RES, padding, "", word, padding + extra, "");
// }

// void	print_intersections(t_hit **xs, int count, int sorted)
// {
// 	int	i = 0;

// 	if (count == 0)
// 	{
// 		printf(YEL"No intersections or intersections are NULL\n"RES);
// 		return ;
// 	}
// 	if (sorted)
// 		printf(BOLD"%15s\n"RES, "Sorted Array:");
// 	else
// 		printf(BOLD"%17s\n"RES, "Unsorted Array:");
// 	while (i < count)
// 	{
// 		printf(BOLD"%12s "LILA"%1.0f "RES""BOLD"%1s\n"RES, "|", xs[i]->t, "|");
// 		i++;
// 	}
// 	printf(BOLD"_________________________________\n\n"RES);
// }

// void	print_hitlist(t_hitlist **xs)
// {
// 	t_hitlist	*current;

// 	if (!xs || !*xs)
// 	{
// 		printf(YEL"Hitlist is NULL\n");
// 		return ;
// 	}
// 	current = *xs;
// 	while (current)
// 	{
// 		printf(G_B"%6s "GR"%7.1f\n"RES, "hit:", current->hit->t);
// 		current = current->next;
// 	}
// }

//##############################################################//
//######################## OBSOLETE ###########################//
//##############################################################//

/*
void	print_rs(t_ray_sphere *rs)
{
	// printf(G_B"x_count:"RES" %d\n", rs->x_count);
	printf(G_B"tc:"RES" %f\n", rs->tc);
	print_tuple(rs->l, "rs->l");
	printf(G_B"l_len:"RES"\t%f\n", rs->l_len);
	printf(G_B"d:"RES" %f\n", rs->d);
	printf(G_B"offset:"RES" %f\n", rs->offset);
} */
