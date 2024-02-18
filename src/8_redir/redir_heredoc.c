/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 16:44:09 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_heredoc(t_word *redir, t_cmd *cmd)
{
	t_heredoc	*hd;

	hd = ft_calloc(sizeof(t_heredoc), 1);
	if (!hd)
		exit_error("Malloc error\n");
	hd->word = ft_strdup(redir->next->word);
	if (!hd->word)
		exit_error("Malloc error\n");
	pipe(hd->fd);
	hd->first = 1;
	cmd->hd = hd;
}
