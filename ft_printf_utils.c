/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:44:28 by itaouil           #+#    #+#             */
/*   Updated: 2021/10/28 10:44:31 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void    ft_putchar_count(char c, int *count)
{
    write(1, &c, 1);
    (void)count;
    (*count)++;
}

void    ft_putstr_count(char *s, int *count)
{
    int i;

    i = 0;
    if (!s)
    {
        ft_putstr_count("(null)", count);
        return ;
    }
    while (s[i])
    {
        ft_putchar_count(s[i], count);
        i++;
    }
}

void    ft_putnbr_count(int n, int *count)
{
    if (n == -2147483648)
    {
        
        return ;
    }
    if (n < 0)
    {
        ft_putchar_count('-', count);
        n = -n;
    }
    if (n >= 10)
    {
        ft_putnbr_count(n / 10, count);
        ft_putchar_count(((n % 10) + 48), count);
    }
    if (n < 10)
    {
        ft_putchar_count((n + 48), count);
    }
}

void    ft_putnbr_base_count(unsigned long n, int *count)
{
    const char    base16[] = "0123456789abcdef";
    char    i;

    if (n >= 16)
    {
        ft_putnbr_base_count(n / 16, count);
        i = base16[(n % 16)];
        ft_putchar_count(i, count);
    }
    if (n < 16)
    {
        i = base16[n];
        ft_putchar_count(i, count);
    }
}

void ft_putptr_count(unsigned long ptr, int *count)
{
    ft_putstr_count("0x", count);
    ft_putnbr_base_count(ptr, count);
}
