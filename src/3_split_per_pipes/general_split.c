/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2023/10/18 20:31:33 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//TODO hay que revisar la funcion porque creo que mezcla las commillas y no contabiliza bieb ek numero
//si retorna 1 es porque el | esta entre comillas.
//si retorna 0 es porque no esta entre comillas.

int pipe_quoted(char *str, int i)
{
    int j;
    int flag;
    int aux;

    j = 0;
    flag = 0;
    aux = 0;
    while (str[j] && j < i)
    {
        if (flag == 0 && ((str[j] == '\'' ) || (str[j] == '\"')))
        {
            flag = 1;
            str[aux] = str[j];
            j++;
        }
        else if (flag == 1 && str[j] == str[aux])
            flag = 0;
        j++;
    }
    if (flag == 1)
    {
        while (str[j] && j >= i)
        {
            if (str[j] == str[aux])
            {
                return(syntax_error(1));
            }
            j++;
        }     
    }
    return (0);
}
char *substring_frompipe(char *str, int pipe, int i)
{
    char *content_node;
   
    if (str[i] == '\0')
        content_node = ft_substr(str, pipe, (i - 1) - pipe);
    else
        content_node = ft_substr(str, pipe, i - pipe);
    return (content_node);
}

char *checking_pipe_quoted(char *str)
{
    int i;
    int pipe;
    char *content;

    i = 0;
    pipe = 0;
    content = NULL;
    while (str[i])
    {
        if (str[i] == '|' || str[i + 1] == '\0')
        {
            if (!pipe_quoted(str, i))
            {
                content = substring_frompipe(str, pipe, i);
                pipe = i + 1;
               // break;
                i++;
                printf("content: %s\n", content);
            }
            //i++;
        }
        i++;
    }
    return (content);
}





//TODOcreate_token_list
//TODOgeneral_split



