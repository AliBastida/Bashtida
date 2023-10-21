/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2023/10/21 10:03:25 by abastida         ###   ########.fr       */
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
                return(1);
            }
            j++;
        }     
    }
    return (0);
}

char *substring_frompipe(char *str, int pipe, int i)
{
    char *content;
    
    if (str[i + 1] == '\0')
        content = ft_substr(str, pipe, i+1 - pipe);
    else
        content = ft_substr(str, pipe, i - pipe);
    return(content);
}

char *checking_pipe_quoted(char *str, bool start_point)
{
    int i = 0;
    int pipe = 0;
    char *content;
    
    if (start_point)
    {
        i = 0;
        pipe = 0;
    }
    content = NULL;
    while (str[i])
    {
        if ((str[i] == '|'  && !pipe_quoted(str, i)) || str[i + 1] == '\0')
        {
            content = substring_frompipe(str, pipe, i);
            pipe = i + 1;
            printf("content: %s\n", content);
            i++;
            
        }
        i++;
    }
    return (content);
}

int num_pipes(char *str)
{
    int i;
    int n_pipes;

    i = 0;
    n_pipes = 0;
    while (str[i])
    {
        if (str[i] == '|' && (!pipe_quoted(str,i)))
            n_pipes++;
        i++;    
    }
    return (n_pipes + 1);
}

//TODOrevisar la separacion de contenidos por pipes. si pongo 2 pipes, me imprime el segund y en el ultimo, se come la ultima posicion.


//TODOcreate_token_list
//TODOgeneral_split



