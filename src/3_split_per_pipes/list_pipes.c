/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:40:43 by abastida          #+#    #+#             */
/*   Updated: 2023/11/03 14:31:13 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// Con esta funcion crearemos el nuevo nodo
t_token	*ft_newnode(void *content)
{
	t_token	*new;

	new = ft_calloc(sizeof(t_token), 1);
	if (!new)
		return (NULL);
	new ->content_token = content;
    printf("content: %s\n", new->content_token);
	new -> next = NULL;
	return (new);
}

// Esta es nuestra funcion para crear la lista con el rdo de line_divided_in_tokens nos lo guardara en un nuevo nodo
// (new_node) en funcion de los pipes que encuentra (n). 
void *create_node(char *str, t_master *master)
{
    t_token *new_node;
    t_token *last;
    t_token *tmp;
    char **line_divided;
    int n;
    
    master ->n_pipes = how_many_pipes(str) + 1;
    printf("n_pipes %d\n", master->n_pipes);
    line_divided = line_divided_in_tokens(str);
    n = 0;
    while (master -> n_pipes > n)
    { 
        new_node = ft_newnode(line_divided[n]);
        printf("token: %s\n", new_node->content_token);
        lst_add_back(&master->node, new_node);
        last = lst_last(&new_node);
        printf("last: %s\n", last->content_token); 
        n++;
    }
    tmp = master->node;
    while (tmp != NULL)
    {
        printf("list-> %s\n", tmp->content_token);
        tmp = tmp->next;
    }
    return (0);
}

//FIXME: BORRAR TMP Y EL WHILE QUE IMPRIME LA LISTA
