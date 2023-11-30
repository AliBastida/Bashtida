/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:40:43 by abastida          #+#    #+#             */
/*   Updated: 2023/11/30 12:21:39 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// Con esta funcion crearemos el nuevo nodo

char *clean_word(char *str)
{
    char *clean_line;

	clean_line = ft_strtrim(str, " ");
    free(str);
    return (clean_line);
}

t_token	*ft_newnode(void *content)
{
	t_token	*new;

	new = ft_calloc(sizeof(t_token), 1);
	if (!new)
		return (NULL);
	new ->content_token = content;
	new -> next = NULL;
	return (new);
}

// Esta es nuestra funcion para crear la lista con el rdo de line_divided_in_tokens nos lo guardara en un nuevo nodo
// (new_node) en funcion de los pipes que encuentra (n).

t_token *create_nodeandlist(t_master *master, char *str)
{
    t_token *new_node;
    t_token *tmp;
    t_token *new_list;
    int n_pipes;
    int len;
    char **line_divided;
    int n;

    len = 0;
    n_pipes = how_many_pipes(str) + 1;
    line_divided = line_divided_in_tokens(str);
    new_list = NULL;
    printf("---line divided: %s---\n", *line_divided);
    n = 0;
    while (n_pipes > n)
	{
		new_node = ft_newnode(clean_word(line_divided[n]));
        if (new_list == NULL)
            new_list = new_node;
        else
         lst_add_back(&new_list, new_node);
        n++;
	}

	tmp = new_list;
    while (tmp!= NULL)
	{
		// printf("list-> **%s**\n", tmp->content_token);
		// len = len_nodes(tmp->content_token);
		// printf("len: %d\n", len);
		tmp = tmp->next;
	}
	free(line_divided);
    master->node = new_list;
    return (new_list);
}

//FIXME: BORRAR TMP Y EL WHILE QUE IMPRIME LA LISTA
