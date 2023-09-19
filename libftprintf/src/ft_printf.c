/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:57:35 by abastida          #+#    #+#             */
/*   Updated: 2022/10/22 19:06:45 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list arg, const char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (type == '%')
		len += ft_putchar('%');
	else if (type == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if ((type == 'd') || (type == 'i'))
		len += ft_printnbr(va_arg(arg, int));
	else if (type == 'u')
		len += ft_printnbr(va_arg(arg, unsigned int));
	else if (type == 'x')
		len += ft_puthexa_low(va_arg(arg, unsigned int));
	else if (type == 'X')
		len += ft_puthexa_upper(va_arg(arg, unsigned int));
	else if (type == 'p')
		len += ft_ptrhexa(va_arg(arg, unsigned long long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start (arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(arg, str[i + 1]);
			i += 2;
		}
		else
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (len);
}
