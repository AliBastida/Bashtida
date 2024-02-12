/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:59:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/12 15:52:07 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int len_hastaeligual(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

static char *copyvble(char *str, int size)
{
	int i;
	char *copy;

	copy = ft_calloc(size + 1, sizeof(char));
	if (!copy)
		return (NULL);

	i = 0;
	while ((str[i] && str[i] != '=') && (i <= size))
	{
		if (str[i] == '+')
		{
			return (copy);
		}
		else
			copy[i] = str[i];
		printf("%d \t %d\n", i, size);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int checking_format(char *str)
{
	int i;
	size_t last_one;

	i = 0;
	last_one = ft_strlen(str);
	while (str[i])
	{
		if (ft_isalpha(str[0]) || (i > 0 && (ft_isdigit(str[i]) || ft_isalpha(str[i]) || str[i] == '_' || str[last_one - 1] == '+')))
			return (0);
		else
		{
			printf("NO esta bien escrito\n"); // TODO: TENEMOS QUE GUARDAR EL ERROR EN LA V_GLOBAL.
			// guardar el error en algun sitio;
			return (1);
		}
		i++;
	}
	return (0);
}

static t_list *get_envnode_export(t_list *env, char *arg)
{
	int arg_len;
	t_list *tmp;

	tmp = env;
	arg_len = ft_strlen(arg);
	while (tmp) //&& tmp->next != NULL)
	{
		if (ft_strncmp((char *)tmp->content, arg, arg_len) == 0)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL); // nos tiene que devolver el nodo de la coincidencia.
}

int builtin_export(t_master *master, char **args)
{
	char *arg;
	int i;
	int len;
	char *checking_mas
		// t_list *aux;

		i = 1;
	while (args[i])
	{
		len = len_hastaeligual(args[i]);
		printf("len hasta el igual: %d", len);
		arg = copyvble(args[i], len);
		if (checking_format(arg) == 0)
		{
			// si arg[len-1]=='+'
			//{arg = ft_}
			arg = ft_strjoin(arg, "=");
			printf("arg: ---%s----\n", args[i]);
			if (get_envnode_export(master->env, arg))
			{
				//	master->env->content = ft_strdup(args[i]);
				printf("hola\n");
			}
			else
			{
				// aux = ft_lstnew((char *)args[i]);
				// printf("aux: ==%s==\n", aux->content);
				// ft_lstadd_back(env, aux);
				ft_lstadd_back(&master->env, ft_lstnew(ft_strdup(args[i])));

				//
				//  crea nodo + strdup de todo args[i]
				//  lst_add_back
			}
			PRINT_LIST(master->env);
			// aux = get_envnode_export(env, arg);
			// printf("AUX: ///%s///\n", aux->content);
		}
		i++;
	}
	free(arg);
	return (0);
}
/*
if (strncmp == 0)
	--->existe la vv de entorno.Tenemos que coger ese nodo y cambiar el valor por lo que hay detras del igual con strdup;
buscar el nodo de t_list.cambiar el content desde el igual hasta el final.

	if (strncmp != 0)--->no existe.Hay que crearlo y darle valores nuevos.crea el nodo.añadelo al final de la lista.dale el valor de args[i]
		.
*/
