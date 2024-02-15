/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:31:30 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 10:27:22 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int syntax_error(char *str, char c, int out)
{
	ft_putstr_fd(str, 2);
	if (c > 0)
	{
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\'', 2);
		ft_putchar_fd('\n', 2);
	}
	g_err = 2;
	return (out);
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
// true = diferente a 0
// false = igual a 0
bool is_space(unsigned char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	else
		return (false);
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
