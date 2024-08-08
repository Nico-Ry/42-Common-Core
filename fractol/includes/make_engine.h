/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:43:29 by nryser            #+#    #+#             */
/*   Updated: 2024/08/07 20:55:51 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_ENGINE_H
# define MAKE_ENGINE_H

# include "fractal.h"

// Function declarations for initializing and managing the fractal engine
void	change_fractal(int key, t_engine *engine);
void	set_fractal_type(t_engine *engine, char *str);
void	reset_engine(t_engine *engine, int fractal_type);
void	init_engine(t_engine *engine, char *arg);
//declaration for the cleanup function
void	cleanup(t_engine *engine);

#endif  /* MAKE_ENGINE_H */