/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:32:26 by abastida          #+#    #+#             */
/*   Updated: 2023/11/08 15:10:24 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Esta es la funcion en la que si todos los chequeos de sintaxis estan ok > devuelve la linea sin comillas*/
int checking_syntax(char *str, t_master *master)
{
    (void) master;
    if (paired_quotes(str) == 1)
        {
            if (check_syntax_pipes(str) == 1)
            {
                if (redir(str) == 1)
                    printf("Syntax ok\n");
                    //printf("%s\n", clean_line(str, master));
            }
        }
    else
    {
        printf("syntax error :<\n");
        return (0);
    }
    return (1);
}
//FIXME la linea limpia la tiene que devolver despues de divir la str.