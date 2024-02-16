/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:40:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/09 12:20:54 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*En esta funcion contamos los | que hay fuera de quotes*/
static int how_many_pipes(char *str)
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

// Con esta funcion crearemos el nuevo nodo
static char *clean_word(char *str)
{
	char *clean_line;

	clean_line = ft_strtrim(str, " ");
	free(str);
	return (clean_line);
}

static t_token *ft_newnode(void *content)
{
	t_token	*new;

	new = ft_calloc(sizeof(t_token), 1);
	if (!new)
		return (NULL);
	new->content_token = content;
	new->next = NULL;
	return (new);
}

// Esta es nuestra funcion para crear la lista con el rdo de line_divided_in_tokens nos lo guardara en un nuevo nodo
// (new_node) en funcion de los pipes que encuentra (n).

// TODO: aqui he borrado la variable n_pipes y estoy utilizando la n_pipes de master
t_token *create_nodeandlist(t_master *master, char *str)
{
	int n;
	int n_pipes;
	char **line_divided;
	t_token *new_node;
	t_token *new_list;

	n = 0;
	new_list = NULL;
	n_pipes = how_many_pipes(str) + 1;
	master->n_cmds = n_pipes;
	line_divided = line_divided_in_tokens(str, n_pipes);
	while (n_pipes > n)
	{
		new_node = ft_newnode(clean_word(line_divided[n]));
		if (new_list == NULL)
			new_list = new_node;
		else
			lst_add_back(&new_list, new_node);
		n++;
	}
	free(line_divided);
	master->node = new_list;
	return (new_list);
}
