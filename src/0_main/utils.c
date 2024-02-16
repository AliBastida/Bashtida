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

void	free_all(t_master *master)
{
	if (master->line)
		free(master->line);
	if (master->clean_line)
		free(master->clean_line);
	if (master->cmds)
		free_cmds(master->cmds);
	if (master->node)
		free_tokens(master->node);
	if (master->env)
		ft_lstclear(&master->env, &free);
	free(master);
}
