/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:17:06 by abastida          #+#    #+#             */
/*   Updated: 2024/01/11 15:09:35 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Esta funcion retorna 1 si es redireccion y 0 si no es.
int is_redir(char *str, int i)
{
	if (str[i] != '\0' && (str[i] == '>' || str[i] == '<'))
	{
		if ((str[i + 1]) != '\0' && (str[i + 1] == str[i]))
		{
			printf("Doble redir\n");
			printf("valor de i en redir%d\n", i);
			return (2);
		}
		printf("Simple redir\n");
		return (1);
	}
	return (0);
}

/*
char *substr_words(t_token *tmp, int start, int i)
{
	char *new;
	char *rest;
	new = ft_substr(tmp->content_token, start, i - start + 1); // hemos hecho un sbstr de new y obtendremos rest que es lo que usaremos como nuevo tmp en la funcion create_nodeand list_word
	printf("new: ***%s***\n", new);
	rest = ft_substr(tmp->content_token, i + 1, ft_strlen(tmp->content_token));
	printf("resto: -%s-\n", rest);
	free(tmp->content_token);
	tmp->content_token = rest;
	return new;
}*/
// TODO /*esta funcion tal cual esta da error si le pasamos ** espacio > espacio | espacio >   no lo gestionamos porque sera syntax error*//* len_nodes calcula cuantos palabras hay entre pipes. Recoge una char * (content_token) y nos retorna la len que vamos a necesitar para crear los nodos nuevos de t_word*/
int len_nodes(char *token)
{
    int len;
    int i;

	len = 1; // TODO: TENEMOS QUE VER QUE VALOR DARLE A LEN O COMO GESTIONAR SU VALOR PORQUE SI PONEMOS LEN 0 NOS DEJA UN NODO FUERA Y SI PONEMOS LEN 1 NOS DA SEGFAULT SI HACEMOS >A.
	i = 0;
	while (token[i])
	{
        if (token[i] == '\'' || token[i] == '\"')
           i = next_quote(token, i + 1, token[i]);
		else if (token[i] == ' ' || token[i] == '\t') // is_space(token[i])
		{

			while (token[i] == ' '|| token[i] == '\t')
                i++;
            if (token[i] != '\0' && token[i] != '<' && token[i] != '>')
				len++;
		   i--;
		}
		else if (token[i] == '>' || token[i] == '<') // is_redir(token[i]))
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

void categorizing_words(t_word *node)
{
	int i;

	i = 0;
	while (node->word[i] != '\0')
	{
		if (node->word[i] == '<' && node->word[i + 1] == '<')
		{
			node->type = REDIR_A;
			i++;
		}
		else if (node->word[i] == '>' && node->word[i + 1] == '>')
		{
			node->type = REDIR_B;
			i++;
		}
		else if (node->word[i] == '<')
			node->type = REDIR_C;
		else if (node->word[i] == '>')
			node->type = REDIR_D;
		else if (node->word[i] == '$')
			node->type = DOLLAR;
		i++;
	}
}
