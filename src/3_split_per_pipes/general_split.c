/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2023/10/18 11:01:50 by abastida         ###   ########.fr       */
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

int checking_pipe_quoted(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '|')
        {
            printf("%d\n", pipe_quoted(str, i));
        }
        i++;
    }
    return (0);
}















/*int how_many_pipes(char *str)
{
    int i;
    int pipes;

    i = 0;
    pipes = 1;
    while (str[i])
    {
        if (str[i] == '|')
            pipes++;
        i++;
    }
    return (pipes);
}

int token_length(char *str)
{
    int i = 0;
    int length = 0;
    while (str[i] != '|' && str[i] != '\0')
    {
        if (str[i] == '|')
            length = i;
        i++;
    }
    return (i - length);
}


int token_length(char *str, int pipe)
{
    int length = pipe;
    while (str[length] != '|' && str[length] !=) '\0'
        length++;
    return (length - pipe);
}

bool pipe_quoted(char *str, int i)
{
    int j;
    int flag;

    j = 0;
    flag = 0;
    while (str[j] && j < i)
    {
        printf ("primer valor de j%d\n", j);
        if (str[j] == '\'' || str[j] == '\"')
        {
            flag = 1;
            printf("%d\n", j);
        }
        else if (flag == 1 && (str[j] == '\'' || str[j] == '\"'))
            flag = 0;
        j++;
    }
    while (str[j] && j >= i)
    {
        if ((str[j] == '\'' || str[j] == '\"') && flag == 1)
            return (1);
        j++;
    }
    return (flag);
}

int how_many_pipes(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '|')
        {
            if (pipe_quoted(str, i) == 1)
                printf("no hace nada\n");
            else if (pipe_quoted(str, i) == 0)
                printf("hace substr\n");
            else
                printf("caca\n");
        }
        i++;
    }
    return (0);
}*/



/*
t_token	*ft_lstnew(void *str)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new -> content_token = str;
    new -> previous = NULL;
	new -> next = NULL;
	return (new);
}*/


//TODOcreate_token_list
//TODOgeneral_split