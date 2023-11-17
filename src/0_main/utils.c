/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:31:30 by abastida          #+#    #+#             */
/*   Updated: 2023/11/17 12:11:45 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int syntax_error(int n)
{
    if (n == 3)
        ft_putstr_fd("Syntax Error\n", 2);
    else if (n == 0)
        ft_putstr_fd("Syntax Error\n", 2);

    return (n);
}

void ft_free_single(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return ;
    while (str[i])
    {
        if (str[i])
            free (str);
        i++;
    }
    free (str);
}

bool is_space(unsigned char c)
{
    if (c == ' ' || c == '\t') //|| c == '\n' || c == '\v' || c == '\f' 
       // || c == '\r')
        return (true);
    else
        return (false);
}