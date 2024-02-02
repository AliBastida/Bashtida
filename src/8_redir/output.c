/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:34:06 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/02 14:39:34 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Redirection of output causes the filename to be opened for writing on the standard output. If the file does not exist it is created; if it does exist it is truncated to zero size.
// Retorna un fd 0 -1(error)
int redir_output(t_word *redir, t_master *master)
{
	int fd;
	char *filename;

	fd = 0;
	filename = redir->word->words->next;
	if (filename)
	{
		fd = fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644); // permisos full seria esto: S_IRWXU
	}
	else if (!filename)
	{
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644); // permisos solo cuando se crea
	}
	if (fd == -1)
		// error correspondiente;
		master->cmds->out_fd = fd;
	close(master->cmds->out_fd);
	free(filename);
	return ()
}
