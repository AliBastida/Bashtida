/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:11 by abastida          #+#    #+#             */
/*   Updated: 2022/06/13 16:07:24 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	long	a;

	a = (long) n;
	i = ft_intlen(a);
	num = (char *) malloc(sizeof(char) * (i + 1));
	if (!num)
		return (0);
	num[i] = '\0';
	if (a == 0)
		num[0] = '0';
	else if (a < 0)
	{
		a *= -1;
		num[0] = '-';
	}
	while (a > 0)
	{
		num[--i] = (a % 10) + '0';
		a /= 10;
	}
	return (num);
}
