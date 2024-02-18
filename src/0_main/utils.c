/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:31:30 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 15:19:47 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**converting(t_list *env)
{
	int		i;
	char	**env_char;

	i = 0;
	env_char = ft_calloc(sizeof(char *), (ft_lstsize(env) + 1));
	if (!env_char)
		exit_error("Malloc error\n");
	while (env && env->content)
	{
		env_char[i] = ft_strdup(env->content);
		if (!env_char[i])
			exit_error("Malloc error\n");
		env = env->next;
		i++;
	}
	return (env_char);
}

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

bool	is_space(unsigned char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	else
		return (false);
}

int	next_quote(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}
