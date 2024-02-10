/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:59:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/10 18:27:30 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int len_hastaeligual(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

static char *copyvble(char *str, int size)
{
	int i;
	char *copy;

	copy = ft_calloc(size, sizeof(char));
	if (!copy)
		return (NULL);

	i = 0;
	while ((str[i] && str[i] != '=') && (i <= size))
	{
		copy[i] = str[i];
		printf("%d \t %d\n", i, size);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int checking_format(char *str)
{
	int i;
	size_t last_one;

	i = 0;
	last_one = ft_strlen(str);
	while (str[i])
	{
		if ((!ft_isalpha(str[0]) && str[0] != '_') || (i > 0 && (!ft_isdigit(str[i]) && !ft_isalpha(str[i]) && str[i] != '_')))
		{
			printf("not a valid identifier\n");
			// hay que guardar el error!!
			return (1);
		}
		else
			i++;
	}
	return (0);
	// TODO: TENEEMOS QUE CONTEMPLAR EL CASO DEL'+' antes de =
	//	el resto esta mal.
}

int builtin_export(t_list **env, char **args)
{
	char *arg;
	int i;
	(void)env;
	int len;

	i = 1;
	while (args[i])
	{
		len = len_hastaeligual(args[i]);
		arg = copyvble(args[i], len);
		if (checking_format(arg) == 0)
		{
			arg = ft_strjoin(arg, "=");
			if (ft_strncmp((char *)(*env)->content, arg, ft_strlen(arg)) == 0)
				printf("%s\t %s\n", (char *)(*env)->content, arg);
		}
		i++;
	}
	printf("arg: ---%s----\n", arg);
	free(arg);
	return (0);
}
