/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:59:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 08:56:20 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void adding_export_continue(t_master *master, char **args, int i)
{
	char *arg;
	t_list *aux;
	int len;

	aux = master->env;
	len = len_hastaeligualymas(args[i]);
	arg = copyvble(args[i], len);
	if (checking_format(arg) == 0)
		arg = ft_strjoin(arg, "=");
	if (get_envnode_export(master->env, arg))
	{
		aux = get_envnode_export(master->env, arg);
		aux->content = ft_strdup(ft_strjoin(arg, ft_strchr_export(args[i], '=')));
	}
		else
		{
			arg = ft_strjoin(arg, ft_strchr_export(args[i], '='));
			ft_lstadd_back(&master->env, ft_lstnew(ft_strdup(arg)));
		}
		free(arg);
}

// esta funcion hace trabajar realmente export: trabaja en el caso concreto de que nos den la vble con =, sin =, con el +=
// y si la vble la encuentra en el env la sustituimos por el nuevo valor con strdup si es nueva, la anade al final
static void adding_export(t_master *master, char **args, int i)
{
	char *arg;
	int len;

	len = len_hastaeligualymas(args[i]);
	if (args[i][len] && (checking_format(args[i]) == 0) && ((args[i][len + 1] == '\0' || args[i][len + 2] == '\0')))
	{
		arg = copyvble(args[i], len);
		arg = ft_strdup(ft_strjoin(arg, "=\"\""));
		ft_lstadd_back(&master->env, ft_lstnew(ft_strdup(arg)));
		free(arg);
	}

	else
		adding_export_continue(master, args, i);
}

void static print_export(char **arr)
{
	int i;

	i = 0;
	if (arr == NULL)
		return;
	while (arr[i] != NULL)
	{
		printf("declare -x %s\n", arr[i]);
		i++;
	}
}

static void swapping(char **env, size_t size)
{
	char *tmp;
	size_t i;
	size_t j;
	size_t j_min;

	i = -1;
	while (++i < size - 1)
	{
		j_min = i;
		j = i;
		while (++j < size)
		{
			if (env[j_min] && env[j] && ft_strcmp(env[j], env[j_min]) < 0)
				j_min = j;
		}
		if (j_min != i)
		{
			tmp = env[i];
			env[i] = env[j_min];
			env[j_min] = tmp;
		}
	}
	print_export(env);
}

int builtin_export(t_master *master, char **args)
{
	int i;
	char **list_char; // int len;

	i = 1;
	if (!args[i])
	{
		list_char = converting(master->env);
		swapping(list_char, ft_len_dptr(list_char));
		free(list_char);
	}
	while (args[i])
	{
		adding_export(master, args, i);
		i++;
	}
	return (0);
}
