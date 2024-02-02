/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:27:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/02 14:38:36 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int redir_input(t_word *redir, t_master *master)
{
	int fd;
	char *filename;

	fd = 0;
	filename = redir->word->next->words;
	// master->cmds->file_name = redir->word->words->next;
	fd = open(filename, O_RDONLY, 0664);
	if (fd == -1)
	{
		*master->cmds->ok = 4;
		printf(g_error_array[master->cmds->ok - 1]);
	}
	master->cmds->in_fd = fd;
	close(master->cmds->in_fd);
	free(filename);
	return (master->cmds->ok);
}
// d = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
