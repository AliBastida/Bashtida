/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:05:23 by abastida          #+#    #+#             */
/*   Updated: 2024/02/06 13:52:39 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void check_dollar(t_token *token, t_list *env)
{
	t_token *tmp;
	t_word *node;
	tmp = token;
	while (tmp)
	{
		node = token->words;
		while (node)
		{
			printf("Categorize: -%s-\t-%p-\n", node->word, node);
			categorizing_words(node);
			check_to_expand(node, env);
			printf("--%d--\n", node->type);
			node = node->next;
		}
		tmp = tmp->next;
	}
}

void ft_expand_dollar(t_word *node, t_list *env, int idx)
{
	char *tmp;

	tmp = ft_strdup(node->word);
	free(node->word);
	printf("Getenv: -%s-\n", ft_getenv(tmp, env, idx));
	node->word = ft_strdup(ft_getenv(tmp, env, idx));
	printf("Here: %p\t%p\n", tmp, node->word); // TODO: tenemos que mirar porque da segfault si $VBLE y la vble no existe.
	free(tmp);
}

void check_to_expand(t_word *node, t_list *env)
{
	int i;
	char *word_quoted;
	int start;

	i = 0;
	start = 0;
	node->flag_quote = 0;
	printf("Node word: %s\n", node->word);
	while (node->word[i])
	{
		if (node->word[i] == '\'' && node->flag_quote == 0)
		{
			printf("line sin comillas: ****%s***\n", line_without_quo(node, &i));
			node->flag_quote = 1;
			start = next_quote(node->word, i + 1, node->word[i]);
			printf("node->flag_quote %d **el valor de i: %d\n", node->flag_quote, i);
		}
		else if (node->word[i] == '\"' && node->flag_quote == 0)
			node->flag_quote = 2;
		else if (node->word[i] == '$' && (is_space(node->word[i + 1]) == 0) && node->word[i + 1] != '\0' && node->flag_quote != 1) // gestiona que $este en comillas dobles o sin comillas
			ft_expand_dollar(node, env, i);
		else if ((node->word[i] == '$' && (is_space(node->word[i + 1]) == 0) && node->word[i + 1] != '\0' && node->flag_quote == 1)) // gestiona quue el dolar este en comillas simples
		{
			word_quoted = ft_substr(node->word, i, start - i);
			node->flag_quote = 0;
			printf("word_quoted: ----%s------,end_node->flag_quote %d ----> el valor de i: %d\n", word_quoted, node->flag_quote, i);
		}
		i++;
	}
}

char *line_without_quo(t_word *node, int *i)
{
	char *clean_line;
	int start;

	clean_line = "\0";
	start = 0;
	while (node->word[*i])
	{
		if ((node->word[*i] == '\'' || node->word[*i] == '\"') && node->flag_quote == 0)
		{
			start = *i + 1;
			*i = next_quote(node->word, *i + 1, node->word[*i]);
			clean_line = ft_substr(node->word, start, (*i - 1) - start);
		}
		i++;
	}
	return (clean_line);
}
// TODO: despues de un $ solo puede ir una vble de entorno. + metacaracterres. redir o |
