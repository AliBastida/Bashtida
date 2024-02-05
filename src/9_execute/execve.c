/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:52:12 by abastida          #+#    #+#             */
/*   Updated: 2024/02/05 08:05:43 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// execve(cmd, args, env);
// tengo que hacer una funcion que me convierta la lista del env a char ** para pasarsela a la funcion exec_ve. Esta funcion sera llamada por exec_cmd y el retorno de la transformacion
// es lo que le pasare a execve.

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

// TODO gestionar la vable global $?
int execute_cmds(t_master *master)
{
	int status;
	pid_t pid;
	t_cmd *tmp;
	char **env;

	tmp = master->cmds;
	while (tmp)
	{
		if (tmp->hd)
			ft_take_heredoc(tmp);
		tmp = tmp->next;
	}
	tmp = master->cmds;
	while (tmp)
	{
		if (tmp->ok)
		{
			printf("%s\n", g_error_array[tmp->ok - 1]);
			tmp = tmp->next;
			continue ;
		}
		pid = fork();
		if (pid == -1)
		{
			printf("Fork error\n");
			return (0);
		}
		else if (pid == 0)
		{
			env = converting(master->env);
			execve(tmp->cmd, tmp->args, env);
			perror("Execve error");
			exit(1);
		}
		waitpid(pid, &status, 0);
		printf("Exit status: %d\n", WEXITSTATUS(status));
		g_err = WEXITSTATUS(status);
		tmp = tmp->next;
	}
	return (1);
}
