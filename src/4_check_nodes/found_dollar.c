/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:05:23 by abastida          #+#    #+#             */
/*   Updated: 2024/01/15 09:56:07 by abastida         ###   ########.fr       */
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
	printf("1@@@@@@\n");
	while (token && tmp->next != NULL)
	{
		printf("2@@@@@\n");
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

void ft_expand_dollar(t_word *node, const char **env)
{
	printf("Getenv: -%s-\n", ft_getenv(node->word, env));
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
		{
			ft_expand_dollar(node, env);
		}
		else if (node->word[i] == '\'' && node->flag_quote == 1)
		{
			// TODO: Devuelve lo mismo que cogio, sin las comillas, incluyendo el $
			word_quoted = ft_substr(node->word, i, start - i);
			node->flag_quote = 0;
			printf("word_quoted: ----%s------,end_node->flag_quote %d ----> el valor de i: %d\n", word_quoted, node->flag_quote, i);
		}
		i++;
	}
}
// TODO: despues de un $ solo puede ir una vble de entorno. + metacaracterres. redir o |

/*char *if_single_quote(char *word, int *i)
{
	char *word_quoted;

	word_quoted = "null";
	word_quoted = ft_substr
}
*/
