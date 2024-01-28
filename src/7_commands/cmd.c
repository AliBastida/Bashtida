/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:32 by abastida          #+#    #+#             */
/*   Updated: 2024/01/28 21:17:00 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// TODO: ESTA FUNCION HAY QUE CAMBIARLA ENTERA
t_cmd *saving_cmd(t_word *words)
{
	t_cmd *new;
	t_word *wd;
	int i;
	int j;

	new = ft_calloc(sizeof(t_cmd), 1);
	wd = words;
	i = 0;
	j = 0;
	if (!new)
		return (NULL);
	new->args = NULL;
	new->next = NULL;
	while (wd->word && wd->word[i])
	{
		i = 0;
		while (is_redir(wd->word, i) == 0)
		{
			new->args[j][i] = wd->word[i];
			i++;
		}
		j++;
		wd = wd->next;
	}
	return (new);
}
