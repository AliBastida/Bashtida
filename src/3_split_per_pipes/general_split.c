/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2023/10/23 12:57:47 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*esta funcion mira donde esta la siguiente quote para saltar todo lo que hay dentro*/
int next_quote(char *str, int i, char c)
{
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    if (str[i] == c)
        return (i);
    return (0);
}
/*esta funcion busca el char y despues del if, va otro que busca el |*/
void look_for_char(char *str)
{
    int i = 0;
    int next = 0;
    
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
        {
            printf("el caracter es: %c La posicion de i: %d\n", str[i], i);
            next = next_quote(str, i + 1, str[i]);
            printf("la siguiente posicion es: %d\n", next);
        }
        //si str[i] es |, haz substr de lo qeu hay antes. TEngo que hacer una funcion que haga substr segun su posicion. 
        i++;
    }
}
//TODO: la funcion que recorre la str en busca de su match, esta funcionando.
//TODO:  Falta hace substr desde | hasta el inicio o el siguiente |, tengo que ver como calcular la len;
