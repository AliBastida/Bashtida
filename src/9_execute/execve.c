/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:52:12 by abastida          #+#    #+#             */
/*   Updated: 2024/02/06 12:59:52 by vduchi           ###   ########.fr       */
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
			check_pipes(tmp, pipes);
			env = converting(master->env);
			// si es un builtin ejecuta el builtin; si no, ejecuta exeve;
			// cada funcion debe devolver un int, y ese int (valor de salida) lo ponemos como argumento en el exit)
			if (is_builtin(tmp->cmd) == true)
			{
				/*if (ft_strncmp(cmd, "echo", 5) == 0)
					ejecuta funcion echo;
				else if (ft_strcmp(cmd, "pwd", 4) == 0)
					ejecuta funcion pwd;*/
				if (ft_strncmp(tmp->cmd, "cd", 3) == 0) //
					builtin_cd(tmp->args[1]);
				/*else if (ft_strcmp(cmd, "export", 7) == 0)
					ejecuta funcion export;
				else if (ft_strcmp(cmd, "unset", 6) == 0)
					ejecuta funcion unset;
				else if (ft_strcmp(cmd, "env", 4) == 0)
					ejecuta funcion env;
				else if (ft_strcmp(cmd, "exit", 5) == 0)
					ejecuta funcion exit;*/
				exit(0);
			}
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
