/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 06:34:22 by abastida          #+#    #+#             */
/*   Updated: 2024/02/04 12:39:39 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*lst_last_cmd(t_cmd *list)
{
	t_cmd	*tmp;

	tmp = list;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	return (tmp);
}

int	n_args(t_word *words)
{
	int	i;

	i = 0;
	while (words)
	{
		if (words->type == 1 || words->type == 2 || words->type == 3
			|| words->type == 4)
			words = words->next;
		else
			i++;
		words = words->next;
	}
	return (i);
}

void	lst_add_back_cmd(t_cmd *list, t_cmd *node)
{
	t_cmd	*tmp;

	if (list == NULL)
		list = node;
	else
	{
		tmp = lst_last_cmd(list);
		tmp->next = node;
	}
}
