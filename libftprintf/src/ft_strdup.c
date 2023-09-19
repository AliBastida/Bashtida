/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:44:20 by abastida          #+#    #+#             */
/*   Updated: 2022/06/01 12:29:54 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*scp;

	len = ft_strlen(s1);
	scp = malloc(sizeof(char) * (len + 1));
	if (scp)
	{
		ft_memcpy(scp, s1, len + 1);
		return (scp);
	}
	return (NULL);
	free(scp);
}
