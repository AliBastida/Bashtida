/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:27:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/07 10:27:46 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_cmd_and_pipes(t_cmd *cmd, t_pipes *pipes)
{
	if (cmd->n == 0 && cmd->next)
		pipe(pipes->p);
	else if (cmd->n > 0 && cmd->in_fd == 0 && cmd->next && !cmd->hd)
	{
		if (pipes->tmp_fd != -1)
			close(pipes->tmp_fd);
		pipes->tmp_fd = dup(pipes->p[0]);
		close(pipes->p[0]);
		close(pipes->p[1]);
		pipe(pipes->p);
	}
	if (cmd->ok)
	{
		printf("%s\n", g_error_array[cmd->ok - 1]);
		cmd = cmd->next;
		return (1);
	}
	return (0);
}
