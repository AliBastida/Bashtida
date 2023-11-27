/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:35:41 by abastida          #+#    #+#             */
/*   Updated: 2023/11/27 15:17:17 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
t_word *running_through_nodes(t_token *token)
{
    t_token *tmp;
    int i;

    tmp = token;
    i = 0;
    while (tmp != NULL)
    {   
        while (tmp->content_token[i])
        {
           
            if (tmp->content_token[i] == '>')
                printf("Holaaaaaaaaaa1\n");
            else if (tmp->content_token[i] == '$')
                printf("ciaooooooo2\n");
            i++;
        }
        i = 0;
        printf("numero de palabras por nodo:%s\n", divided_by_word(tmp));
        tmp = tmp->next;
    }
    if(!tmp)
        tmp = create_nodeandlist(token->content_token);
    else
        tmp = create_nodeandlist(token->content_token);
    printf("%s\n", tmp->content_token);
    return (0);
} */