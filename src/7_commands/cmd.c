/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/01 17:29:45 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *checking_path(char **path, char *cmd, int *ok)
{
	char *new_path;
	int i;

	i = 0;
	while (path[i])
	{
		new_path = ft_strjoin(path[i], "/");
		new_path = ft_strjoin(new_path, cmd);
		if (access(new_path, X_OK) == 0)
		{
			printf("este es mi cmd: %s \n", new_path);
			*ok = 0;
			return (new_path);
		}
		else if (access(new_path, F_OK) == 0)
		{
			*ok = 3;
			printf("%s", g_error_array[*ok - 1]);
		}
		i++;
	}
	*ok = 2;
	printf("%s", g_error_array[*ok - 1]);
	return ((char *)g_error_array[*ok - 1]);
}
/**/
void ft_take_cmd(t_cmd *new, t_word *words, t_master *master)
{
	char *cmd;
	char **split;

	if (words->type == 1 || words->type == 2 || words->type == 3 || words->type == 4)
		cmd = ft_strdup(words->next->next->word);
	else
		cmd = ft_strdup(words->word);
	split = ft_split(get_path(master), ':');
	new->cmd = checking_path(split, cmd, &new->ok);
	free(cmd);
}

// el contador i que nos devueleve esta funcion es el que nos dice la cantidad de memoria que queremos reservar con el calloc para los args en la funcion saving commands.
/*int node_counter(t_word *words)
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
}*/

/*t_cmd *saving_arg(t_master *token)
{
	t_token *tmp;

	tmp = token->node;
}*/
// TODO: TENENEMOS QUE HACER UN LOOP QUE RECORRA T_TOKEN ENTERO RECOGIENDO LOS CMDS Y GUARDANDOLOS EN LA LISTA T_CMD, QUE DESPUES DEBE SER RECORRIDA PARA EJECUTAR LOS COMANDOS.
/*t_cmd *saving_cmd(t_master *master)
{
	t_cmd *new;
	t_cmd *list;
	t_word *wd;
	t_token *tmp;

	// new = ft_calloc(sizeof(t_cmd), 1);
	// tmp = master->node;
	// j = 0;
	// if (!new)
	// 	return (NULL);
	// new->args = ft_calloc(sizeof(char *), (node_counter(words) + 1));
	// if (!new->args)
	// 	return (NULL);
	// while (tmp)
	// {
	// 	wd = words;
	// 	while (wd && j < node_counter(words))
	// 	{
	// 		if (wd->type == 1 || wd->type == 2 || wd->type == 3 || wd->type == 4)
	// 			wd = wd->next;
	// 		else
	// 		{
	// 			new->args[j] = ft_strdup(wd->word);
	// 			// printf("-new list cmd---*%s---- j: %d\n", new->args[j], j);
	// 			j++;
	// 		}
	// 		wd = wd->next;
	// 	}
	// 	tmp = tmp->next;
	// }
	// ft_take_cmd(new, words, master);
	// master->cmds = new;
	// // converting(master->env);

	return (NULL);
}
*/
char *get_path(t_master *master)
{
	char *path;
	path = ft_getenv("PATH", master->env, -1);
	return (path);
}
