/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:04:15 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 19:04:15 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

void	print_count(t_id_count count)
{
	printf(YEL"[DEBUG]\n"RES);
	printf("A: %d\n", count.a);
	printf("C: %d\n", count.c);
	printf("L: %d\n", count.l);
	printf("SP: %d\n", count.sp);
	printf("PL: %d\n", count.pl);
	printf("CY: %d\n", count.cy);
	printf("CO: %d\n", count.co);
	printf("Total shapes: %d\n", count.total);
}

int	print_pattern_error(int is_cone, char *s)
{
	if (!s || !*s)
	{
		printf(R_B""X""RES"Undefined Pattern\n");
		return (0);
	}
	else if (is_cone)
		printf(AKA""X""RES"Please select pattern between 0-5 for cones\n");
	else
		printf(AKA""X""RES"Please select pattern between 0-7\n");
	return (0);
}

static int	valid_tokens(t_tokens *node, t_id type, bool bonus)
{
	if (type == A)
		return (valid_ambient(node->tokens));
	else if (type == C)
		return (valid_camera(node->tokens));
	else if (type == L)
		return (valid_light(node->tokens, bonus));
	else if (type == SP)
		return (valid_sphere(node->tokens, bonus));
	else if (type == PL)
		return (valid_plane(node->tokens, bonus));
	else if (type == CY)
		return (valid_cylinder(node->tokens, bonus));
	else if (type == CO)
		return (valid_cone(node->tokens, bonus));
	return (0);
}

int	valid_input(t_input *data, bool bonus)
{
	t_tokens	*current;

	if (expected_identifiers(data, data->list, bonus))
		return (-1);
	current = data->list;
	while (current)
	{
		if (!valid_tokens(current, current->type, bonus))
			return (-1);
		current = current->next;
	}
	printf(G_B"✔ "GR"Valid input\n"RES);
	return (0);
}
