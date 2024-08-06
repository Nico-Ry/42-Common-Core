/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:43:22 by nryser            #+#    #+#             */
/*   Updated: 2024/08/06 09:43:58 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fractal.h"

int	on_destroy_event(t_engine *engine);
int	on_mouse_hook_event(int key, int x, int y, t_engine *engine);
int	on_key_hook_event(int key, t_engine *engine);
int	on_mousemove_event(int x, int y, t_engine *engine);

#endif  /* EVENTS_H */
