/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:40:43 by abastida          #+#    #+#             */
/*   Updated: 2023/11/15 15:34:01 by abastida         ###   ########.fr       */
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
   // printf("content: %s\n", new->content_token);
	new -> next = NULL;
	return (new);
}

// Esta es nuestra funcion para crear la lista con el rdo de line_divided_in_tokens nos lo guardara en un nuevo nodo
// (new_node) en funcion de los pipes que encuentra (n). 

t_token *create_nodeandlist(char *str, t_master *master)
{
    t_token *new_node;
    t_token *tmp;
    int len;
    char **line_divided;
    
    int n;
    len = 0;
    master->n_pipes = how_many_pipes(str) + 1;
    line_divided = line_divided_in_tokens(str);
    printf("---line divided: %s---\n", *line_divided);
    n = 0;
    while (master -> n_pipes > n)
    { 
        if (!line_divided[n])
            line_divided[n] = ft_strdup("");
        new_node = ft_newnode(clean_word(line_divided[n]));
        //printf("Content token: **%s**\n", new_node->content_token);
        lst_add_back(&master->node, new_node);
        n++;
    }
    tmp = master->node;
    while (tmp!= NULL)
    {  
        printf("list-> **%s**\n", tmp->content_token);
        len = len_nodes(tmp->content_token);
        printf("len: %d\n", len);
        tmp = tmp->next;
    }
    free(line_divided);
    return (new_node);
}

//FIXME: BORRAR TMP Y EL WHILE QUE IMPRIME LA LISTA
