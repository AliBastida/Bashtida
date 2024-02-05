/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:27:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/04 17:35:21 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			return ;
		}
		cmd->in_fd = fd;
	}
	cmd->ok = res;
	printf("Input error: %i\n", res);
}
