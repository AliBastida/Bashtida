/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:32:26 by abastida          #+#    #+#             */
/*   Updated: 2023/11/15 15:35:58 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Esta es la funcion en la que si todos los chequeos de sintaxis estan ok > devuelve la linea sin comillas*/

//FIXME la linea limpia la tiene que devolver despues de divir la str.


int checking_syntax(char *str)
{
    if (paired_quotes(str) != 1)
    {
        printf ("paired_quotes error");
        return 0;
    }
    if (check_syntax_pipes(str) != 1)
    {
        printf ("syntax_error");
        return 0;
    }
    if (redir(str) != 1)
    {
        printf("error redir\n");
        return 0;
    }
    return (1);
}
