/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:05:16 by abastida          #+#    #+#             */
/*   Updated: 2022/06/08 15:22:29 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	slen;

	slen = ft_strlen (s);
	if ((slen == 0) || (slen < start))
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	else if (len > slen - start)
		len = slen - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)(s + start), len + 1);
	return (ptr);
}
