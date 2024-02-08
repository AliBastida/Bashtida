/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:17:06 by abastida          #+#    #+#             */
/*   Updated: 2024/02/08 17:10:45 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Esta funcion retorna 1 si es redireccion y 0 si no es.
int is_redir(char *str, int i)
{
	if (str[i] != '\0' && (str[i] == '>' || str[i] == '<'))
	{
		if ((str[i + 1]) != '\0' && (str[i + 1] == str[i]))
			return (2);
		return (1);
	}
	return (0);
}

/* len_nodes calcula cuantos palabras hay entre pipes. Recoge una char * (content_token) y nos retorna la len que vamos a necesitar para crear los nodos nuevos de t_word*/
int len_nodes(char *token)
{
    int len;
    int i;

	len = 1;
	i = 0;

	while (token[i])
	{
		if (token[i + 1] && (token[i] == '\'' || token[i] == '\"'))
			i = next_quote(token, i + 1, token[i]);
		if (!is_space(token[i]) && is_space(token[i + 1]) && !is_redir(token, i))
			len++;
		if (is_redir(token, i) != 0)
		{
			if (i != 0 && !is_space(token[i - 1]))
				len++;
			if (is_redir(token, i) == 2)
				i++;
			if (token[i + 1] == '\0')
				len--;
			len++;
		}
		i++;
	}
	return (len);
}
// FIXME: arreglar esta funcion
void categorizing_words(t_word *node)
{
	int i;

	i = 0;

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
		else
			i++;
}

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
}
