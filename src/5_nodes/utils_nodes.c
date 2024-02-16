/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:17:06 by abastida          #+#    #+#             */
/*   Updated: 2024/02/12 13:34:06 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	i++;
}

// Esta funcion recibe t_token y guarda cada nodo limpio de comillas y con dollar expandido
void line_ready_to_use(t_token *token, t_master *master)
{
	t_word *node;
	t_token *tmp;
	char *var_con_dolar_expandido;

	tmp = token;
	while (tmp)
	{
		node = token->words;
		while (node)
		{
			var_con_dolar_expandido = extract_dollar(node, master->env);
			clean_line(var_con_dolar_expandido, master);
			free(node->word);
			node->word = ft_strdup(master->clean_line);
			free(master->clean_line);
			master->clean_line = NULL;
			node = node->next;
		}
		tmp = tmp->next;
	}
}

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

// hemos hecho un sbstr de new y obtendremos rest que es lo que usaremos como nuevo tmp en la funcion create_nodeand list_word
char *substr_words(t_token *tmp, int start, int i)
{
	char *new;
	char *rest;
	new = ft_substr(tmp->content_token, start, i - start + 1);
	rest = ft_substr(tmp->content_token, i + 1, ft_strlen(tmp->content_token));
	free(tmp->content_token);
	if (!ft_strncmp(rest, "", 1))
	{
		free(rest);
		tmp->content_token = NULL;
	}
	else
		tmp->content_token = rest;
	return new;
}