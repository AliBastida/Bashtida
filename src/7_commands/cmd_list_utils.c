/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:35:20 by abastida          #+#    #+#             */
/*   Updated: 2024/02/09 12:48:35 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// tenemos que hacer un malloc con el numero de nodos de t_word qye no son redirecciones ni lo siguiente para crear el char ** del nodo.
// tenemos que, con strdup copiar en el char **los args (incluido el cmd).
// despues, en otra funcion, copiamos la posicion [0] del char en char *cmd y en otra funcion comprobamos si el path existe y es ejecutable o no.
// otra funcion que ejecute el cmd.
// FIXME: SE PASA DE LINEAS -> VALERIO: LO ARREGLO YO

// FIXME: ME DA LA SENSACION DE QUE NO EXPANDE $VBLE SI ES ARG Y NO CMD. HAY QUE REVISARLO

t_cmd *new_cmd(t_word *words, int n)
{
	t_cmd *new;

	new = ft_calloc(sizeof(t_cmd), 1);
	if (!new)
		exit_error("Malloc error");
	new->n = n;
	new->out_fd = 1;
	new->args = ft_calloc(sizeof(char *), n_args(words) + 1);
	if (!new->args)
		exit_error("Malloc error");
	return (new);
}

t_cmd *create_node_cmd(t_word *words, t_master *master, int n)
{
	int i;
	t_cmd *new;
	t_word *tmp;

	i = 0;
	tmp = words;
	new = new_cmd(words, n);
	if (!new)
		return (NULL);
	while (tmp)
	{
		if (tmp->type == 1 || tmp->type == 2 || tmp->type == 3 || tmp->type == 4)
		{
			manage_redir(tmp, new);
			tmp = tmp->next;
		}
		else
			new->args[i++] = ft_strdup(tmp->word);
		tmp = tmp->next;
	}
	if (new->args[0])
		ft_take_cmd(new, master);
	return (new);
}

t_cmd *create_list_cmd(t_token *token, t_master *master)
{
	int		i;
	t_cmd	*list;
	t_cmd	*node;
	t_token	*tmp;

	i = 0;
	tmp = token;
	list = NULL;
	while (tmp)
	{
		node = create_node_cmd(tmp->words, master, i);
		if (!node)
			return (NULL);
		if (list == NULL)
			list = node;
		else
			lst_add_back_cmd(list, node);
		tmp = tmp->next;
		i++;
	}
	return (list);
}
