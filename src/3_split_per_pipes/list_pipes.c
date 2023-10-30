/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:40:43 by abastida          #+#    #+#             */
/*   Updated: 2023/10/21 17:39:38 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_newnode(void *content)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new ->content_token = content;
	new -> next = NULL;
	return (new);
}

void create_list(char *str)
{
    int i;
    int n_pipes;
    t_token *new_node;

    i = 0;
    n_pipes = num_pipes(str);
    printf("n_pipes %d\n", n_pipes);
    new_node = NULL;
    while (i < n_pipes)
    {
        if (i == 0)
            new_node = ft_newnode(checking_pipe_quoted(str, true));
        else
            new_node = ft_newnode(checking_pipe_quoted(str, false));
        i++;
        printf("%s\n", new_node->content_token);
    }
}
