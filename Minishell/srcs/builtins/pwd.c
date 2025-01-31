/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:44:20 by nryser            #+#    #+#             */
/*   Updated: 2025/01/27 18:47:33 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_pwd(t_command *node)
{
	char	cwd[1024];
	int		fd;

	(void)node;
	fd = STDOUT_FILENO;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(fd, cwd, ft_strlen(cwd));
		write(fd, "\n", 1);
	}
	else
	{
		perror("miniHell: pwd");
		return (1);
	}
	return (0);
}
