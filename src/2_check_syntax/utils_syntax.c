/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:32:26 by abastida          #+#    #+#             */
/*   Updated: 2023/12/05 11:55:23 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Esta es la funcion en la que si todos los chequeos de sintaxis estan ok > devuelve la linea sin comillas*/

//FIXME la linea limpia la tiene que devolver despues de divir la str.


int checking_syntax(char *str)
{
    if (paired_quotes(str) != 1)
    {
		printf("SyntaxError_PairedQuotes\n");
		return 0;
    }
    if (check_syntax_pipes(str) != 1)
    {
		printf("SyntaxError\n");
		return 0;
    }
    if (redir(str) != 1)
    {
		printf("SyntaxError_redir\n");
		return 0;
    }
    return (1);
}
