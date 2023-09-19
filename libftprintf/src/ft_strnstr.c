/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:45:16 by abastida          #+#    #+#             */
/*   Updated: 2022/05/30 16:52:37 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (len > (count2 + count) && haystack[count] != '\0')
	{
		if (haystack[count] == needle[count2])
		{
			while (needle[count2] != '\0' && len > (count + count2))
			{
				if (haystack[count + count2] == needle[count2])
					count2++;
				else
					break ;
			}
			if (needle[count2] == '\0')
				return ((char *)&haystack[count]);
			count2 = 0;
		}
		count++;
	}
	return (NULL);
}
