/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:50:06 by abastida          #+#    #+#             */
/*   Updated: 2022/12/09 14:21:21 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && (n - 1) && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
}
