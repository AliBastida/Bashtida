/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:31:30 by abastida          #+#    #+#             */
/*   Updated: 2024/02/06 15:58:49 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int syntax_error(int n)
{
    if (n == 3)
        ft_putstr_fd("Syntax Error\n", 2);
    else if (n == 0)
        ft_putstr_fd("Syntax Error\n", 2);

    return (n);
}

void ft_free_double(char **str)
{
    int i;

    i = 0;
    if (str == NULL)
        return ;
    while (str[i])
    {
        if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

void ft_free_single(char *str)
{
	if (str == NULL)
		return;
	free(str);
}

void ft_free_doble(char **str)
{
	int i;

	i = 0;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	i++;
}

bool is_space(unsigned char c)
{
	if (c == ' ' || c == '\t') //|| c == '\n' || c == '\v' || c == '\f'
							   // || c == '\r')
		return (true);		   // diferente a 0
	else
		return (false); // igual a 0
}

void *free_all(t_master *line)
{
    if (!line_divided_in_tokens(line->line))
        {
            free (line->line);
            return (NULL);
        }
    if (!create_nodeandlist(line, line->line))
        {
            free (line);
            return (NULL);
        }
    if (!divided_by_word(line->node))
        {
            free (line->node);
            return (NULL);
        }
    return (NULL);
}
