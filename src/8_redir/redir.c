/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:43 by abastida          #+#    #+#             */
/*   Updated: 2024/02/03 06:59:38 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void manage_redir(t_word *redir, t_master *master)
{

	// if (redir->type == 1)
	//	llama a redir heredoc;
	// else if (redir->type == 2)
	//	llama a su funcion;
	if (redir->type == 3)
		redir_input(redir, master);
	else
		redir_output(redir, master);
}
