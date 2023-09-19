/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:37:16 by abastida          #+#    #+#             */
/*   Updated: 2022/06/01 10:42:59 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * (sizeof(char) * size));
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, (count * size));
	return (ptr);
}
