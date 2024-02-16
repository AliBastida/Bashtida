/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:30 by abastida          #+#    #+#             */
/*   Updated: 2024/02/09 12:43:11 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_copy_line(char **line, char *str)
{
	int	len;

	len = ft_strchr_quotes(str, '|') + 1;
	*line = ft_calloc(sizeof(char), len);
	if (!*line)
		exit_error("Malloc error\n");
	ft_strlcpy(*line, str, len);
	return (len);
}

char **line_divided_in_tokens(char *str, int n_pipes)
{
	int		j;
	// int n_pipes;
	int		position;
	char	**line_divided;

	j = 0;
	position = 0;
	line_divided = ft_calloc(sizeof(char *), n_pipes + 1);
	if (!line_divided)
		exit_error("Malloc error\n");
	while (n_pipes > j)
	{
		position += ft_copy_line(&line_divided[j], str + position);
		j++;
	}
	line_divided[j] = NULL;
	return (line_divided);
}
