/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:35:13 by abastida          #+#    #+#             */
/*   Updated: 2023/11/07 11:01:18 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	last;
	char	*new;

	start = 0;
	last = ft_strlen(s1);
	while ((s1[start]) && (ft_strchr(set, s1[start])))
		start++;
	while ((last > start) && (ft_strchr(set, s1[last - 1])))
		last--;
	new = malloc(sizeof(char) * (last - start + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[start], (last - start + 1));
	return (new);
}
