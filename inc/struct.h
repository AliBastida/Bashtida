/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:47:58 by abastida          #+#    #+#             */
/*   Updated: 2023/12/06 16:33:59 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

enum e_token_type
{
	WORD,
	REDIR_A,
	REDIR_B,
	REDIR_C,
	REDIR_D,
	DOLLAR,
};

typedef struct s_word
{
	char *word;
	int single_quotes;
	int type;
	int flag_quote;
	struct s_word *next;
} t_word;

typedef struct s_token
{
	char *content_token;
	char **word_node;
	t_word *words;
	struct s_token *next;
} t_token;

typedef struct s_master
{
	char *line;
    char *clean_line;
	int n_pipes;
    t_token *node;
	t_list *env;
}t_master;

#endif
