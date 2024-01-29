/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:32 by abastida          #+#    #+#             */
/*   Updated: 2024/01/29 15:14:27 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// el contador i que nos devueleve esta funcion es el que nos dice la cantidad de memoria que queremos reservar con el calloc para los args en la funcion saving commands.
int node_counter(t_word *words)
{
	t_word *wd;
	int i;

	wd = words;
	i = 0;
	while (wd)
	{
		if (wd->type == 1 || wd->type == 2 || wd->type == 3 || wd->type == 4)
		{
			wd = wd->next;
			wd = wd->next;
		}
		else
		{
			i++;
			wd = wd->next;
			// printf("numero de nodos de t_word%d\n", i);
		}
	}
	return (i);
}

// esta funcion guarda en un char **(new->args) los args que vamos a necesitar para ejecutar los comandos, saltando las redirecciones y lo siguiente.
// TODO: ojo que aqui estamos saltando la redireeccion y el next - y nos devuelve la estructura new, con ->arg rellenados.
t_cmd *saving_cmd(t_word *words)
{
	t_cmd *new;
	t_word *wd;
	int j;

	new = ft_calloc(sizeof(t_cmd), 1);
	wd = words;
	j = 0;
	if (!new)
		return (NULL);
	new->args = ft_calloc(sizeof(char *), (node_counter(words) + 1));
	if (!new->args)
		return (NULL);

	while (wd && j < node_counter(words))
	{
		if (wd->type == 1 || wd->type == 2 || wd->type == 3 || wd->type == 4)
			wd = wd->next;
		else
		{
			new->args[j] = ft_strdup(wd->word);
			printf("-new list cmd---*%s---- j: %d\n", new->args[j], j);
			j++;
		}
		wd = wd->next;
	}
	free(wd);
	return (new);
}

// printf("Getenv: -%s-\n", ft_getenv("PATH=", env, idx)); //TODO: Para coger el valor de la variable PATH
// TODO: HAY QUE COMPROBAR QUUE FUNCIONA

char *get_path(t_master *master)
{
	char *path;
	path = ft_getenv("PATH", master->env, 0);
	printf("%s\n", path);
	return (path);
}
