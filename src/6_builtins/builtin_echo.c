/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:13:00 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 15:35:28 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TRUE SI HAY N
// FALSE NO HAY N
static bool	finding_n(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' && arg[1] == 'n')
	{
		i = 2;
		{
			while (arg[i] == 'n' && arg[i])
				i++;
			if (arg[i] == '\0')
				return (true);
		}
	}
	return (false);
}

int	builtin_echo(char **args)
{
	int		i;
	bool	found_n;

	i = 1;
	found_n = true;
	if (!args[i])
		printf("\n");
	while (args[i] && finding_n(args[i]) == true)
	{
		found_n = false;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (found_n == true)
		printf("\n");
	return (0);
}
