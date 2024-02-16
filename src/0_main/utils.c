/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:31:30 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 10:27:22 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	syntax_error(char *str, char c, int out)
{
	ft_putstr_fd(str, 2);
	if (c > 0)
	{
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\'', 2);
		ft_putchar_fd('\n', 2);
	}
	g_err = 2;
	return (out);
}

// true = diferente a 0
// false = igual a 0
bool	is_space(unsigned char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	else
		return (false);
}

/*esta funcion mira donde esta la siguiente quote para saltar todo lo que hay dentro*/
int next_quote(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}
