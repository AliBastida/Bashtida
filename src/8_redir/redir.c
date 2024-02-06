/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/05 16:42:08 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void manage_redir(t_word *redir, t_cmd *cmd)
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
