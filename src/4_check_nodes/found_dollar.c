/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:05:23 by abastida          #+#    #+#             */
/*   Updated: 2023/11/03 14:36:37 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Si en la linea hay un dolar, chequea sin esta entre comillas dobles o no, y devuelve 1 si 
//esta entre comillas dobles. Si el retorno es 1, llamaremos a otra funcion (check_after_dollar)que compruebe el siguiente caracter
//para saber lo que hay que hacer despues. 


/*bool check_dollar(t_master *line)
{
    int i;
    t_master *tmp; 

    i = 0;
    tmp = line->node;
    while (tmp != NULL)
    {
        if (tmp ->line[i] == '$')
        {
            printf("hemos encontrado $\n", tmp->line[i]);
            return (1);
        }
        i++;
        //tmp = tmp->node->next;
    }
    return (0);
}*/

//FIXME No se como plantear esta funcion!!!!!