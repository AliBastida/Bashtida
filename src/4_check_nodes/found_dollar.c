/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:05:23 by abastida          #+#    #+#             */
/*   Updated: 2023/12/06 17:12:58 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check_dollar(t_word *node)
// esta funcio chequea si el dolar esta entre comillas simples, y si no lo esta, expandir dollar.

void check_dollar(t_token *token)
{
	t_token *tmp;
	t_word *node;

	tmp = token;
	node = token->words;
	while (tmp)
	{
		while (node)
		{
			categorizing_words(node);
			check_to_expand(node);
			printf("--%d--\n", node->type);
			node = node->next;
		}

		tmp = tmp->next;
	}
}

void check_to_expand(t_word *node)
{
	int i;

	i = 0;
	node->flag_quote = 0;
	while (node->word[i])
	{
		if (node->word[i] == '\'' && node->flag_quote == 0)
		{
			node->flag_quote = 1;
			printf("node->flag_quote %d **el valor de i: %d\n", node->flag_quote, i);
		}
		else if (node->word[i] == '$' && (is_space(node->word[i + 1]) == 0) && node->word[i + 1] != '\0' && node->flag_quote != 1)
		{
			// ft_expand_dollar;
			printf("Funcion expand dollar\n");
		}
		else if (node->word[i] == '\'' && node->flag_quote == 1)
		{
			node->flag_quote = 0;
			printf("end_node->flag_quote %d ----> el valor de i: %d\n", node->flag_quote, i);
		}
		i++;
	}
}

void ft_dup_env(t_master *master, const char **envp)
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
// Si en la linea hay un dolar, chequea sin esta entre comillas dobles o no, y devuelve 1 si
// esta entre comillas dobles. Si el retorno es 1, llamaremos a otra funcion (check_after_dollar)que compruebe el siguiente caracter
// para saber lo que hay que hacer despues.
/*
bool check_dollar(t_master *line)
{
	int i;
	t_master *tmp;

	i = 0;
	tmp = line->node;
	while (tmp != NULL)
	{
		// Mirar si el char * del nodo tiene comillas simples
		if (tmp ->line[i] == '$')
		{
			printf("hemos encontrado $\n", tmp->line[i]);
			return (1);
		}
		i++;
		//tmp = tmp->node->next;
	}
	return (0);
}
*/
// FIXME No se como plantear esta funcion!!!!!
