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

static int	next_start(char *word, int i)
{
	while (ft_isalpha(word[i]) || word[i] == '_')
		i++;
	return (i);
}

static int	check_quotes(t_word *node, int *i)
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

static char	*get_last_line(t_word *node, char *line, int start, int i)
{
	char	*tmp;

	if (start == i)
		return (line);
	if (!line)
		tmp = ft_substr(node->word, start, i - start);
	else
		tmp = ft_strjoin(line, ft_substr(node->word, start, i - start));
	if (!tmp)
		exit_error("Malloc error\n");
	free(line);
	return (tmp);
}

static char	*get_env_var(t_word *node, t_list *env, char *line, int *i)
{
	char	*tmp;
	char	*env_var;

	if (node->word[*i + 1] == '?' && !ft_isalnum(node->word[*i + 2]))
	{
		if (!line)
			tmp = ft_strdup("$?");
		else
			tmp = ft_strjoin(line, "$?");
		(*i)++;
	}
	else
	{
		env_var = ft_strdup(ft_getenv(&node->word[*i], env, 0));
		if (!line)
			return (env_var);
		tmp = ft_strjoin(line, env_var);
		free(env_var);
	}
	if (!tmp)
		exit_error("Malloc error\n");
	free(line);
	return (tmp);
}

char	*extract_dollar(t_word *node, t_list *env)
{
	int		i;
	int		start;
	char	*line;

	i = 0;
	start = 0;
	line = NULL;
	while (node->word[i])
	{
		if (check_quotes(node, &i))
			continue ;
		if (node->word[i] == '$')
		{
			line = get_last_line(node, line, start, i);
			line = get_env_var(node, env, line, &i);
			start = next_start(node->word, i + 1);
			i = start;
			continue ;
		}
		i++;
	}
	line = get_last_line(node, line, start, i);
	return (line);
}
