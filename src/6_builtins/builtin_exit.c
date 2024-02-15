/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:56:31 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/15 10:01:28 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// hacer funcion que reciba el valor y printea el error: ***no entiendo xq reccibe char *str como args[i]

// hacer una funcion que chequea si args[i] es numero valido:
// * ft_isdigit
// * atoi
// * max y min
// 0 - 255
long long int ft_atol(char *str)
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

static int checking_numbers(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}
static void exit_valid_arguments(char *str)
{
	long long int valid_num;

	valid_num = ft_atol(str);
	valid_num = valid_num % 256;
	printf("exit\n");
	exit(valid_num);
}
void builtin_exit(char **args)
{
	if (!args[1])
	{
		if (isatty(STDIN_FILENO))
		{
			write(2, "exit\n", 6);
			exit(0);
		}
	}
	if (args[1] || args[2])
	{
		if (checking_numbers(args[1]) == 1) //--> comprueba si el primer argumento es solo numero, si es, pasa al siguiente if y comprueba que no haya mas de un argumento, por lo que entra y gestiona argumentos validos.
			printf("bashtida: exit: %s: numeric argument required\n", args[1]);
		else if (!args[2])
			exit_valid_arguments(args[1]);
		else if (args[2])
			printf("bashtida: exit: too many arguments\n");
		exit(0);
		// too many arguments
		// funcion exit_error (args[i], long long int *value, int mode) -> funccioon que gestionara con el atol = value
	}
}
// TODO: SALIDA CON 255?
