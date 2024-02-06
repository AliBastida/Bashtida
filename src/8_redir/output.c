/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:34:06 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/05 17:28:15 by abastida         ###   ########.fr       */
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
	int res;

	fd = 0;
	if (cmd->ok != 0)
		return;
	filename = filename_path(redir->next->word);
	printf("Complete Filename: %s\n", filename);
	res = ft_access(filename, 1);

	// TODO hacer el access con el archivo antes de hacer open
	if (!res || res == FILE_NOT_FOUND)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU); // permisos full seria esto: S_IRWXU 0644
		if (fd == -1)
		{
			cmd->ok = 4;
			printf("%s\n", g_error_array[cmd->ok - 1]);
			return;
			// error correspondiente;
		}
		else
			cmd->out_fd = fd;
	}
	cmd->ok = res;
	printf("Output error: %i\n", res);
	// close(master->cmds->out_fd);
	// free(filename);
}
/*
void redir_input(t_word *redir, t_cmd *cmd)
{
	int fd;
	int res;
	char *filename;

	fd = 0;
	filename = filename_path(redir->next->word);
	printf("Complete Filename: %s\n", filename);
	res = ft_access(filename, 0);
	if (!res)
	{
		fd = open(filename, O_RDONLY);
		printf("fd: %d\n", fd);
		if (fd == -1)
		{
			cmd->ok = 4;
			printf("%s\n", g_error_array[cmd->ok - 1]);
			return;
		}
		cmd->in_fd = fd;
	}
	cmd->ok = res;
	printf("Input error: %i\n", res);
}*/
