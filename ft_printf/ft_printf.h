/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:46:38 by nryser            #+#    #+#             */
/*   Updated: 2023/12/19 16:43:15 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

int			ft_printf(const char *str, ...);
int			ft_work(const char *str, va_list ap);
int			ft_char(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int nbr, char *dec_chars);
int			ft_putptr(unsigned long ptr, char *hex_chars);
int			ft_putnbr_hex(unsigned long nbr, char *hex_chars);
int			ft_putnbr_dec(unsigned int nbr, char *dec_chars);
#endif