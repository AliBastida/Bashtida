/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:09:08 by abastida          #+#    #+#             */
/*   Updated: 2022/06/07 13:25:00 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (NULL);
	i = 0;
	while ((s1[i] != '\0') && (i >= 0))
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while ((s2[j]) && (j >= 0))
	{
		new[i + j] = s2[j];
			j++;
	}
	new [i + j] = '\0';
	return (new);
}
