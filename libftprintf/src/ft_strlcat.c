/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:26:46 by abastida          #+#    #+#             */
/*   Updated: 2022/06/01 16:49:41 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	j = 0;
	i = ft_strlen(dst);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if ((dstsize == 0) || (i >= dstsize))
	{	
		return ((ft_strlen(src) + dstsize));
	}
	while (((src[j] != '\0') && (dstsize - 1) > i))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
