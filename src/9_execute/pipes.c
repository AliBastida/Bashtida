/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:27:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 13:51:11 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_ok(t_cmd **cmd)
{
	if ((*cmd)->ok)
	{
		if ((*cmd)->ok > 2)
			printf("bash: %s: %s", (*cmd)->error, g_error_array[(*cmd)->ok
				- 1]);
		else
			printf("bash: %s: %s", (*cmd)->cmd, g_error_array[(*cmd)->ok - 1]);
		(*cmd) = (*cmd)->next;
		return (1);
	}
	return (0);
}

void	redirect_pipes(t_cmd *cmd, t_pipes pipes)
{
	if (cmd->in_fd != 0 && (!cmd->hd || (cmd->hd && !cmd->hd->first)))
		((dup2(cmd->in_fd, 0)) && (close(cmd->in_fd)));
	else
	{
		if (cmd->hd)
		{
			dup2(cmd->hd->fd[0], 0);
			((close(cmd->hd->fd[0])) && (close(cmd->hd->fd[1])));
		}
		else if (cmd->n > 0 && cmd->next)
			((dup2(pipes.tmp_fd, 0)) && (close(pipes.tmp_fd)));
		else if (cmd->n > 0 && !cmd->next)
			dup2(pipes.p[0], 0);
	}
	close(pipes.p[0]);
	if (cmd->out_fd != 1)
		((dup2(cmd->out_fd, 1)) && (close(cmd->out_fd)));
	else if (cmd->out_fd == 1 && cmd->next)
		dup2(pipes.p[1], 1);
	close(pipes.p[1]);
}

int	check_cmd_and_pipes(t_cmd **cmd, t_pipes *pipes)
{
	if ((*cmd)->n == 0 && (*cmd)->next)
		pipe(pipes->p);
	else if ((*cmd)->n > 0 && (*cmd)->in_fd == 0 && (*cmd)->next && !(*cmd)->hd)
	{
		if (pipes->tmp_fd != -1)
			close(pipes->tmp_fd);
		pipes->tmp_fd = dup(pipes->p[0]);
		close(pipes->p[0]);
		close(pipes->p[1]);
		pipe(pipes->p);
	}
	if (!(*cmd)->cmd)
	{
		(*cmd) = (*cmd)->next;
		return (1);
	}
	return (check_ok(cmd));
}
