/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_ambient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:21:54 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 09:21:54 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	args_count_error(char **tokens, int count, int max)
{
	int	i;

	i = 0;
	if (count > max)
		printf(R_B""X""RES"Too many arguments in line: `");
	else
		printf(R_B""X""RES"Too few arguments in line: `");
	while (i < count - 1)
		printf(AKA"%s    ", tokens[i++]);
	printf("%s"RES"`\n", tokens[i]);
	return (0);
}

int	valid_ambient(char **tokens)
{
	int	count;

	count = count_split(tokens);
	if (count != 3)
		return (args_count_error(tokens, count, 3));
	if (!is_float(tokens[1]) || !valid_light_ratio(tokens[1]))
		return (0);
	if (!is_color(tokens[2]))
		return (0);
	return (1);
}
