/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:24:43 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:24:45 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static t_id	unique_id(char *s)
{
	if (*s == 'A')
		return (A);
	else if (*s == 'C')
		return (C);
	else if (*s == 'L')
		return (L);
	printf(R_B""X""RES""ID_ERR""AKA"%s\n"RES, s);
	return (UFO);
}

static t_id	shape_id(char *s)
{
	if (s[0] == 's' && s[1] == 'p')
		return (SP);
	else if (s[0] == 'p' && s[1] == 'l')
		return (PL);
	else if (s[0] == 'c' && s[1] == 'y')
		return (CY);
	else if (s[0] == 'c' && s[1] == 'o')
		return (CO);
	printf(R_B""X""RES""ID_ERR""AKA"%s\n"RES, s);
	return (UFO);
}

t_id	get_identifier(char *s)
{
	int	len;

	if (!s || !*s)
		return (UFO);
	len = ft_strlen(s);
	if (len == 1)
		return (unique_id(s));
	if (len == 2)
		return (shape_id(s));
	printf(R_B""X""RES""ID_ERR""AKA"%s\n"RES, s);
	return (UFO);
}

// static t_tokens	*handle_token_line(char **lines,
// 					int i, t_tokens **head)
// {
// 	char		**tokens;
// 	t_tokens	*new_node;

// 	tokens = ft_split(lines[i], ' ');
// 	if (!tokens)
// 	{
// 		printf(AKA"Error: Failed to split line: %s\n"RES, lines[i]);
// 		free_array(lines);
// 		return (NULL);
// 	}
// 	if (!valid_tokens_old(tokens))
// 	{
// 		printf(AKA"Invalid token line: %s\n"RES, lines[i]);
// 		free_array(tokens);
// 		free_array(lines);
// 		return (NULL);
// 	}
// 	new_node = create_token_node(tokens, get_identifier(tokens[0]));
// 	append_token_node(head, new_node);
// 	return (*head);
// }

static t_tokens	*parse_line(char *line)
{
	char		**tokens;
	t_id		type;
	t_tokens	*new_node;

	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		printf(R_B""X""RES""FAILED_SPLIT"`"AKA"%s"RES"`\n", line);
		return (NULL);
	}
	type = get_identifier(tokens[0]);
	if (type == UFO)
		return (NULL);
	new_node = create_token_node(tokens, type);
	return (new_node);
}

t_tokens	*parse_input(char **lines)
{
	int			i;
	t_tokens	*head;
	t_tokens	*new_node;

	i = 0;
	head = NULL;
	while (lines[i])
	{
		new_node = parse_line(lines[i]);
		if (!new_node)
			return (free_tokens_list(head));
		append_token_node(&head, new_node);
		i++;
	}
	printf(G_B"✔ "GR"Finished parsing tokens\n"RES);
	return (head);
}
