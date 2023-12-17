/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:46:38 by nryser            #+#    #+#             */
/*   Updated: 2023/12/17 16:14:41 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

int 	ft_printf(const char *str, ...);
int		ft_work(const char *str, va_list ap);
int		ft_char(char c);
int		ft_putstr(char *str);


#endif
