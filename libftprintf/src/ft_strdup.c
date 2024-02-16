/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:44:20 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 17:50:00 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*scp;

	len = ft_strlen(s1);
	scp = malloc(sizeof(char) * (len + 1));
	if (!scp)
		return (NULL);
	if (scp)
	{
		ft_memcpy(scp, s1, len + 1);
		return (scp);
	}
	return (NULL);
	free(scp);
}
