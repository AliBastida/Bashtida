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
		if (ft_strchr(arg, '+'))
			new = take_out_plus(arg);
		else
			new = ft_strdup(arg);
		aux = ft_lstnew(new);
		ft_lstadd_back(&master->env, aux);
	}
}

// esta funcion hace trabajar realmente export: trabaja en el caso
// concreto de que nos den la vble con =, sin =, con el +=
// y si la vble la encuentra en el env la sustituimos por el nuevo
// valor con strdup si es nueva, la anade al final
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
}

int	builtin_export(t_master *master, char **args)
{
	int		i;
	int		j;
	char	*tmp;
	char	**list;

	i = 0;
	j = -1;
	if (!args[i + 1])
	{
		list = converting(master->env);
		swapping(list, ft_len_dptr(list));
		while (list[++j])
		{
			tmp = ft_strjoin(ft_substr(list[j], 0, ft_strchr(list[j], '=')
						- list[j] + 1), "\"");
			if (!tmp)
				exit_error("Malloc error\n");
			printf("declare -x %s%s\"\n", tmp, ft_strchr(list[j], '=') + 1);
			free(tmp);
		}
		ft_free_double(list);
	}
	while (args[++i])
		adding_export(master, args[i]);
	return (0);
}
