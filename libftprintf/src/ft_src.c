/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:57:48 by abastida          #+#    #+#             */
/*   Updated: 2022/10/22 19:08:00 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	rst;

	rst = 0;
	if (str == NULL)
	{
		if (write (1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	i = -1;
	while (str[++i])
		rst += write (1, &str[i], 1);
	return (rst);
}

int	ft_putnbr(long long num, int signo)
{
	char	c;

	c = num % 10 + '0';
	if (num <= 9)
		return (write(1, "-", signo) + write(1, &c, 1));
	return (ft_putnbr(num / 10, signo) + write(1, &c, 1));
}

int	ft_printnbr(long long n)
{
	if (n < 0)
		return (ft_putnbr(n * -1, 1));
	return (ft_putnbr(n, 0));
}
