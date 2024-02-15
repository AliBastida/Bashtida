/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:56:31 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/14 18:32:45 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// hacer funcion que reciba el valor y printea el error: ***no entiendo xq reccibe char *str como args[i]

// hacer una funcion que chequea si args[i] es numero valido:
// * ft_isdigit
// * atoi
// * max y min
// 0 - 255
long long int ft_atol(const char *str)
{
	int sign;
	long long int res;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f' || *str == '\n' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res > ((LONG_MAX - '0') / 10))
			return (0);
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (*str != '\0' && *str != ' ')
		return (0);
	res = res * sign;
	return (res);
}

int builtin_exit(char **args)
{
	long long int value;

	value = 0;
	if (!args[1])
	// -> // cuando es solo exit
	{
		if (isatty(STDIN_FILENO))
		{
			write(2, "exit\n", 6);
			exit(0);
		}
	}
	if (args[2] && atol(args[2]) == 0)
	{
		// if (atol == 0)
		// -> // argument required
		// else
		// too many arguments
		// funcion exit_error (args[i], long long int *value, int mode) -> funccioon que gestionara con el atol = value
	}
	// if (args[2] && atol(args[2] != 0))
	// -> // success
	return (0);
}
