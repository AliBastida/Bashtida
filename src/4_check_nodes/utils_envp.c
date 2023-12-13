/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:51:12 by pabastid          #+#    #+#             */
/*   Updated: 2023/12/13 13:12:57 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Necesitamos dduplicar la vble const char **envp para poder trabajar con ella. En esta funcion, hacemos una lista dentro de t_master donde meteremos el dulicado de envp.*/
void ft_dup_envp(t_master *master, const char **envp)
{
	int i;
	char *dup;
	(void)master;

	i = 0;
	while (envp != NULL && envp[i])
	{
		dup = ft_strdup(envp[i]);
		if (master->env == NULL)
			master->env = ft_lstnew(dup);
		else
			ft_lstadd_back(&master->env, ft_lstnew(dup));
		i++;
	}
}

/* Esta funcioon getenv recibe un char *(con el nombre qque queremos comparar) y qque junto con el "=" lo meeteremos en vble y es lo que usaremos para comparar*/
char *ft_getenvp(const char *name, const char **envp)
{
	char *vble;
	int vble_len;
	int i;

	i = 0;
	vble = ft_strjoin(name, "="); // le unimos el "=" para asegurar todos los casos.
	vble_len = ft_strlen(vble);
	while (envp != NULL && envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], vble, vble_len) == 0)
		{
			free(vble);
			return ((char *)envp[i] + vble_len); // casteamos el int; y devuelve el puntero a la vable + el = -> USER= pabastid
		}
		i++;
	}
	free(vble);
	vble = NULL; // si no encuentra nada igual devuelve NULL.
	return (vble);
}
