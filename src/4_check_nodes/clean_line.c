/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:50:19 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 15:25:18 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_without_quotes(char *str)
{
	int		i;
	int		len;
	bool	double_quote;
	bool	simple_quote;

	i = -1;
	len = 0;
	double_quote = false;
	simple_quote = false;
	while (str[++i])
	{
		if ((str[i] == '\"' && simple_quote == false) || (str[i] == '\''
				&& double_quote == false))
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

void	clean_line(char *str, t_word *node)
{
	int		i;
	int		j;
	bool	double_quote;
	bool	simple_quote;

	i = 0;
	j = 0;
	double_quote = false;
	simple_quote = false;
	free(node->word);
	node->word = ft_calloc(len_without_quotes(str) + 1, sizeof(char));
	while (str[i])
	{
		if ((str[i] == '\"' && simple_quote == false) || (str[i] == '\''
				&& double_quote == false))
		{
			if (str[i] == '\"')
				double_quote = !double_quote;
			else if (str[i] == '\'')
				simple_quote = !simple_quote;
			i++;
		}
		else if (str[i] != '\0')
			node->word[j++] = str[i++];
	}
}
