/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:01:23 by abastida          #+#    #+#             */
/*   Updated: 2022/06/07 14:39:34 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[11];
	int		i;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	else if (n == 0)
		ft_putchar_fd('0', fd);
	i = 0;
	while (n > 0)
	{
		num[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	while (i > 0)
		ft_putchar_fd(num[--i], fd);
}
