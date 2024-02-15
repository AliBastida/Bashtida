/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:32:26 by abastida          #+#    #+#             */
/*   Updated: 2024/02/09 12:16:30 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Esta es la funcion en la que si todos los chequeos de sintaxis estan ok > devuelve la linea sin comillas*/

int checking_syntax(char *str)
{
	if (paired_quotes(str))
	{
		return (return_error("SyntaxError_PairedQuotes\n", 1));
		// printf("SyntaxError_PairedQuotes\n");
		// return 0;
	}
	else if (check_syntax_pipes(str))
	{
		return (return_error("SyntaxError\n", 1));
		// printf("SyntaxError\n");
		// return 0;
	}
	else if (redir(str))
	{
		return (return_error("SyntaxError_redir\n", 1));
		// printf("SyntaxError_redir\n");
		// return 0;
	}
	return (0);
}
