/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:35:41 by abastida          #+#    #+#             */
/*   Updated: 2024/01/08 13:34:17 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*lst_last_word(t_word **lst)
{
	t_word	*temp;

	temp = *lst;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	return (temp);
}


void	lst_add_back_word(t_word **first, t_word *new_node)
{
	t_word	*temp;

	if (*first == NULL)
		*first = new_node;
	else
	{
		temp = lst_last_word(first);
		temp->next = new_node;
	}
}


t_word	*ft_newnode_word(void *content)
{
	t_word	*new;

	new = ft_calloc(sizeof(t_token), 1);
	if (!new)
		return (NULL);
	new ->word = content;
	new -> next = NULL;
	return (new);
}

char *divided_by_word(t_token *node)
{
	int i;
	t_token *tmp;
	char *new;
	int start;
	char *rest;

	i = 0;
	tmp = node;
	start = 0;
	new = NULL;
	while (tmp->content_token[i])
	{
		if ((i == 0 || (is_space(tmp->content_token[i - 1]))) && !is_space(tmp->content_token[i]))
			start = i;
		if (tmp->content_token[i] == '\'' || tmp->content_token[i] == '\"')
			i = next_quote(tmp->content_token, i + 1, tmp->content_token[i]);
		if (!is_space(tmp->content_token[i]) && (is_space(tmp->content_token[i + 1]) || tmp->content_token[i + 1] == '\0'))
		{
			new = ft_substr(tmp->content_token, start, i - start + 1); // hemos hecho un sbstr de new y obtendremos rest que es lo que usaremos como nuevo tmp en la funcion create_nodeand list_word
			printf("new: ***%s***\n", new);
			rest = ft_substr(tmp->content_token, i + 1, ft_strlen(tmp->content_token));
			printf("resto: %s\n", rest);
			free(tmp->content_token);
			tmp->content_token = rest;
			break;
		}
		i++;
	}
   return(new);
}

t_word *create_nodeandlist_word(t_token *token, const char **env)
{
	int n;
	int n_words;
	t_word *new_list;
	t_word *new;
	t_token *tmp;

	tmp = token;
	while (tmp)
	{
		n = 0;
		new_list = NULL;
		n_words = len_nodes(tmp->content_token);
		while (n_words > n)
		{
			new = ft_newnode_word(divided_by_word(tmp));
			if (!new)
				return (NULL);
			if (new_list == NULL)
				new_list = new;
			else
			{
				lst_add_back_word(&new_list, new);
			}
			n++;
		}
		tmp->words = new_list;
		new = new_list;
		check_dollar(tmp, env);
		/*while (new) // TODO: quitar el while con cariño porque da segfault si lo quitamos sin mas.
		{
			printf("list-> **%s**\n", new->word);
			categorizing_words(new);
			check_to_expand(new);

			printf("--%d--\n", new->type);
			printf("n_words: %d\n", n_words);
			new = new->next;*/
		tmp = tmp->next;
	}
	return (new_list);
}
// TODO: cuando tngamos reservado, recorreremos la str analizando si hay $, si hay '', y sabiendo que la primera posicion del array ** es cmd. (son todos los del env.).
