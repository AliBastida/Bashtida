/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:50:19 by abastida          #+#    #+#             */
/*   Updated: 2024/01/08 14:15:47 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Function that checks if all quotes are closed Returns 0 if not closed;
bool paired_quotes(char *line)
{
    int i;
    int j;
    bool status;

    i = 0;
    j = -1;
    status = 1;
    while (line[i])
    {
        if (j < 0 && (line[i] == '\'' || line[i] == '\"'))
        {
            j = i;
            status = 0;
        }
        else if (j >= 0 && line[i] == line[j])
        {
            j = -1;
            status = 1;
        }
        i++;
    }
    return (status);
}

char *memory_alloc(t_master *master)
{
	int len;

	len = ft_strlen(master->line);
    master->clean_line = ft_calloc(len+1, sizeof(t_master));
    if (!master->clean_line)
        return (NULL);
    else
        return (master->clean_line);
}

// Esta funcion detecta si hay comillas y las quita de la linea.
char *clean_line(char *str, t_master *master)
{
    int i;
    int j;
    bool double_quote;
    bool simple_quote;

	i = 0;
    j = 0;
    master->clean_line = memory_alloc(master);
    double_quote = false;
    simple_quote = false;
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
      master->clean_line[j++] = str[i++];
    }
    return (master->clean_line);
}

