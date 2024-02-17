/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:35:20 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 18:16:47 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd *new_cmd(t_word *words, int n)
{
	t_cmd *new;

	new = ft_calloc(sizeof(t_cmd), 1);
	if (!new)
		exit_error("Malloc error");
	new->n = n;
	new->out_fd = 1;
	new->args = ft_calloc(sizeof(char *), n_args(words) + 1);
	if (!new->args)
		exit_error("Malloc error");
	return (new);
}

static t_cmd *create_node_cmd(t_word *words, t_master *master, int n)
{
	int i;
	t_cmd *new;
	t_word *tmp;

	i = 0;
	tmp = words;
	new = new_cmd(words, n);
	if (!new)
		return (NULL);
	while (tmp)
	{
		if (tmp->type == 1 || tmp->type == 2 || tmp->type == 3 || tmp->type == 4)
		{
			manage_redir(tmp, new);
			tmp = tmp->next;
		}
		else
			new->args[i++] = ft_strdup(tmp->word);
		tmp = tmp->next;
	}
	if (new->args[0])
		ft_take_cmd(new, master);
	return (new);
}

t_cmd *create_list_cmd(t_token *token, t_master *master)
{
	int		i;
	t_cmd	*list;
	t_cmd	*node;
	t_token	*tmp;

	i = 0;
	tmp = token;
	list = NULL;
	while (tmp)
	{
		// PRINT_WORD(tmp->words);
		node = create_node_cmd(tmp->words, master, i);
		if (!node)
			exit_error("Malloc error");
		if (list == NULL)
			list = node;
		else
			lst_add_back_cmd(list, node);
		tmp = tmp->next;
		i++;
	}
	return (list);
}
