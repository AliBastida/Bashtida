/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:17:06 by abastida          #+#    #+#             */
/*   Updated: 2023/11/06 16:46:16 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}*/
/* len_nodes calcula cuantos palabras hay entre pipes. Recoge una char * (content_token) y nos retorna la len que vamos a necesitar para crear los nodos nuevos de t_word*/
int len_nodes(char *token)//TODO /*esta funcion tal cual esta da error si le pasamos ** espacio > espacio | espacio >   no lo gestionamos porque sera syntax error*/
{
    int len;
    int i;

    len = 1;
    i = 0;
    while (token[i])
    {
        if (token[i] == '\'' || token[i] == '\"')
           i = next_quote(token, i + 1, token[i]);
        else if (token[i] == ' ' || token[i] == '\t')
        {

			while (token[i] == ' '|| token[i] == '\t')
                i++;
            if (token[i] != '\0' && token[i] != '<' && token[i] != '>')
				len++;
		   i--;
        }
        else if (token[i] == '>' || token[i] == '<')
        {
            if (token[i] == token[i + 1])
                i++;
            if (token[i + 1] != ' ')
                len++;
            len++;
        }
        i++;
	}
	return (len);
}
