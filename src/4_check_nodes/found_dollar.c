/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:05:23 by abastida          #+#    #+#             */
/*   Updated: 2024/01/08 14:42:31 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check_dollar(t_word *node)
// esta funcio chequea si el dolar esta entre comillas simples, y si no lo esta, expandir dollar.

void check_dollar(t_token *token, const char **env)
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
			check_to_expand(node, env);
			printf("--%d--\n", node->type);
			node = node->next;
		}
		tmp = tmp->next;
	}
}

void ft_expand_dollar(t_word *node, const char **env)
{
	// TODO: tenemos que limpiar antes de passar a getenv de comillas dobles.
	printf("%s\n", ft_getenv(node->word, env));
}

void check_to_expand(t_word *node, const char **env)
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
		else if (node->word[i] == '\"' && node->flag_quote == 0)
			node->flag_quote = 2;
		else if (node->word[i] == '$' && (is_space(node->word[i + 1]) == 0) && node->word[i + 1] != '\0' && node->flag_quote != 1)
		{
			ft_expand_dollar(node, env);
		}
		else if (node->word[i] == '\'' && node->flag_quote == 1)
		{
			// TODO: Devuelve lo mismo que cogio.
			node->flag_quote = 0;
			printf("end_node->flag_quote %d ----> el valor de i: %d\n", node->flag_quote, i);
		}
		i++;
	}
}
