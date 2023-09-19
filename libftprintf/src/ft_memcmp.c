/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:30:30 by abastida          #+#    #+#             */
/*   Updated: 2022/05/27 17:00:47 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pts1;
	unsigned char	*pts2;
	unsigned int	i;

	pts1 = (unsigned char *)s1;
	pts2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (pts1[i] != pts2[i])
			return ((pts1)[i] - (pts2)[i]);
		i++;
	}
	return (0);
}
