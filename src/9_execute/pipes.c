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

void redirect_pipes(t_cmd *cmd, t_pipes pipes)
{
	// Control de entrada, que es el file descriptor 0
	if (cmd->in_fd != 0 && (!cmd->hd || (cmd->hd && !cmd->hd->first)))
		((dup2(cmd->in_fd, 0)) && (close(cmd->in_fd))); // Aqui miramos si hay una redireccion < y es la ultima, tambien despues de cualquier heredoc
	else
	{
		if (cmd->hd)
		{ // Aqui hacemos dup2 del pipe del heredoc
			dup2(cmd->hd->fd[0], 0);
			((close(cmd->hd->fd[0])) && (close(cmd->hd->fd[1])));
		}
		else if (cmd->n > 0 && cmd->next) // Aqui hacemos el dup2 del file descriptor temporal porque significa que hay un comando despues
			((dup2(pipes.tmp_fd, 0)) && (close(pipes.tmp_fd)));
		else if (cmd->n > 0 && !cmd->next) // Aqui hacemos el dup2 del pipe, porque despues no hay otro comando
			dup2(pipes.p[0], 0);
	}
	close(pipes.p[0]); // Aqui cerramos el pipe de lectura
	// Control de salida, que es el file descriptor 1
	if (cmd->out_fd != 1) // Aqui miramos si hay una redireccion > o >>
		((dup2(cmd->out_fd, 1)) && (close(cmd->out_fd)));
	else if (cmd->out_fd == 1 && cmd->next) // Aqui hacemos dup2 del pipe porque hay un comando despues y no hay redirecciones
		dup2(pipes.p[1], 1);
	close(pipes.p[1]); // Aqui cerramos el pipe de lectura
}

int check_cmd_and_pipes(t_cmd **cmd, t_pipes *pipes)
{
	if ((*cmd)->n == 0 && (*cmd)->next) // Aqui creamos el pipe si hay mas de un comando al principio de la ejecucion de los hijos
		pipe(pipes->p);
	else if ((*cmd)->n > 0 && (*cmd)->in_fd == 0 && (*cmd)->next && !(*cmd)->hd)
	{ // Aqui hacemos la transferencia de datos entre el pipe y el file descriptor temporal
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
	if ((*cmd)->ok) // Aqui miramos si el comando está bien o hay un error
	{
		printf("bash: %s: %s", (*cmd)->cmd, g_error_array[(*cmd)->ok - 1]);
		// printf("%s\n", g_error_array[(*cmd)->ok - 1]);
		(*cmd) = (*cmd)->next;
		return (1);
	}
	return (0);
}
