/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:17:07 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/08 12:26:02 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// comprobar si unset tira error cuando usamos caracteres especiales (@) -> hay que crear una funcion que comprueba que no hay caracteres especiales >> que usaremos en export tambien
int builtin_unset(**env_char, [array de args]) // recibe el **env_char que resulta de execve.c->converting la lista env y el array de args que van detras <UNSET hola holaaaa ciao pescao>
{
	int i;

	i =
		if (![array[1]]) // si ponemos solo unset no hace nada
		return (0);
	else
	{
		while (args[i]) // mientras haya argumentos que borrar;
		{
			1 - comprobamos si hay carcateres especiales para que tire error
			// t_env nodo = con la funcion ft_getenv(que le daremos el arg que esta analizando comprueba si esta en la lista * *env y si la encuentra devolvera el nodo)
			{
				if (!el nodo)
					->continue;
				if (existe el nodo)
					->lo borra;
				Al borrar hay que comprobar : 1 - Si es el primer nodo de la lista->hay que ponerlo en NULL porque al borrarlo se queda vacio;
				2 - Si no es el primer nodo->hay que cambiar el prev y el next, y el prev del prev y del next que acabara en null.
			}
		}
		return (0);
	}
}
