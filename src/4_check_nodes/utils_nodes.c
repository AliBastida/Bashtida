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

int len_nodes(char *token)
{
    int len;
    int i;

    len = 1;
    i = 0;
    while (token[i])
    {
        if (token[i] == ' ')
            len++;
        else if ((token[i] == '<') || ((token[i] == '<') 
            && (token[i + 1] == '<'))
            || (token[i] == '>') || (token[i] == '>' && token[i + 1] == '>'))
            len ++;
        i++;
    }
    return (len);
}
//TODO: tengo que arregar esta funcion porque me cuenta por cada > 1, lo que quiero es que cuente 1 si es > o 1 si es >>.
//TODO: lo siguiente a hacer es: sabiendo la len de nodos, lo que haremos es crear un char ** donde guardaremos lo qye hay dentro de cada nodo. Necesitamos calloc para reservar memoria.
//cuando tngamos reservado, recorreremos la str analizando si hay $, si hay '', y sabiendo que la primera posicion del array ** es cmd. (son todos los del env.).


/*
int len_nodes(char *token)
{
    int len;
    int i;

    len = 1;
    i = 0;
    while (token[i])
    {
        if (ft_strcmp(token, " ") == 0)
        {
            len++;
            printf("ENTRA EN ESPACIO\n");
        }
        else if ((ft_strcmp(&token[i], ">") == 0) ||
        (ft_strcmp(token, ">>") == 0) ||
        (ft_strcmp(&token[i], "<") == 0) ||
        (ft_strcmp(&token[i], "<<") == 0))
        {
            printf("ENTRA EN REDIRECCION\n");
            len += 2;
        }
        i++;
    }
    return (len);
}*/






/*

char **divided_by_word(t_master *master)
{
    
    t_token *tmp; 
    char **word;
    int len;

    
    word = ft_calloc((sizeof(char *), ))
}*/