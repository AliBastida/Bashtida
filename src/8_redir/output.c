/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:34:06 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/04 17:31:08 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Redirection of output causes the filename to be opened for writing on the standard output. If the file does not exist it is created; if it does exist it is truncated to zero size.
// Retorna un fd 0 -1(error)
// TODO da controlar que no esta bien
void redir_output(t_word *redir, t_cmd *cmd)
{
	int fd;
	char *filename;

	fd = 0;
	filename = redir->next->word;
	// TODO hacer el access con el archivo antes de hacer open
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644); // permisos full seria esto: S_IRWXU
	if (fd == -1)
	{
		cmd->ok = 4;
		return;
		// error correspondiente;
	}
	cmd->out_fd = fd;
	// close(master->cmds->out_fd);
	// free(filename);
}
