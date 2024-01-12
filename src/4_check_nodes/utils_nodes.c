/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:17:06 by abastida          #+#    #+#             */
/*   Updated: 2024/01/12 13:40:17 by abastida         ###   ########.fr       */
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
	printf("%d\n", len);
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
