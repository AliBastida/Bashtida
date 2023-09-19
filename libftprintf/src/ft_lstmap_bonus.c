/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:12:08 by abastida          #+#    #+#             */
/*   Updated: 2022/06/14 12:01:56 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void*(*f) (void *), void (*del) (void *))
{
	t_list	*new;
	t_list	*first;
	void	*new_content;

	first = NULL;
	while (lst)
	{
		new_content = f(lst -> content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			free (new_content);
			ft_lstclear (&first, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&first, new);
		lst = lst -> next;
	}
	return (first);
}
