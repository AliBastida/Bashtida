/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:35:20 by abastida          #+#    #+#             */
/*   Updated: 2024/02/01 18:08:48 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Aqui averiguamos el len para el malloc de la lista de args
int n_args(t_word *words)
{
	int i;

	i = 0;
	while (words)
	{
		if (words->type == 1 || words->type == 2 || words->type == 3 || words->type == 4)
			words = words->next;
		else
			i++;
		words = words->next;
	}
	return (i);
}

// tenemos que hacer un malloc con el numero de nodos de t_word qye no son redirecciones ni lo siguiente para crear el char ** del nodo.
// tenemos que, con strdup copiar en el char **los args (incluido el cmd).
// despues, en otra funcion, copiamos la posicion [0] del char en char *cmd y en otra funcion comprobamos si el path existe y es ejecutable o no.
// otra funcion que ejecute el cmd.

t_cmd *create_node_cmd(t_word *words, t_master *master)
{
	t_cmd *new;
	t_word *tmp;
	int i;

	i = 0;
	tmp = words;
	new = ft_calloc(sizeof(t_cmd), 1);
	new->next = NULL;
	new->args = ft_calloc(sizeof(char *), n_args(words) + 1);
	if (!new)
		return (NULL);
	while (tmp)
	{
		if (tmp->type == 1 || tmp->type == 2 || tmp->type == 3 || tmp->type == 4)
			tmp = tmp->next;
		else
		{
			new->args[i] = ft_strdup(tmp->word);
			i++;
		}
		tmp = tmp->next;
	}
	new->cmd = ft_strdup(new->args[0]);
	// TODO: aqui va la funccion que chequea ssi es un BUILTIN
	ft_take_cmd(new, words, master);
	// exec_cmd(new, master);
	//  checking path - access

	return (new);
}
/*t_token *create_nodeandlist(t_master *master, char *str)
{
	t_token *new_node;
	t_token *new_list;
	int n_pipes;
	char **line_divided;
	int n;

	n = 0;
	new_list = NULL;
	n_pipes = how_many_pipes(str) + 1;
	line_divided = line_divided_in_tokens(str);
	while (n_pipes > n)
	{
		new_node = ft_newnode(clean_word(line_divided[n]));
		if (new_list == NULL)
			new_list = new_node;
		else
			lst_add_back(&new_list, new_node);
		n++;
	}
	free(line_divided);
	master->node = new_list;
	return (new_list);
}
*/
t_cmd *lst_last_cmd(t_cmd *list)
{
	t_cmd *tmp;

	tmp = list;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	return (tmp);
}

void lst_add_back_cmd(t_cmd *list, t_cmd *node)
{
	t_cmd *tmp;

	if (list == NULL)
		list = node;
	else
	{
		tmp = lst_last_cmd(list);
		tmp->next = node;
	}
}

t_cmd *create_list_cmd(t_token *token, t_master *master)
{
	t_cmd *list;
	t_cmd *node;
	t_token *tmp;

	tmp = token;
	while (tmp)
	{
		node = create_node_cmd(tmp->words, master);
		if (!node)
			return (NULL);
		if (list == NULL)
			list = node;
		else
			lst_add_back_cmd(list, node);
		tmp = tmp->next;
	}
	return (list);
}
