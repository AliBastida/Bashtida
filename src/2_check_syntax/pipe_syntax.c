/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:38:29 by abastida          #+#    #+#             */
/*   Updated: 2023/11/08 16:07:40 by abastida         ###   ########.fr       */
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
        return (0);
    return (1);
}

bool there_is_sth(char *str)
{
    if(!something_before(str))
        return (0);
    str = ft_strchr(str, '|');

    while (str != NULL)
    {  
        if (str == str + 1)
            return (syntax_error(3));
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
    while (str[len] == ' ')
        len--;
    if (str[len] == '|')
        return (syntax_error(0));
    return (1);
}

bool check_syntax_pipes(char *str)
{
    if (!str)
    {
        printf("hola\n"); 
        return (0);
    }
      
    if (!there_is_sth(str))
        return (0);
    if (!something_after(str))
        return (0);   
    return (1);
}

//TODO: tenemos que revisar el caso en el que haya un | seguido de "". Eso deberia dar error tb.