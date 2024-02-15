/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:35:41 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 18:27:53 by pabastid         ###   ########.fr       */
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
	new->next = NULL;
	return (new);
}

char	*divided_by_word(t_token *tmp)
{
	int	i;
	int	start;
	int	ret;

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
		if (ret || (!is_space(tmp->content_token[i])
				&& (is_space(tmp->content_token[i + 1])
					|| is_redir(tmp->content_token, i + 1)
					|| tmp->content_token[i + 1] == '\0')))
			return (substr_words(tmp, start, i));
		i++;
	}
	return (NULL);
}

// TODO: HAY QUE CHEQUEAR SI EL N++ SE PUEDE PONER DONDE LO HE PUESTO O DEBE IR ABAJO
t_word	*create_nodeandlist_word(t_master *master, t_token *token)
{
	t_word	*new_list;
	t_word	*new;
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		new_list = NULL;
		while (tmp->content_token)
		{
			new = ft_newnode_word(divided_by_word(tmp));
			if (!new)
				exit();
			categorizing_words(new);
			if (new_list == NULL)
				new_list = new;
			else
				lst_add_back_word(&new_list, new);
		}
		tmp->words = new_list;
		line_ready_to_use(tmp, master);
		tmp = tmp->next;
	}
	master->cmds = create_list_cmd(token, master);
	return (new_list);
}
