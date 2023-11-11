/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:16:33 by abastida          #+#    #+#             */
/*   Updated: 2023/11/10 09:27:30 by abastida         ###   ########.fr       */
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
        printf("Char: %c\tI: %d\n", str[i], i);
        if (str[i] == '\'' || str[i] == '\"')
        {
            i = next_quote(str, i + 1, str[i]);
            printf("Char: %c\tI: %d\n", str[i], i);
        }
        if (str[i] == c)
            return (i);
        i++;
    }
    return (i);
}
