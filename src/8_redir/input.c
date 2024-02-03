/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:27:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/03 07:59:04 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void redir_input(t_word *redir, t_master *master)
{
	int fd;
	char *filename;

	fd = 0;
	filename = redir->next->word;
	printf("%s\n", filename);
	filename = filename_path(take_path(master), filename);
	printf("filename: %s\n", filename);
	if (ft_access(filename) == 0)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			master->cmds->ok = 4;
			printf("%s\n", g_error_array[master->cmds->ok - 1]);
			return;
		}
		master->cmds->in_fd = fd;
	}
}

// TODO hacer el access con el archivo antes de hacer open
