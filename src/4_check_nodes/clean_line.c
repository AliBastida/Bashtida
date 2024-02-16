/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:50:19 by abastida          #+#    #+#             */
/*   Updated: 2024/02/09 12:14:47 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int len_without_quotes(char *str)
{
	int i;
	int len;
	bool double_quote;
	bool simple_quote;

	i = -1;
	len = 0;
	double_quote = false;
	simple_quote = false;
	while (str[++i])
	{
		if ((str[i] == '\"' && simple_quote == false) || (str[i] == '\'' && double_quote == false))
		{
			if (str[i] == '\"')
				double_quote = !double_quote;
			else if (str[i] == '\'')
				simple_quote = !simple_quote;
		}
		else
			len++;
	}
	return (len);
}

static void memory_alloc(t_master *master, char *str)
{
	int len;

	len = ft_strlen(str);
	master->clean_line = ft_calloc(len_without_quotes(str) + 1, sizeof(char));
	// printf("Len without quotes: %d\twith: %zu\n", len_without_quotes(str), ft_strlen(str));
	// estamos allocando mas memoria,
	// xq estamos contando memoria incluyenddo las comillas.
	// TODO AHORA NO
	if (!master->clean_line)
		exit_error("Malloc error\n");
}

// Esta funcion detecta si hay comillas y las quita de la linea.
void clean_line(char *str, t_master *master)
{
	int i;
	int j;
	bool double_quote;
	bool simple_quote;

	i = 0;
	j = 0;
	double_quote = false;
	simple_quote = false;
	memory_alloc(master, str);
	while (str[i])
	{
		if ((str[i] == '\"' && simple_quote == false) || (str[i] == '\'' && double_quote == false))
		{
			if (str[i] == '\"')
				double_quote = !double_quote;
			else if (str[i] == '\'')
				simple_quote = !simple_quote;
			i++;
		}
		else if (str[i] != '\0')
			master->clean_line[j++] = str[i++];
	}
	// printf("Master line: %s\n", master->clean_line);
}
