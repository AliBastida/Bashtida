/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/04 17:11:30 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void manage_redir(t_word *redir, t_cmd *cmd)
{

	// if (redir->type == 1)
	//	llama a redir heredoc;
	// else if (redir->type == 2)
	//	llama a su funcion;
	if (redir->type == 1)
		redir_heredoc(redir, cmd);
	else if (redir->type == 3)
		redir_input(redir, cmd);
	else
		redir_output(redir, cmd);
}
