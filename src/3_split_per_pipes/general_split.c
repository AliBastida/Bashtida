/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2023/11/10 13:23:26 by abastida         ###   ########.fr       */
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
    return (i);
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


int ft_copy_line(char **line, char *str)
{
    int len; 

    len = ft_strchar(str, '|') + 1; // Porque el calloc y el strlcpy necesitan un valor mas para funcionar
    printf("len: %d, str: %s\n", len, str);
    *line = ft_calloc(sizeof(char), len);
    ft_strlcpy(*line, str, len);
    printf("line : -%s-\n", *line);
    return (len);
}
/*En esta funcion miramos el num de pipe*s que estan fuera de quotes (next quote)y con substr_token
guarda en la variable line_by_pipes el cotenido. Nos retornara tantos como pipes + 1 */
/*char **line_divided_in_tokens(char *str)
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
    num_pipe = how_many_pipes(str) + 2;// mas dos porque necesitamos una posicion mas y para el nulo;
    line_by_pipes = ft_calloc(sizeof(char *), num_pipe);
    if (!line_by_pipes)
        return (NULL);
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
        {
          //  printf("i %d\n", i);
            i = next_quote(str, i + 1, str[i]);
          //  line_by_pipes[j] = substr_token(str, i, x - i+1);
          //  printf("j %d\n", j);
          //  j = j + 1;
          printf("hola\n");
          PRINT_ARRAY(line_by_pipes);
          //  i = x;
           // printf("i %d\n", i);
            if (str[i + 1] == '\0')
                line_by_pipes[j] = ft_strdup("");
        }
        else if (str[i + 1] == '\0' || str[i] == '|')
        { 
            // TODO PODEMOS QUITAR ESTE IF?
          // if (j < num_pipe)  
           //{
                line_by_pipes[j] = substr_token(str, pipe, i);
                pipe = i + 1;
                printf("j : %d, line_by_pipes: <%s>\n", j, line_by_pipes[j]);	
                j++;
               
            //}
        }
        i++;    
       
    }
    line_by_pipes[j] = NULL;
    PRINT_ARRAY(line_by_pipes);
    return (line_by_pipes);
}*/

char **line_divided_in_tokens(char *str)
{
    char **line_divided;
    int j;
    int position;
    int n_box;

    n_box = how_many_pipes(str) + 1;
    line_divided = ft_calloc(sizeof(char *), n_box + 1);
    j = 0;
    position = 0;
    while (n_box > j)
    {         
        printf("position: %d\n", position);//aqui vamos a grabar en line_divided[j] lo que saquemos de str[i].
        position += ft_copy_line(&line_divided[j], str + position);
        printf("line divided: =====%s======\n", line_divided[j]);
        j++;
    }
    line_divided[j] = NULL;
    return  (line_divided);
}

