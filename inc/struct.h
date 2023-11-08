/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:47:58 by abastida          #+#    #+#             */
/*   Updated: 2023/11/08 11:42:15 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_word
{
    char *word;
    int single_quotes;
    struct s_word *next;
}t_word;

typedef struct s_token
{
    char    *content_token; 
    char    **word_node;
    t_word  *words;
    struct s_token  *next;
}t_token;

typedef struct s_master
{
	char *line;
    char *clean_line;
   
	int n_pipes;
    t_token *node;
}t_master;

#endif