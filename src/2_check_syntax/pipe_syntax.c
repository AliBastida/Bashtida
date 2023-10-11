/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:38:29 by abastida          #+#    #+#             */
/*   Updated: 2023/10/11 16:04:03 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

bool something_before(char *str)
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '|')
    {
        ft_putstr_fd("Syntax Error\n", 2);
        return (0);
    }
    return (1);
}

bool there_is_sth(char *str)
{
    if(!something_before(str))
        return (0);
    str = ft_strchr(str, '|');
    while (str != NULL)
    {  
        str = str + 1;
        if(!something_before(str))
            return (0);
        str = ft_strchr(str, '|');
    }
    return (1);
}

bool something_after(char *str)
{
    int len;

    len = ft_strlen(str);
    len = len - 1;
    while (str[len] == ' ')
        len--;
    if (str[len] == '|')
    {
        ft_putstr_fd("Syntax Error\n", 2);
        return (0);
    }
    return (1);
}

bool check_syntax_pipes(char *str)
{
    if (!there_is_sth(str))
        return (0);
    else if (!something_after(str))
        return (0);
    else
        return (1);
}