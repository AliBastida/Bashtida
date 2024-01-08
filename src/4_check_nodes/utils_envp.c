/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:51:12 by pabastid          #+#    #+#             */
/*   Updated: 2024/01/08 15:21:33 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Necesitamos dduplicar la vble const char **envp para poder trabajar con ella. En esta funcion, hacemos una lista dentro de t_master donde meteremos el dulicado de envp.*/
void ft_dup_env(t_master *master, const char **env)
{
	int i;
	char *dup;
	(void)master;

	i = 0;
	while (env != NULL && env[i])
	{
		dup = ft_strdup(env[i]);
		if (master->env == NULL)
			master->env = ft_lstnew(dup);
		else
			ft_lstadd_back(&master->env, ft_lstnew(dup));
		i++;
	}
}

// FIXME:  No funciona!!
char *clean_vble(char *node)
{
	int i;
	char *new_line;

	i = 0;
	new_line = malloc(sizeof(char) * ft_strlen(node) + 1);
	if (!new_line)
		return (NULL);
	while (node[i])
	{
		if ((node[i] == '$') && (node[i - 1] == '\"'))
		{
			while (node[i] != '\"')
			{
				new_line[i] = node[i];
				i++;
			}
		}
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}
/* Esta funcioon getenv recibe un char *(con el nombre qque queremos comparar) y qque junto con el "=" lo meeteremos en vble y es lo que usaremos para comparar*/
char *ft_getenv(const char *name, const char **env)
{
	char *vble;
	const char *new_name;
	int vble_len;
	int i;

	i = 0;
	new_name = clean_vble((char *)name);
	vble = ft_strjoin(new_name + 1, "="); // le unimos el "=" para asegurar todos los casos.
	printf("%s\n", vble);
	vble_len = ft_strlen(vble);
	while (env != NULL && env[i] != NULL)
	{
		if (ft_strncmp((char *)env[i], vble, vble_len) == 0)
		{
			free(vble);
			return ((char *)env[i] + vble_len); // casteamos el int; y devuelve el puntero a la vable + el = -> USER= pabastid
		}
		i++;
	}
	free(vble);
	vble = ft_strdup(""); // Antes devolvia NULL, pero lo hemos cambiado para que nos de cadena vacia.
	return (vble);
}
