/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:51:12 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/13 17:35:36 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Necesitamos dduplicar la vble const char **envp para poder trabajar con ella. En esta funcion, hacemos una lista dentro de t_master donde meteremos el dulicado de envp.*/
void ft_dup_env(t_master *master, const char **env)
{
	int i;
	char *dup;

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
	// print_env(master);
}

char *clean_vble(char *node, int idx)
{
	int i;
	int j;
	int len;
	char *new_line;

	j = 0;
	len = 0;
	i = idx + 1;
	while (ft_isalpha(node[i]))
	{
		i++;
		len++;
	}
	new_line = malloc(sizeof(char) * (len + 1)); // LEN DE EL NOMBRE DE LA VARIABLE HASTA QUE NO ENCUENTRAS UN CARACTER ALFABETICO
	if (!new_line)
		return (NULL);
	i = idx + 1;
	while (j < len)
	{
		new_line[j] = node[i];
		j++;
		i++;
	}
	new_line[j] = '\0';
	return (new_line);
}

/* Esta funcioon getenv recibe un char *(con el nombre qque queremos comparar) y qque junto con el "=" lo meeteremos en vble y es lo que usaremos para comparar*/
char *ft_getenv(const char *name, t_list *env, int idx)
{
	char *vble;
	int vble_len;
	t_list *tmp;
	const char *new_name;

	tmp = env;
	new_name = clean_vble((char *)name, idx);
	vble = ft_strjoin(new_name, "="); // le unimos el "=" para asegurar todos los casos.
	// printf("Vble: %s\n", vble);
	vble_len = ft_strlen(vble);
	while (tmp && tmp->content)
	{
		// printf("Env: %s\n", (char *)tmp->content);
		if (ft_strncmp((char *)tmp->content, vble, vble_len) == 0)
		{
			free(vble);
			return ((char *)tmp->content + vble_len); // casteamos el int; y devuelve el puntero a la vable + el = -> USER= pabastid
		}
		tmp = tmp->next;
	}
	free(vble);
	vble = ft_strdup(""); // Antes devolvia NULL, pero lo hemos cambiado para que nos de cadena vacia.
	return (vble);
}
