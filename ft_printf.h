/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:44:20 by itaouil           #+#    #+#             */
/*   Updated: 2021/10/28 10:44:21 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int     ft_printf(const char *s, ...);
void    ft_putchar(char c);
void    ft_putchar_count(char c, int *count);
void    ft_putnbr_base_count(unsigned long n, int *count);
void    ft_putnbr_count(int n, int *count);
void    ft_putptr_count(unsigned long ptr, int *count);
void    ft_putstr_count(char *s, int *count);
int     ft_strlen(const char *str);
void    print_args(const char *s, size_t i, va_list arglist, int *count);


#endif