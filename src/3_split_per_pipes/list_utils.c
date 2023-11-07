/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:23:56 by abastida          #+#    #+#             */
/*   Updated: 2023/11/07 15:01:33 by abastida         ###   ########.fr       */
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

void	lstdelone(t_token *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst -> content_token);
	free (lst);
}


void	lstclear(t_token **lst, void (*del)(void*))
{
	t_token	*keeper;

	if (!*lst)
		return ;
	while (*lst)
	{
		keeper = (*lst)->next;
		lstdelone(*lst, del);
		*lst = keeper;
	}
	*lst = NULL;
}
