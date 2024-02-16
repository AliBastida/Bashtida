/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:27:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 18:13:04 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void redir_input(t_word *redir, t_cmd *cmd)
{
	int fd;
	int res;
	char *filename;

	fd = 0;
	if (cmd->ok != 0)
		return;
	filename = filename_path(redir->next->word);
	printf("Complete Filename: %s\n", filename);
	res = ft_access(filename, 0);
	if (!res)
	{
		fd = open(filename, O_RDONLY);
		printf("fd: %d\n", fd);
		if (fd == -1)
		{
			cmd->error = ft_strdup(redir->next->word);
			cmd->ok = 4;
			printf("bashtida: error: %s : %s\n", cmd->error, g_error_array[cmd->ok - 1]);
			return ;
		}
		cmd->in_fd = fd;
		return;
	}
	cmd->ok = res;
	printf("Input error: %i\n", res);
}
