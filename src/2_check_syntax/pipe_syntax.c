/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:38:29 by abastida          #+#    #+#             */
/*   Updated: 2023/10/12 14:30:45 by pabastid         ###   ########.fr       */
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
        syntax_error(0);
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
        syntax_error(0);
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