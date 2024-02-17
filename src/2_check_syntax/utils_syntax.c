/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:32:26 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 19:07:34 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	paired_quotes(char *line)
{
	int		i;
	int		j;
	bool	status;

	i = 0;
	j = -1;
	status = 0;
	while (line[i])
	{
		if (j < 0 && (line[i] == '\'' || line[i] == '\"'))
		{
			j = i;
			status = 1;
		}
		else if (j >= 0 && line[i] == line[j])
		{
			j = -1;
			status = 0;
		}
		i++;
	}
	return (status);
}

static int	redir(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			j = i + 1;
			if (str[i] == str[j])
				j++;
			while (str[j] && str[j] == ' ')
				j++;
			if (str[j] == '\0')
				return (1);
			else if (str[j] == '|')
				return (2);
			else if (str[j] == '<' || str[j] == '>')
				return (str[j]);
			i = j;
		}
	}
	return (0);
}

int	checking_syntax(char *str)
{
	int	res;

	if (paired_quotes(str))
		return (syntax_error("Syntax Error: quotes not closed\n", 0, 1));
	else if (check_syntax_pipes(str))
		return (syntax_error("Bashtida: syntax error near "
								"unexpected token `|'\n",
								0,
								1));
	res = redir(str);
	if (res == 1)
		return (syntax_error("Bashtida: syntax error near "
								"unexpected token `newline'\n",
								0,
								1));
	else if (res == 2)
		return (syntax_error("Bashtida: syntax error near "
								"unexpected token `|'\n",
								0,
								1));
	else if (res > 2)
		return (syntax_error("Bashtida: syntax error near "
								"unexpected token `",
								res,
								1));
	return (0);
}
