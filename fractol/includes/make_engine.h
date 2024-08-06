/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:43:29 by nryser            #+#    #+#             */
/*   Updated: 2024/08/06 09:44:17 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_ENGINE_H
# define MAKE_ENGINE_H

# include "fractal.h"

void	change_fractal(int key, t_engine *engine);
void	set_fractal_type(t_engine *engine, char *str);
void	reset_engine(t_engine *engine, int fractal_type);
void	init_engine(t_engine *engine, char *arg);

#endif  /* MAKE_ENGINE_H */