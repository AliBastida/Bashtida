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

char *clean_vble(char *node, int idx)
{
	int i;
	int j;
	int len;
	char *new_line;

	j = -1;
	len = 0;
	i = idx + 1;
	while (ft_isalpha(node[i]))
	{
		i++;
		len++;
	}
	new_line = malloc(sizeof(char) * (len + 1)); // LEN DE EL NOMBRE DE LA VARIABLE HASTA QUE NO ENCUENTRAS UN CARACTER ALFABETICO
	if (!new_line)
		exit_error("Malloc error\n");
	i = idx + 1;
	while (++j < len)
		new_line[j] = node[i++];
	new_line[j] = '\0';
	return (new_line);
}

/* Esta funcion getenv recibe un char *(con el nombre que queremos comparar) y que junto con el "=" lo meteremos en vble y es lo que usaremos para comparar*/
char *ft_getenv(const char *name, t_list *env, int idx)
{
	int vble_len;
	char *vble;
	char *new_name;
	t_list *tmp;

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
			return ((char *)tmp->content + vble_len); // casteamos el int; y devuelve el puntero a la vable + el = -> USER=pabastid
		}
		tmp = tmp->next;
	}
	free(vble);
	vble = ft_strdup(""); // Antes devolvia NULL, pero lo hemos cambiado para que nos de cadena vacia.
	return (vble);
}
