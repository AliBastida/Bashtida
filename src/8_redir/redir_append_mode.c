/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_append_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:22:34 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 14:05:37 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_mode(t_word *redir, t_cmd *cmd)
{
	int		fd;
	int		res;
	char	*filename;

	fd = 0;
	if (cmd->ok != 0)
		return ;
	filename = filename_path(redir->next->word);
	res = ft_access(filename, 1);
	if (!res || res == FILE_NOT_FOUND)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0664);
		if (fd == -1)
			exit_error("Open error\n");
		free(filename);
		cmd->out_fd = fd;
		return ;
	}
	free(filename);
	cmd->ok = res;
	cmd->error = ft_strdup(redir->next->word);
	printf("Output error: %i\n", res);
}
