/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2023/12/04 14:38:37 by pabastid         ###   ########.fr       */
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
	*line = ft_calloc(sizeof(char), len);
	ft_strlcpy(*line, str, len);
	return (len);
}

char **line_divided_in_tokens(char *str)
{
    char **line_divided;
    int j;
    int position;
    int n_box;

    n_box = how_many_pipes(str) + 1;
    line_divided = ft_calloc(sizeof(char *), n_box + 1);
    if(!line_divided)
        return(NULL);
    j = 0;
    position = 0;
    while (n_box > j)
	{
		position += ft_copy_line(&line_divided[j], str + position);
		printf("line divided: =====%s======\n", line_divided[j]);
		j++;
	}
	line_divided[j] = NULL;
	return (line_divided);
}

