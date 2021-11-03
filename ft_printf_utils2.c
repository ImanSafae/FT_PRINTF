/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:04:07 by itaouil           #+#    #+#             */
/*   Updated: 2021/10/28 17:04:13 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putptr_count(unsigned long ptr, int *count)
{
	ft_putstr_count("0x", count);
	ft_putnbr_base_count(ptr, count, 0);
}

void	ft_putunsignednbr_count(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunsignednbr_count(n / 10, count);
		ft_putunsignedchar_count(((n % 10) + 48), count);
	}
	if (n < 10)
	{
		ft_putunsignedchar_count((n + 48), count);
	}
}

void	ft_putunsignedchar_count(unsigned int c, int *count)
{
	write(1, &c, 1);
	(void)count;
	(*count)++;
}
