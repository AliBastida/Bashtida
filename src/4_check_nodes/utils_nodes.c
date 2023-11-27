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
                // len++; lo hemos silenciado porque nos sumaba uno de mas xq entraba dos veces;
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
//TODO: lo siguiente a hacer es: sabiendo la len de nodos, lo que haremos es crear un char ** donde guardaremos lo qye hay dentro de cada nodo. Necesitamos calloc para reservar memoria.
//cuando tngamos reservado, recorreremos la str analizando si hay $, si hay '', y sabiendo que la primera posicion del array ** es cmd. (son todos los del env.).

char *divided_by_word(t_token *node)
{

    int i;
    t_token *tmp; 
    int start;
    char *new_word;

    i = 0;
    tmp = node;
    start = 0;
    new_word = NULL;

    while(tmp->content_token[i])
    {
        while (tmp->content_token[i] == ' ' || tmp->content_token[i] == '\t')
            i++;
        if (tmp->content_token[i] == '\'' || tmp->content_token[i] == '\"')
            i = next_quote(tmp->content_token, i, tmp->content_token[i]);
        if ((is_space(tmp->content_token[i - 1]) || i == 0) && !is_space(tmp->content_token[i]))
            start = i;
        if (is_space(tmp->content_token[i + 1]) || tmp->content_token[i + 1] == '\0')
            {
                new_word = ft_substr(tmp->content_token, start, i - start + 1);
                printf("retorno de substr: %s\n", ft_substr(tmp->content_token, start, i - start + 1));
            }
        i++;
        if (!new_word)
            return(NULL);
        return(new_word);
    }
   return(new_word);
}
