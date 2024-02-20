/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:34:06 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/20 13:31:53 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_output(t_word *redir, t_cmd *cmd)
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
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			exit_error("Open error\n");
		free(filename);
		cmd->out_fd = fd;
		return ;
	}
	free(filename);
	cmd->ok = res;
	cmd->error = ft_strdup(redir->next->word);
}
