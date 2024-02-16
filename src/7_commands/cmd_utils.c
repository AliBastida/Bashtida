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

static t_cmd *lst_last_cmd(t_cmd *list)
{
	t_cmd *tmp;

	tmp = list;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	return (tmp);
}

// Aqui averiguamos el len para el malloc de la lista de args
int n_args(t_word *words)
{
	int i;

	i = 0;
	while (words)
	{
		if (words->type == 1 || words->type == 2 || words->type == 3 || words->type == 4)
			words = words->next;
		else
			i++;
		words = words->next;
	}
	return (i);
}

// char **take_path(t_master *master)
// {
// 	char *path;
// 	char **split;

// 	int i = 0;
// 	path = ft_strdup(ft_getenv("PATH", master->env, -1));
// 	split = ft_split(path, ':');
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	free(path);
// 	return (split);
// }

void lst_add_back_cmd(t_cmd *list, t_cmd *node)
{
	t_cmd *tmp;

	if (list == NULL)
		list = node;
	else
	{
		tmp = lst_last_cmd(list);
		tmp->next = node;
	}
}
