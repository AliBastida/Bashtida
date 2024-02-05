/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:04:03 by abastida          #+#    #+#             */
/*   Updated: 2024/02/05 08:01:44 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void run_here_doc(t_cmd *cmd)
{
	char	*line;
	while(42)
	{
		line = readline("> ");
		if (!line || (line[0] != '\0'
				&& !ft_strncmp(line, cmd->hd->word, ft_strlen(line))))
			break ;
		ft_putstr_fd(line, cmd->hd->fd[1]);
		ft_putchar_fd('\n', cmd->hd->fd[1]);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	exit(0);
}

void ft_take_heredoc(t_cmd *cmd)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		run_here_doc(cmd);
	waitpid(pid, &status, 0);
	printf("");
	g_err = WEXITSTATUS(status);
}
