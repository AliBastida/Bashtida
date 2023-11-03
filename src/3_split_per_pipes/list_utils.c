/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:23:56 by abastida          #+#    #+#             */
/*   Updated: 2023/11/03 13:48:33 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*lst_last(t_token **lst)
{
	t_token	*temp;

	temp = *lst;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	return (temp);
}
void	lst_add_back(t_token **first, t_token *new_node)
{
	t_token	*temp;

	if (*first == NULL)
		*first = new_node;
	else
	{
		temp = lst_last(first);
		temp->next = new_node;
	}
}