/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:36:13 by abastida          #+#    #+#             */
/*   Updated: 2022/05/26 13:46:03 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	if ((dst == src) || (!len))
		return (dst);
	if (dst > src)
	{
		while (len)
		{
			((unsigned char *) dst)[len - 1] = ((unsigned char *) src)[len - 1];
			len--;
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
