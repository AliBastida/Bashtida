/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:31:47 by pabastid          #+#    #+#             */
/*   Updated: 2023/09/22 15:34:53 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

TODO : Rehacer split primero por pipes y despues por espacios.Ha de ser una funcion que reciba ppor parametro un char c y una string.TODO : Tb he de hacer una funcion que cree nodos nuevos y lo que retorne split de pipe lo guarde en nodos mnuevos.
TODO :
																																			int
																																			is_space(t_master *master)
{
	int i = 0;
	if (master->line[i] == ' ' || master->line[i] == '\t' || master->line[i] == '\n')
		return (1);
	return (0);
}

int count_words(t_master *master)
{
	int i = 0;
	int num_word = 0;
	while (master->line[i])
	{
		if (is_space(&master->line[i]) == 1)
			i++;
		if (is_space(&master->line[i]) == 0 && (i == 0 || (is_space(&master->line[i - 1]) == 1)))
			num_word++;
		i++;
	}
	return (num_word);
}

char *saved_word(char * master->line, int start, int end)
{
	char *saved_word;
	int i = 0;
	int len = end - start + 1;
	saved_word = (char *)malloc(sizeof(char) * len);
	if (!saved_word)
		return (NULL);
	while (i < len)
	{
		saved_word[i] = master->line[start];
		start++;
		i++;
	}
	saved_word[i] = '\0';
	return (saved_word);
}

// char **split_line(char *line, char sep );  '|' ' '   no los guarda en ningun lado, lo muestra. y desde donde la llames haces otra cosa.

char **split_line(t_master *master)
{
	int x = 0;
	int i = 0;
	int start = 0;
	int end = 0;
	// split_word = (char **)malloc(sizeof(char *) * count_words(master->line) + 1); TODO: Averiguar si hay que reservar memo a split_word;
	// if (!word)
	//	return (NULL);
	while (master->line[i])
	{
		if (is_space(&master->line[i]) == 0 && (i == 0 || (is_space(&master->line[i - 1]) == 1)))
			start = i;
		if (!is_space(&master->line[i]) && ((is_space(&master->line[i + 1]) == 1 || master->line[i + 1] == '\0')))
		{
			i = i + (count_char(master));
			end = i;
			master->split_word[x] = saved_word(master->line, start, end);
			x++;
		}
		master->split_word = master->split_word->next;
		i++;
	}
	master->split_word[x] = NULL;
	return (word);
}

int count_char(t_master *master)
{
	int i;
	char q;

	i = 0;
	q[2] = '\0';
	while (master->line[i])
	{
		if (master->line[i] == '\'' || master->line[i] == '\"')
			q = master->line[i];
		else if (master->line[i] == q)
			return (i);
		i++;
	}
	return (0);
}
