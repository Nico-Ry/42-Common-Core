/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:55:23 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 09:55:27 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/**
 * @brief Prints the minishell banner
 */
void	print_banner(void)
{
	printf("   _   _   _   _   _   _   _     _   _\n");
	printf("  / \\ / \\ / \\ / \\ / \\ / \\ / \\   / \\ / \\ \n");
	printf(" ( w | e | l | c | o | m | e ) ( t | o )\n");
	printf("  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \n");
	printf("\n");
	printf("  __  __ _       _     _          _ _\n");
	printf(" |  \\/  (_)_ __ (_)___| |__   ___| | |\n");
	printf(" | |\\/| | | '_ \\| / __| '_ \\ / _ \\ | |\n");
	printf(" | |  | | | | | | \\__ \\ | | |  __/ | |\n");
	printf(" |_|  |_|_|_| |_|_|___/_| |_|\\___|_|_|\n");
	printf("\n");
	printf("\t\t   by ameechan & nryser\n");
}

/**
 * @brief Initializes all fields of the t_minishell struct to NULL or 0.
 * @param minish The minishell structure to initialize.
 */
void	init_minish_struct(t_minishell *minish)
{
	minish->env_lst = NULL;
	minish->local_vars = NULL;
	minish->env_array = NULL;
	minish->env_size = 0;
	minish->arg_lst = NULL;
	minish->args = NULL;
	minish->input_line = NULL;
	minish->ast = NULL;
	minish->last_exit_status = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_minishell	*minish;

	if (ac != 1)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	minish = malloc(sizeof(t_minishell));
	init_minish_struct(minish);
	setup_env(envp, minish);
	print_banner();
	start_shell(minish);
	return (0);
}
