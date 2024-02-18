/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:17:06 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 18:03:04 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	categorizing_words(t_word *node)
{
	int	i;

	i = 0;
	if (node->word[i] == '<' && node->word[i + 1] == '<')
	{
		node->type = REDIR_A;
		i++;
	}
	else if (node->word[i] == '>' && node->word[i + 1] == '>')
	{
		node->type = REDIR_B;
		i++;
	}
	else if (node->word[i] == '<')
		node->type = REDIR_C;
	else if (node->word[i] == '>')
		node->type = REDIR_D;
	i++;
}

void	line_ready_to_use(t_token *token, t_master *master)
{
	t_word	*node;
	t_token	*tmp;
	char	*str_expanded;

	tmp = token;
	str_expanded = NULL;
	while (tmp)
	{
		node = token->words;
		while (node)
		{
			str_expanded = extract_dollar(node, master->env);
			clean_line(str_expanded, node);
			free(str_expanded);
			str_expanded = NULL;
			node = node->next;
		}
		tmp = tmp->next;
	}
}

int	is_redir(char *str, int i)
{
	if (str[i] != '\0' && (str[i] == '>' || str[i] == '<'))
	{
		if ((str[i + 1]) != '\0' && (str[i + 1] == str[i]))
			return (2);
		return (1);
	}
	return (0);
}

char	*substr_words(t_token *tmp, int start, int i)
{
	char	*new;
	char	*rest;

	new = ft_substr(tmp->content_token, start, i - start + 1);
	if (!new)
		exit_error("Malloc error");
	rest = ft_substr(tmp->content_token, i + 1, ft_strlen(tmp->content_token));
	if (!rest)
		exit_error("Malloc error");
	free(tmp->content_token);
	if (!ft_strncmp(rest, "", 1))
	{
		free(rest);
		tmp->content_token = NULL;
	}
	else
		tmp->content_token = rest;
	return (new);
}
