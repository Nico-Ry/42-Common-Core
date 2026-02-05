/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:22:49 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:22:54 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static int	print_float_error(const char *s)
{
	if (!s || !*s)
	{
		printf(R_B""X""RES""INVALID_INPUT""LILA"Tip: "TIP"\n"RES);
		return (0);
	}
	printf(R_B""X""RES"`"AKA"%s"RES"` is not a valid float\n", s);
	return (0);
}

static int	is_valid_float(const char *s, int i)
{
	int	has_dot;

	has_dot = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			i++;
			continue ;
		}
		else if (s[i] == '.')
		{
			if (has_dot)
				return (print_float_error(s));
			has_dot = 1;
		}
		else
			return (print_float_error(s));
		i++;
	}
	if (s[i - 1] == '.')
		return (print_float_error(s));
	return (1);
}

static int	valid_decimal_points(const char *s)
{
	char	**parts;
	int		count;

	parts = ft_split(s, '.');
	count = count_split(parts);
	if (count > 2)
	{
		free_array(parts);
		return (0);
	}
	free_array(parts);
	return (1);
}

int	is_float(const char *s)
{
	int	i;

	i = 0;
	if (!s || *s == '\0')
		return (print_float_error(s));
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '.' || !(valid_decimal_points(s)))
		return (print_float_error(s));
	if (!is_valid_float(s, i))
		return (0);
	return (1);
}

int	is_int(char *s)
{
	if (!s || !*s)
		return (print_pattern_error(0, s));
	if (s[1] && s[1] != '\0')
		return (print_pattern_error(0, s));
	if (s[0] < '0' || s[0] > '7')
		return (print_pattern_error(0, s));
	return (1);
}
