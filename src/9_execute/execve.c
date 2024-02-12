/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:52:12 by abastida          #+#    #+#             */
/*   Updated: 2024/02/12 14:42:28 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// execve(cmd, args, env);
// tengo que hacer una funcion que me convierta la lista del env a char ** para pasarsela a la funcion exec_ve. Esta funcion sera llamada por exec_cmd y el retorno de la transformacion
// es lo que le pasare a execve.

int run_builtin(t_master *master, t_cmd *tmp)
{
	/*if (ft_strncmp(cmd, "echo", 5) == 0)
		ejecuta funcion echo;*/
	if (ft_strncmp(tmp->cmd, "pwd", 4) == 0)
		builtin_pwd();
	else if (ft_strncmp(tmp->cmd, "cd", 3) == 0)
		builtin_cd(tmp->args[1]);
	else if (ft_strncmp(tmp->cmd, "export", 7) == 0)
		builtin_export(master, tmp->args);
	else if (ft_strncmp(tmp->cmd, "unset", 6) == 0)
		builtin_unset(&master->env, tmp->args);
	else if (ft_strncmp(tmp->cmd, "env", 4) == 0)
		print_env(master->env);
	/*else if (ft_strncmp(cmd, "exit", 5) == 0)
		ejecuta funcion exit;*/
	return (0);
}

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
		// printf("env-char[i]: %s\n", env_char[i]);
		env = env->next;
		i++;
	}
	return (env_char);
}

void execute_heredoc(t_cmd *cmds)
{
	t_cmd *tmp;

	tmp = cmds;
	while (tmp)
	{
		if (tmp->hd)
			ft_take_heredoc(tmp);
		tmp = tmp->next;
	}
}

// TODO gestionar la vable global $?
int execute_cmds(t_master *master)
{
	int status;
	char **env;
	pid_t pid;
	t_cmd *tmp;
	t_pipes pipes;

	pipes.tmp_fd = -1;
	pipe(pipes.p);
	execute_heredoc(master->cmds);
	tmp = master->cmds;
	printf("N commands: %d\n", master->n_cmds);
	while (tmp)
	{
		if (check_cmd_and_pipes(tmp, &pipes))
		{
			tmp = tmp->next;
			continue;
		}
		if (!tmp->next && is_builtin(tmp->cmd))
			run_builtin(master, tmp);
		pid = fork();
		if (pid == -1)
		{
			printf("Fork error\n");
			return (0);
		}
		else if (pid == 0)
		{
			redirect_pipes(tmp, &pipes);
			env = converting(master->env);
			// si es un builtin ejecuta el builtin; si no, ejecuta exeve;
			// cada funcion debe devolver un int, y ese int (valor de salida) lo ponemos como argumento en el exit)
			if (is_builtin(tmp->cmd))
			{
				g_err = run_builtin(master, tmp);
				exit(g_err);
			}
			execve(tmp->cmd, tmp->args, env);
			perror("Execve error");
			exit(1);
		}
		waitpid(pid, &status, 0);
		printf("\nExit status: %d\n", WEXITSTATUS(status));
		g_err = WEXITSTATUS(status);
		tmp = tmp->next;
	}
	close(pipes.p[0]);
	close(pipes.p[1]);
	close(pipes.tmp_fd);
	return (1);
}
