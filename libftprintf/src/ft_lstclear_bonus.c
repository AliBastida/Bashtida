/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:18:32 by abastida          #+#    #+#             */
/*   Updated: 2022/06/14 11:59:48 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*keeper;

	if (!*lst)
		return ;
	while (*lst)
	{
		keeper = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = keeper;
	}
	*lst = NULL;
}
