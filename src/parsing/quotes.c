/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:50:19 by abastida          #+#    #+#             */
/*   Updated: 2023/09/22 13:14:32 by pabastid         ###   ########.fr       */
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

int memory_alloc(t_master *master)
{
	int len;

	len = ft_strlen(master->line);
	master->clean_line = ft_calloc(len + 1, sizeof(t_master));
	if (!master->clean_line)
	{
		free(master->clean_line);
		return (0);
	}
	else
		return (1);
}


char *clean_line(t_master *master)
{
	int i;
	int j;
	bool double_quote;
	bool simple_quote;

	i = 0;
	j = 0;
	double_quote = false;
	simple_quote = false;
	if (memory_alloc(master) == 1)
	{
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
   else
    exit(1);
}

/*bool what_type_ofquotes(t_master *master)
{
   int i;
   bool type;

   i = 0;
   type = 0;
   while (master->line[i] && paired_quotes(master) == 1)
   {
	if (master->line[i] == '\"')
			type = 1;
	else if (master->line[i] == '\'')
			type = 0;
	i++;
   }
   return (type);
}*/

// TODO:Norm
// TODO:hacer una funcion que ponga uan variable  a 1 si son comillas dobles o 2 si son simples.
// TODO:hacer una funcion split que separe las palabras cuando encuentre "+sp o '+sp.
