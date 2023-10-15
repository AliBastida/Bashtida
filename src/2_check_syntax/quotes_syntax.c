/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:50:19 by abastida          #+#    #+#             */
/*   Updated: 2023/10/15 20:19:15 by abastida         ###   ########.fr       */
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

int memory_alloc(t_master *master)
{
    int len; 

    len = ft_strlen(master->line);
    master->clean_line = ft_calloc(len+1, sizeof(t_master));
    if (!master->clean_line)
        return (0);
    else
        return (1);
}


char *clean_line(char *str)
{

    int i;
    int j;
    char *clean_line;
    bool double_quote;
    bool simple_quote;
    int len = 0;
    
    i = 0;
    j = 0;
    len = ft_strlen(str);
    clean_line = ft_calloc(len + 1, sizeof(char));
    if (!clean_line)
        return (NULL);
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
        clean_line[j++] = str[i++];
    }
    return (clean_line);
}

//TODO:la funcion clean line hay que acortarla.

