/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:17:07 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/08 13:43:19 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// comprobar si unset tira error cuando usamos caracteres especiales (@) -> hay que crear una funcion que comprueba que no hay caracteres especiales >> que usaremos en export tambien
int builtin_unset(**env_char, t_cmd[array de args]) // recibe el **env_char que resulta de execve.c->converting la lista env y el array de args que van detras <UNSET hola holaaaa ciao pescao>
{
	int i;

	i = 1;
	if (!t_cmd ![array[1]]) // si ponemos solo unset no hace nada
		return (0);
	else
	{
		while (args[i]) // mientras haya argumentos que borrar;
		{
			puntero del nodo anterior = get_envnode(arg[i]);
			{
				if (get_envnode no encuetra nada)
					return (0);
				if (existe puntero del nodo anterior = get_envnode(arg[i]))
					1 - si el resultado de get_envnode es el primer nodo->swap con free del primero
							tmp = master->env->next;
				free(master->env) ojo que free de todo
					master->env = tmp;

				2 - si tmp->next != NULL->get_envnode tiene que devolver el anterior(tmp) y hacer free de(tmp->next);
			}
		}
		return (0);
	}
}
