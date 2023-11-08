/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2023/11/08 14:51:39 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*En esta funcion hacemos substr de str segun la posicion en la que se encuentra*/
char *substr_token(char *str, int pipe, int i)
{
    char *token;
	if (str[i + 1] == '\0')
		token = ft_substr(str, pipe, i + 1 - pipe);
	else
		token = ft_substr(str, pipe, i - pipe);
	return (token);
}

/*esta funcion mira donde esta la siguiente quote para saltar todo lo que hay dentro*/
int next_quote(char *str, int i, char c)
{
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (0);
}

/*En esta funcion contamos los | que hay fuera de quotes*/
int how_many_pipes(char *str)
{
    int i;
    int n_pipes;
    
    i = 0;
    n_pipes = 0;
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
            i = next_quote(str, i + 1, str[i]);
        else if (str[i] == '|')
            n_pipes++;
        i++;
    }
    return (n_pipes);
}

/*En esta funcion miramos el num de pipes que estan fuera de quotes (next quote)y con substr_token
guarda en la variable line_by_pipes el cotenido. Nos retornara tantos como pipes + 1 */
char **line_divided_in_tokens(char *str)
{
    int i;
    int j;
    int x;
    int pipe;
    int num_pipe;
    
    char **line_by_pipes;
      
    i = 0;
    j = 0;
    x = 0;
    pipe = 0;
    num_pipe = how_many_pipes(str) + 2;
    line_by_pipes = ft_calloc(sizeof(char *), num_pipe);
    if (!line_by_pipes)
        return (NULL);
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
        {
            printf("i %d\n", i);
            x = next_quote(str, i + 1, str[i]);
            line_by_pipes[j] = substr_token(str, i, x - i+1);
            printf("j %d\n", j);
            j = j + 1;
         //   PRINT_ARRAY(line_by_pipes);
            i = x;
            printf("i %d\n", i);
            /*if (str[i + 1] == '\0')
                line_by_pipes[j] = ft_strdup("");*/
        }
        else if (str[i + 1] == '\0' || str[i] == '|')        
        { 
            // TODO PODEMOS QUITAR ESTE IF?
           // if (j < num_pipe)  
           // {
                line_by_pipes[j] = substr_token(str, pipe, i);
                pipe = i + 1;
              //  printf("j : %d, line_by_pipes: <%s>\n", j, line_by_pipes[j]);	
                j++;
               
          //  }
        }
        i++;    
       
    }
    line_by_pipes[j] = NULL;
    PRINT_ARRAY(line_by_pipes);
    
    return (line_by_pipes);
}

//TODO: Tenemos que dividir esta funcion. 

