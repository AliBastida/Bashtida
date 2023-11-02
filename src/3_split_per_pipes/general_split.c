/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2023/11/02 14:37:02 by abastida         ###   ########.fr       */
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
lo guarda en la variable line_by_pipes, que nos retornara tantos como pipes + 1 */
char **line_divided_in_tokens(char *str)
{
    int i;
    int j;
    int pipe;
    int num_pipe;
    
    char **line_by_pipes;
      
    i = 0;
    j = 0;
    pipe = 0;
    num_pipe = how_many_pipes(str) + 2;
    line_by_pipes = ft_calloc(sizeof(char *), num_pipe);
    if (!line_by_pipes)
        return (NULL);
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
            i = next_quote(str, i + 1, str[i]);
        else if (str[i + 1] == '\0' || str[i] == '|')
        { 
            // TODO PODEMOS QUITAR ESTE IF? y por qu'e entra dos veces aqui??
           // if (j < num_pipe)  
           // {
                line_by_pipes[j] = substr_token(str, pipe, i); 
                pipe = i + 1;
                printf("j : %d, line_by_pipes: %s\n", j, line_by_pipes[j]);	
                j++;
               
          //  }
        }
        i++;
    }
    line_by_pipes[j] = NULL;
    return (line_by_pipes);
}

//TODO: Tenemos que dividir esta funcion. 

