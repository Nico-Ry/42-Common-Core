/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:26:32 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:26:59 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	print_token_line(char **tokens, int count, bool bonus)
{
	int	i;

	i = 0;
	if (!bonus && count > 3)
		printf(R_B""X""RES"Too many arguments in line: `");
	else if (bonus && count > 4)
		printf(R_B""X""RES"Too many arguments in line: `");
	else
		printf(R_B""X""RES"Too few arguments in line: `");
	while (i < count - 1)
		printf(AKA"%s    ", tokens[i++]);
	printf("%s"RES"`\n", tokens[i]);
	return (0);
}

int	valid_light_ratio(char *num)
{
	double	n;

	n = ft_atof(num);
	if (n > 1)
	{
		printf(R_B""X""RES""BRIGHT"[%s "AKA">"RES" 1.0]\n", num);
		return (0);
	}
	else if (n < 0)
	{
		printf(R_B""X""RES""BRIGHT"[%s "AKA"<"RES" 0.0]\n", num);
		return (0);
	}
	return (1);
}

int	valid_light(char **tokens, bool bonus)
{
	int	count;

	count = count_split(tokens);
	if (!bonus && count != 3)
		return (args_count_error(tokens, count, 3));
	else if (bonus && count != 4)
		return (args_count_error(tokens, count, 4));
	if (!is_vec3(tokens[1]))
		return (0);
	if (!is_float(tokens[2]) || !valid_light_ratio(tokens[2]))
		return (0);
	if (bonus && !is_color(tokens[3]))
		return (0);
	return (1);
}

void	add_lights(t_world *w, t_parsed_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->light_count)
	{
		add_light_to_world(w,
			ft_light(scene->light_positions[i],
				scene->light_colours[i],
				scene->brightness[i]));
		i++;
	}
}
