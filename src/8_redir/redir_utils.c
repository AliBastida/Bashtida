/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:04:03 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 17:36:59 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*filename_path(char *name)
{
	char	*tmp;
	char	*filename;
	char	work_dir[256];

	getcwd(work_dir, sizeof(work_dir));
	tmp = ft_strjoin(work_dir, "/");
	if (!tmp)
		exit_error("Malloc error\n");
	filename = ft_strjoin(tmp, name);
	if (!filename)
		exit_error("Malloc error\n");
	free(tmp);
	return (filename);
}

int	ft_access(char *filename, int mod)
{
	if ((!mod && access(filename, R_OK) == 0) || (mod == 1 && access(filename,
				W_OK) == 0) || (mod == 2 && access(filename, X_OK) == 0))
		return (0);
	if ((!mod || mod == 1) && access(filename, F_OK) == 0)
	{
		if (!mod)
			return (FILE_NOT_READ);
		else
			return (FILE_NOT_WRITE);
	}
	else if (mod == 2)
	{
		if (access(filename, F_OK) == 0)
			return (COMMAND_FOUND_NOT_EX);
		return (COMMAND_NOT_FOUND);
	}
	return (FILE_NOT_FOUND);
}

void	manage_redir(t_word *redir, t_cmd *cmd)
{
	if (redir->type == 1)
		redir_heredoc(redir, cmd);
	else if (redir->type == 2)
		append_mode(redir, cmd);
	else if (redir->type == 3)
		redir_input(redir, cmd);
	else
		redir_output(redir, cmd);
}
