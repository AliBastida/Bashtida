/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:17:07 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/15 18:34:12 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Esta funcion get_envnode recibe la lista donde tenemos env,
	la lista que contiene los args y que junto con el "="
	sera lo que meteremos en vble y es lo que usaremos para comparar.
	Nos devuelve el nodo anterior a la coincidencia y si no lo encuentra devuelve NULL*/
/* Nos tiene que devolver el anterior a la coincidencia,
	con lo que el rdo de la coincidencia sera tmp->next y el anterior sera tmp que es lo que devuelve si encuentra;*/
static t_list	*get_envnode_unset(t_list **env, char *arg)
{
	int		arg_len;
	t_list	*tmp;

	tmp = *env;
	arg_len = ft_strlen(arg);
	while (tmp && tmp->next != NULL)
	{
		if (ft_strncmp((char *)tmp->next->content, arg, arg_len) == 0)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

// esta borra el nodo siguiente al que te pasan (la coincidencia)
void	delete_node(t_list *env)
{
	t_list	*aux;

	if (env)
	{
		aux = env->next;
		env->next = aux->next;
		free(aux);
	}
}

// recibe el **env el array de args que van detras <UNSET hola holaaaa ciao pescao>
// le unimos el "=" para asegurar todos los casos.
// en el caso de que la coincidenccia sea el primer nodo hacemos el strncmp
int	builtin_unset(t_list **env, char **args)
{
	int		i;
	char	*arg;
	t_list	*aux;

	i = 1;
	while (args[i])
	{
		arg = ft_strjoin(args[i], "=");
		if (ft_strncmp((char *)(*env)->content, arg, ft_strlen(arg)) == 0)
		{
			aux = (*env)->next;
			free(*env);
			*env = aux;
		}
		else
			delete_node(get_envnode_unset(env, arg));
		free(arg);
		i++;
	}
	return (0);
}
