/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:29:17 by itaouil           #+#    #+#             */
/*   Updated: 2021/10/18 13:29:21 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(const char *s, size_t i, va_list arglist, int *count)
{
	if (s[i] == 'c')
		ft_putchar_count(va_arg(arglist, int), count);
	else if (s[i] == 's')
		ft_putstr_count(va_arg(arglist, char *), count);
	else if (s[i] == 'p')
		ft_putptr_count(va_arg(arglist, unsigned long), count);
	else if (s[i] == 'i' || s[i] == 'd')
		ft_putnbr_count(va_arg(arglist, int), count);
	else if (s[i] == 'u')
		ft_putunsignednbr_count(va_arg(arglist, unsigned int), count);
	else if (s[i] == 'x')
		ft_putnbr_base_count(va_arg(arglist, unsigned int), count, 0);
	else if (s[i] == 'X')
		ft_putnbr_base_count(va_arg(arglist, unsigned int), count, 16);
	else if (s[i] == '%')
		ft_putchar_count('%', count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arglist;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arglist, s);
	while ((i < ft_strlen(s)) && s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			print_args(s, i, arglist, &count);
		}
		else
		{
			ft_putchar_count(s[i], &count);
		}
		i++;
	}
	va_end(arglist);
	return (count);
}
