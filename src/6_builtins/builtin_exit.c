/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:56:31 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/15 18:33:01 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	checking_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

static void	exit_valid_arguments(char *str)
{
	long long int	valid_num;

	valid_num = ft_atol(str);
	valid_num = valid_num % 256;
	printf("exit\n");
	exit(valid_num);
}

int	builtin_exit(char **args)
{
	if (!args[1])
	{
		write(2, "exit\n", 5);
		exit(0);
	}
	if (args[1])
	{
		if (checking_numbers(args[1]) == 1)
			printf("bashtida: exit: %s: numeric argument required\n", args[1]);
		else if (!args[2])
			exit_valid_arguments(args[1]);
		else if (args[2])
		{
			printf("bashtida: exit: too many arguments\n");
			g_err = 1;
			return (1);
		}
		exit(255);
	}
	return (0);
}
// TODO: SALIDA CON 255?
