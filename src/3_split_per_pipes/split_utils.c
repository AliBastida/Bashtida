/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:16:33 by abastida          #+#    #+#             */
/*   Updated: 2023/12/04 14:31:40 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strchar(char *str, int c)
{
    int i;

    i = 0;
   // printf("Check: %c\n", c);
    while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			i = next_quote(str, i + 1, str[i]);
		}
		if (str[i] == c)
            return (i);
        i++;
	}
	return (i);
}
