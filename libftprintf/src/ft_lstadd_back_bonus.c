/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:33:21 by abastida          #+#    #+#             */
/*   Updated: 2022/06/14 11:58:16 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux_lst;

	aux_lst = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (aux_lst -> next != NULL)
		{
			aux_lst = aux_lst -> next;
		}
		aux_lst -> next = new;
	}
}
