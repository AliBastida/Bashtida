/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:52:12 by abastida          #+#    #+#             */
/*   Updated: 2024/01/30 14:14:19 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// execve(cmd, args, env);
// tengo que hacer una funcion que me convierta la lista del env a char ** para pasarsela a la funcion exec_ve. Esta funcion sera llamada por exec_cmd y el retorno de la transformacion
// es lo que le pasare a execve.

int ft_lstsize(t_list *lst);

char **converting(t_list *env)
{
	char **env_char;
	int i;

	i = 0;
	env_char = ft_calloc(sizeof(char *), (ft_lstsize(env) + 1));
	if (!env_char)
		return (NULL);
	while (env && env->content)
	{
		env_char[i] = ft_strdup(env->content);
		printf("env-char[i]: %s\n", env_char[i]);
		env = env->next;
		i++;
	}
	return (env_char);
}

void exec_cmd(t_master *master)
{
	char **env = converting(master->env);
	// printf("Cmd: %p\n", master->cmds->cmd);
	// printf("Arg 0: %p\n", master->cmds->args[0]);
	if (execve(master->cmds->cmd, master->cmds->args, env) == -1)
		printf("%s", g_error_array[2]);
}
