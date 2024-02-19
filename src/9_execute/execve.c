/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:52:12 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 18:57:35 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_here_doc(t_master *master)
{
	t_cmd	*tmp;

	tmp = master->cmds;
	while (tmp)
	{
		if (tmp->hd)
		{
			close(tmp->hd->fd[0]);
			close(tmp->hd->fd[1]);
		}
		tmp = tmp->next;
	}
}

int	close_all_pipes(t_master *master, pid_t *pids, t_pipes pipes, char **env)
{
	int	final;
	int	status;
	int	finished;

	final = 0;
	status = 0;
	finished = 0;
	close(pipes.p[0]);
	close(pipes.p[1]);
	close(pipes.tmp_fd);
	close_here_doc(master);
	ft_free_double(env);
	while (finished < master->n_cmds)
	{
		if (waitpid(-1, &status, 0) == pids[master->n_cmds - 1])
			final = status;
		finished++;
	}
	free(pids);
	return (0);
}

int	one_builtin(t_master *master, t_cmd *cmd, char **env)
{
	int	out_fd;

	out_fd = -1;
	if (cmd->out_fd != 1)
	{
		out_fd = dup(1);
		dup2(cmd->out_fd, 1);
		close(cmd->out_fd);
	}
	take_exit_value(cmd);
	ft_free_double(env);
	g_err = run_builtin(master, cmd);
	if (out_fd != -1)
	{
		dup2(out_fd, 1);
		close(out_fd);
	}
	return (0);
}

pid_t	one_cmd(t_master *master, t_cmd *tmp, t_pipes pipes, char **env)
{
	pid_t	pid;

	set_signals(1);
	pid = fork();
	if (pid == 0)
	{
		redirect_pipes(tmp, pipes);
		close_here_doc(master);
		if (is_builtin(tmp->cmd))
		{
			g_err = run_builtin(master, tmp);
			exit(g_err);
		}
		execve(tmp->cmd, tmp->args, env);
	}
	return (pid);
}
