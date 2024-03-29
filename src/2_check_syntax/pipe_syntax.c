/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:38:29 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 15:13:37 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	something_before(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '|')
		return (1);
	return (0);
}

static bool	there_is_sth(char *str)
{
	if (something_before(str))
		return (1);
	str = ft_strchr(str, '|');
	while (str != NULL)
	{
		if (*str == *(str + 1))
			return (1);
		str = str + 1;
		if (something_before(str))
			return (1);
		str = ft_strchr(str, '|');
	}
	return (0);
}

static bool	something_after(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (str[len] == ' ')
		len--;
	if (str[len] == '|')
		return (1);
	return (0);
}

bool	check_syntax_pipes(char *str)
{
	if (!str)
		return (1);
	if (there_is_sth(str))
		return (1);
	if (something_after(str))
		return (1);
	return (0);
}
