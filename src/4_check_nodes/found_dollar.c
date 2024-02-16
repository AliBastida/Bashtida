/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:05:23 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 17:55:12 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int next_start(char *word, int i)
{
	while (ft_isalpha(word[i]) || word[i] == '_')
		i++;
	return (i);
}

static int check_quotes(t_word *node, int *i)
{
	if (node->word[*i] == '\'' && node->flag_quote == 0)
	{
		*i = next_quote(node->word, *i + 1, node->word[*i]) + 1;
		return (1);
	}
	if (node->word[*i] == '\"' && node->flag_quote == 0)
		node->flag_quote = 2;
	if (node->word[*i] == '\"' && node->flag_quote == 2)
		node->flag_quote = 0;
	return (0);
}

char *extract_dollar(t_word *node, t_list *env)
{
	int i;
	int start;
	char *line;

	i = 0;
	start = 0;
	line = ft_strdup("");
	if (!line)
		exit_error("Malloc error\n");
	while (node->word[i])
	{
		if (check_quotes(node, &i))
			continue;
		if (node->word[i] == '$')
		{
			line = ft_strjoin(line, ft_substr(node->word, start, i - start));
			line = ft_strjoin(line, ft_getenv(&node->word[i], env, 0));
			if (!line)
				exit_error("Malloc error\n");
			start = next_start(node->word, i + 1);
			i = start;
			continue;
		}
		i++;
	}
	line = ft_strjoin(line, ft_substr(node->word, start, i - start));
	if (!line)
		exit_error("Malloc error\n");
	free(node->word);
	node->word = line;
	return (line);
}
