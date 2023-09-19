/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:50:19 by abastida          #+#    #+#             */
/*   Updated: 2023/09/19 15:10:13 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Function that checks if all quotes are closed Returns 0 if not closed;
bool paired_quotes(t_master *master)
{
    int i;
    int j;
    bool status;

    i = 0;
    j = -1;
    status = 1;
    while (master->line[i])
    {
        if (j < 0 && (master->line[i] == '\'' || master->line[i] == '\"'))
        {
            j = i;
            status = 0;
        }
        else if (j >= 0 && master->line[i] == master->line[j])
        {
            j = -1;
            status = 1;
        }
        i++;
    }
     
    return (status);
}


char *clean_line(t_master *master)
{
    int length;
    int i;
    int j;
    bool double_quote;
    bool simple_quote;

    i = 0;
    j = 0;
    length = ft_strlen(master->line);
    double_quote = false;
    simple_quote = false;
    master->clean_line = ft_calloc(length + 1, sizeof(t_master));
    if (!master->clean_line)
        return (0);
    while (master->line[i])
    {
        if ((master->line[i] == '\"' && simple_quote == false) || (master->line[i] == '\'' && double_quote == false))
        {
            if (master->line[i] == '\"')
                double_quote = !double_quote;
            else if (master->line[i] == '\'')
                simple_quote = !simple_quote;
            i++;
        }
        master->clean_line[j++] = master->line[i++];
    }
    return (master->clean_line);
}

//TO-DO:
//Norm
//hacer una funcion que ponga uan variable  a 1 si son comillas dobles o 2 si son simples. 
//hacer una funcion split que separe las palabras cuando encuentre "+sp o '+sp.
