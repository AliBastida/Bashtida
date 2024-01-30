/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:35:41 by abastida          #+#    #+#             */
/*   Updated: 2024/01/30 14:13:19 by abastida         ###   ########.fr       */
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
	new->word = content;
	new -> next = NULL;
	return (new);
}

char *divided_by_word(t_token *tmp)
{
	int i;
	int start;
	int ret;

	i = 0;
	while (tmp->content_token[i] == ' ')
		i++;
	start = i;
	ret = is_redir(tmp->content_token, i);
	if (ret == 2)
		i++;
	while (tmp->content_token[i])
	{
		if (tmp->content_token[i] == '\'' || tmp->content_token[i] == '\"')
			i = next_quote(tmp->content_token, i + 1, tmp->content_token[i]);
		if (ret || (!is_space(tmp->content_token[i]) && (is_space(tmp->content_token[i + 1]) || is_redir(tmp->content_token, i + 1) || tmp->content_token[i + 1] == '\0')))
			return (substr_words(tmp, start, i));
		i++;
	}
	return (NULL);
}
// TODO: ESTA VA EN UTILS_NODES.
char *substr_words(t_token *tmp, int start, int i)
{
	char *new;
	char *rest;
	new = ft_substr(tmp->content_token, start, i - start + 1); // hemos hecho un sbstr de new y obtendremos rest que es lo que usaremos como nuevo tmp en la funcion create_nodeand list_word
	printf("new: ***%s***\n", new);
	rest = ft_substr(tmp->content_token, i + 1, ft_strlen(tmp->content_token));
	printf("resto: -%s-\n", rest);
	free(tmp->content_token);
	tmp->content_token = rest;
	return new;
}
// TODO: separar cmd + argumentos. Si el argumento esta "" hacemos NULL y pasamos al siguiente nodo
// TODO: Gestionar comillas simples. Que devuelva lo que hemos metido

// TODO: NO PODEMOS OLVIDAR QUE ESTA FUNCION HA DE PASAR POR TODOS LOS T_TOKEN QUE CREEMOS, PORQUE HA DE SEPARAR LAS PALABRAS EN TODOS LOS TOKENS.

t_word *create_nodeandlist_word(t_master *master, t_token *token)
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
				lst_add_back_word(&new_list, new);
			n++;
		}

		PRINT_WORD(new_list);
		tmp->words = new_list;
		check_dollar(tmp, master->env);
		saving_cmd(new_list, master);
		tmp = tmp->next;
	}
	return (new_list);
}
