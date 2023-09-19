/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:57:08 by abastida          #+#    #+#             */
/*   Updated: 2022/10/22 19:08:29 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa_low(unsigned long num)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	c = base [num % 16];
	if (num >= 16)
		return (ft_puthexa_low(num / 16) + write(1, &c, 1));
	return (write(1, &c, 1));
}

int	ft_puthexa_upper(unsigned long num)
{
	char	*base;
	char	c;

	base = "0123456789ABCDEF";
	c = base [num % 16];
	if (num >= 16)
		return (ft_puthexa_upper(num / 16) + write(1, &c, 1));
	return (write(1, &c, 1));
}

int	ft_ptrhexa(unsigned long pointer)
{
	return (write(1, "0x", 2) + ft_puthexa_low(pointer));
}
