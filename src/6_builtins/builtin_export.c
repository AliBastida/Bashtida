/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:59:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/12 18:56:12 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void adding_export(t_master *master, char **args, int i)
{
	char *arg;
	t_list *aux;
	int len;

	aux = master->env;
	len = len_hastaeligualymas(args[i]);
	arg = copyvble(args[i], len);
	if (checking_format(arg) == 0)
	{
		arg = ft_strjoin(arg, "=");
		printf("arg: ---%s----\n", args[i]);
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
		PRINT_LIST(master->env);
	}
	free(arg);
}

static void swapping_nodes(t_list **env)
{
	t_list *first;
	t_list *second;

	first = *env;
	if (!first || !first->next)
		return;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second = *env;
}

static void ordering_alphabetic(t_list **env)
{
	t_list *tmp;

	tmp = *env;
	while (tmp && tmp->next)
	{
		if (ft_strncmp(tmp->content, tmp->next->content, ft_strlen(tmp->content)) > 0)
		{
			swapping_nodes(&tmp);
		}
		else
			tmp = tmp->next;
	}
	// if (ft_strncmp (env->content, env->next->content) > 0)
	//	swap(env->content, env->next->content)
	// env = env->next;
}

int builtin_export(t_master *master, char **args)
{
	// char *arg;
	// t_list *aux;
	int i;
	// int len;

	i = 1;
	// aux = master->env;
	if (!args[i])
	{
		ordering_alphabetic(&master->env);
		PRINT_LIST(master->env);
	}
	printf("declare -x\n"); // FIXME: TIENE QUE IMPRIMIR TODAS LAS VV DE ENTORNO EN ORDEN ALFABETICO CON ESA LINEA DELANTE.
	while (args[i])
	{
		adding_export(master, args, i);
		i++;
	}
	return (0);
}
