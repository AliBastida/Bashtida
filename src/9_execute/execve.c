/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:52:12 by abastida          #+#    #+#             */
/*   Updated: 2024/02/12 14:46:40 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void close_all_pipes(t_master *master, pid_t *pids, t_pipes pipes)
{
	int final;
	int status;
	int finished;

	final = 0;
	status = 0;
	finished = 0;
	close(pipes.p[0]);
	close(pipes.p[1]);
	close(pipes.tmp_fd);
	while (finished < master->n_cmds)
	{
		if (waitpid(-1, &status, 0) == pids[master->n_cmds - 1])
			final = status;
		if (!WIFSIGNALED(status))
			g_err = WEXITSTATUS(status);
		finished++;
	}
	if (pids)
		free(pids);
	g_err = final;
}

pid_t loop_cmds(t_master *master, t_cmd *tmp, t_pipes pipes)
{
	pid_t pid;
	char **env;

	pid = fork();
	if (pid == 0)
	{
		redirect_pipes(tmp, pipes);
		env = converting(master->env);
		// si es un builtin ejecuta el builtin; si no, ejecuta exeve;
		// cada funcion debe devolver un int, y ese int (valor de salida) lo ponemos como argumento en el exit)
		if (is_builtin(tmp->cmd))
		{
			g_err = run_builtin(master, tmp);
			exit(g_err);
		}
		execve(tmp->cmd, tmp->args, env);
	}
	// printf("\nExit status: %d\n", WEXITSTATUS(status));
	// g_err = WEXITSTATUS(status);
	return (pid);
}
