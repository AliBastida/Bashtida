/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:59:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 18:06:53 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void adding_export_continue(t_master *master, char **args, int i)
// {
// 	int len;
// 	char *arg;
// 	t_list *aux;

// 	len = len_until_equal(args[i]);
// 	if (checking_format(args[i]) == 1)
// 	{
// 		printf("bashtida: export: %s': not a valid identifier\n", args[i]);
// 		return ;
// 	}
// 	arg = copyvble(args[i], len);
// 	if (checking_format(arg) == 0)
// 		arg = ft_strjoin(arg, "=");
// 	if (!arg)
// 		exit_error("Malloc error");
// 	if (get_envnode_export(master->env, arg))
// 	{
// 		aux = get_envnode_export(master->env, arg);
// 		aux->content = ft_strdup(ft_strjoin(arg, ft_strchr_export(args[i],
// 																	'=')));
// 		if (!aux->content)
// 			exit_error("Malloc error");
// 	}
// 	else if ((checking_format(arg) == 0))
// 	{
// 		arg = ft_strjoin(arg, ft_strchr_export(args[i], '='));
// 		if (!arg)
// 			exit_error("Malloc error");
// 		ft_lstadd_back(&master->env, ft_lstnew(ft_strdup(arg)));
// 	}
// 	free(arg);
// }

// esta funcion hace trabajar realmente export: trabaja en el caso
// concreto de que nos den la vble con =, sin =, con el +=
// y si la vble la encuentra en el env la sustituimos por el nuevo
// valor con strdup si es nueva, la anade al final
// static void adding_export(t_master *master, char **args, int i)
// {
// 	int len;
// 	char *arg;
// 	t_list *aux;

// 	aux = master->env;
// 	len = len_until_equal(args[i]);
// 	if (args[i][len] && (checking_format(args[i]) == 0) && ((args[i][len
// + 1] == '\0' || args[i][len + 2] == '\0')))
// 	{
// 		arg = copyvble(args[i], len);
// 		arg = ft_strdup(ft_strjoin(arg, "=\"\""));
// 		if (!arg)
// 			exit_error("Malloc error");
// 		ft_lstadd_back(&master->env, ft_lstnew(ft_strdup(arg)));
// 		free(arg);
// 	}
// 	else
// 		adding_export_continue(master, args, i);
// }

char	*take_out_plus(char *str)
{
	char	*new;
	char	*tmp;

	tmp = ft_substr(str, 0, ft_strchr(str, '+') - str);
	if (!tmp)
		exit_error("Malloc error\n");
	new = ft_strjoin(tmp, ft_strchr(str, '+') + 1);
	if (!new)
		exit_error("Malloc error\n");
	free(tmp);
	return (new);
}

static void	adding_export_continue(t_master *master, char *arg)
{
	char	*new;
	t_list	*aux;

	aux = get_envnode_export(master->env, arg);
	if (aux)
	{
		if (ft_strchr(arg, '+'))
			join_var(aux, arg);
		else
		{
			free(aux->content);
			aux->content = ft_strdup(arg);
		}
	}
	else
	{
		new = take_out_plus(arg);
		aux = ft_lstnew(new);
		ft_lstadd_back(&master->env, aux);
	}
}

static void	adding_export(t_master *master, char *arg)
{
	int		len;
	char	*new;

	len = len_until_equal(arg);
	if (checking_format(arg))
	{
		printf("bashtida: export: %s': not a valid identifier\n", arg);
		return ;
	}
	if (!arg[len] || (arg[len] && arg[len + 1] == '\0'))
	{
		new = ft_strjoin(arg, "=\"\"");
		if (!new)
			exit_error("Malloc error\n");
		ft_lstadd_back(&master->env, ft_lstnew(new));
	}
	else
		adding_export_continue(master, arg);
}

// static void	print_export(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	if (arr == NULL)
// 		return ;
// 	while (arr[i] != NULL)
// 	{
// 		printf("declare -x %s\n", arr[i]);
// 		i++;
// 	}
// }

static void	swapping(char **env, size_t size)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	j_min;

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
	// print_export(env);
}

int	builtin_export(t_master *master, char **args)
{
	int		i;
	int		j;
	char	*tmp;
	char	**list_char;

	i = 0;
	j = -1;
	if (!args[i + 1])
	{
		list_char = converting(master->env);
		swapping(list_char, ft_len_dptr(list_char));
		while (list_char[++j])
		{
			tmp = ft_strjoin(ft_substr(list_char[j], 0, ft_strchr(list_char[j],
							'=') - list_char[j] + 1), "\"");
			if (!tmp)
				exit_error("Malloc error\n");
			printf("declare -x %s%s\"\n", tmp, ft_strchr(list_char[j], '=')
				+ 1);
			free(tmp);
		}
		free(list_char);
		// TODO free normal de un doble puntero??????????????????????????
	}
	while (args[++i])
	{
		// adding_export(master, args, i);
		adding_export(master, args[i]);
	}
	return (0);
}
