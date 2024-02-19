/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:27:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 18:16:44 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_input(t_word *redir, t_cmd *cmd)
{
	int		fd;
	int		res;
	char	*filename;

	fd = 0;
	if (cmd->ok != 0)
		return ;
	filename = filename_path(redir->next->word);
	res = ft_access(filename, 0);
	if (!res)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			exit_error("Open error\n");
		free(filename);
		cmd->in_fd = fd;
		if (cmd->hd)
			cmd->hd->first = 0;
		return ;
	}
	free(filename);
	cmd->ok = res;
	cmd->error = ft_strdup(redir->next->word);
}
