/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:40:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/01 12:05:14 by abastida         ###   ########.fr       */
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
	t_token *new_list;
	int n_pipes;
	char **line_divided;
    int n;

	n = 0;
	new_list = NULL;
	n_pipes = how_many_pipes(str) + 1;
	line_divided = line_divided_in_tokens(str);
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

//FIXME: BORRAR TMP Y EL WHILE QUE IMPRIME LA LISTA
