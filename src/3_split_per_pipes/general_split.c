/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2023/10/30 10:41:05 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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
    if (str[i] == c)
        return (i);
    return (0);
}
/*esta funcion busca el char y despues del if, va otro que busca el |*/
char *look_for_char(char *str)
{
    int i = 0;
    int pipe = 0;
    char *line_by_pipes = NULL;
    
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
        {
            printf("el caracter es: %c La posicion de i: %d\n", str[i], i);
            i = next_quote(str, i + 1, str[i]);
            printf("la siguiente posicion es: %d\n", i);
        }
        else if (str[i + 1] == '\0' || str[i] == '|')
        {    
            line_by_pipes = substr_token(str, pipe, i);
            printf("line_by_pipes: %s\n", line_by_pipes);
			pipe = i + 1;
			
        }
        i++;
    }
    return (line_by_pipes);
}

//TODO: AHORA LO QUE TENGO QUE HACER ES QUE LO QUE RETORNA(LINE_BY_PIPES) GUARDARLO EN NODOS.