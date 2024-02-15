/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:05:23 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 09:59:08 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Esta funcion recibe t_token y guarda cada nodo limpio de comillas y con dollar expandido
void line_ready_to_use(t_token *token, t_master *master)
{
	t_token *tmp;
	char *var_con_dolar_expandido;
	t_word *node;
	tmp = token;
	while (tmp)
	{
		node = token->words;
		while (node)
		{
			var_con_dolar_expandido = extract_dollar(node, master->env);
			clean_line(var_con_dolar_expandido, master);
			free(node->word);
			node->word = ft_strdup(master->clean_line);
			free(master->clean_line);
			master->clean_line = NULL;
			node = node->next;
		}
		tmp = tmp->next;
	}
}

int next_start(char *word, int i)
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
	while (node->word[i])
	{
		if (check_quotes(node, &i))
			continue;
		if (node->word[i] == '$')
		{
			// FIXME: PONEMOS AQUI SI ES $+? ??????
			line = ft_strjoin(line, ft_substr(node->word, start, i - start));
			line = ft_strjoin(line, ft_getenv(&node->word[i], env, 0));
			start = next_start(node->word, i + 1);
			i = start;
			continue;
		}
		i++;
	}
	line = ft_strjoin(line, ft_substr(node->word, start, i - start));
	free(node->word);
	node->word = line;
	return (line);
}
