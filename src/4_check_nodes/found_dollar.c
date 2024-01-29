/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:05:23 by abastida          #+#    #+#             */
/*   Updated: 2024/01/29 14:53:21 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void check_dollar(t_token *token, const char **env)
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

void ft_expand_dollar(t_word *node, const char **env, int idx)
{
	printf("Getenv: -%s-\n", ft_getenv(node->word, env, idx));
}

void check_to_expand(t_word *node, const char **env)
{
	int i;
	char *word_quoted;
	int start;

	i = 0;
	start = 0;
	node->flag_quote = 0;
	while (node->word[i])
	{
		if (node->word[i] == '\'' && node->flag_quote == 0)
		{
			node->flag_quote = 1;
			start = next_quote(node->word, i + 1, node->word[i]);
			printf("node->flag_quote %d **el valor de i: %d\n", node->flag_quote, i);
		}
		else if (node->word[i] == '\"' && node->flag_quote == 0)
			node->flag_quote = 2;
		else if (node->word[i] == '$' && (is_space(node->word[i + 1]) == 0) && node->word[i + 1] != '\0' && node->flag_quote != 1)
			ft_expand_dollar(node, env, i);
		else if ((node->word[i] == '$' && (is_space(node->word[i + 1]) == 0) && node->word[i + 1] != '\0' && node->flag_quote == 1))
		{
			word_quoted = ft_substr(node->word, i, start - i);
			node->flag_quote = 0;
			printf("word_quoted: ----%s------,end_node->flag_quote %d ----> el valor de i: %d\n", word_quoted, node->flag_quote, i);
		}
		i++;
	}
}
// TODO: despues de un $ solo puede ir una vble de entorno. + metacaracterres. redir o |
