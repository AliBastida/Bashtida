/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:17:07 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/16 18:07:10 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*get_envnode_unset(t_list **env, char *arg)
{
	int		arg_len;
	t_list	*tmp;

	tmp = *env;
	arg_len = ft_strlen(arg);
	while (tmp && tmp->next != NULL)
	{
		if (ft_strncmp((char *)tmp->next->content, arg, arg_len) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	delete_node(t_list *env)
{
	t_list	*aux;

	if (env)
	{
		aux = env->next;
		env->next = aux->next;
		free(aux);
	}
}

int	builtin_unset(t_list **env, char **args)
{
	int		i;
	char	*arg;
	t_list	*aux;

	i = 1;
	while (args[i])
	{
		arg = ft_strjoin(args[i], "=");
		if (!arg)
			exit_error("Malloc error");
		if (ft_strncmp((char *)(*env)->content, arg, ft_strlen(arg)) == 0)
		{
			aux = (*env)->next;
			free(*env);
			*env = aux;
		}
		else
			delete_node(get_envnode_unset(env, arg));
		free(arg);
		i++;
	}
	return (0);
}
