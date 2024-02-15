/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:30:43 by abastida          #+#    #+#             */
/*   Updated: 2024/01/09 12:54:38 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Y TAMBIEN SOBRE ESTAS FUNCIONES!!!

int check_redir_1(char *str)
{
    int i;

    i = 0;
	if (str[i] != '\0' && str[i] == '>')
	{
		if (str[i + 1] && str[i + 1] == '<')
			return (syntax_error(3));
		else if (str[i + 1] && str[i + 1] == '>')
		{
			if (str[i + 2] && (str[i + 2] == '<' || str[i + 2] == '>'))
				return (syntax_error(3));
		}
	}
	return (0);
}

int check_redir_2(char *str)
{
    int i;

    i = 0;
	if (str[i] && str[i] == '<')
	{
		if (str[i + 1] && str[i + 1] == '>')
			return (syntax_error(3));
		else if (str[i + 1] && str[i + 1] == '<')
		{
			if (str[i + 2] && (str[i + 2] == '>' || str[i + 2] == '<'))
				return (syntax_error(3));
		}
	}
	return (0);
}

int error_redir(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '<')
		{
			if ((str[i + 1] == ' ' && str[i + 2] == '|') || (str[i + 1] == '<' && str[i + 2] == ' ' && str[i + 3] == '|'))
				return (3);
		}
		else if (str[i] && str[i] == '>')
		{
			if ((str[i + 1] == ' ' && str[i + 2] == '|') || (str[i + 1] == '>' && str[i + 2] == ' ' && str[i + 3] == '|'))
				return (3);
		}
		i++;
	}
	return (0);
}

int redir(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{

		if (str[i] == '>' && check_redir_1(&str[i]) == 3)
			return (1);
		else if (str[i] == '<' && check_redir_2(&str[i]) == 3)
			return (1);
		else if ((str[i] == '>' || str[i] == '<') && error_redir(&str[i]) == 3)
			return (1);
		i++;
	}
	return (0);
}
