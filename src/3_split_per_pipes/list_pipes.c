/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:40:43 by abastida          #+#    #+#             */
/*   Updated: 2023/11/02 14:16:19 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void *create_list(char *str, t_master *master)
{
    t_token *new_node;
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
        new_node = new_node -> next;
        n++;
    }
    return (0);
}
