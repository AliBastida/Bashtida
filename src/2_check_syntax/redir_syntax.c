/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:30:43 by abastida          #+#    #+#             */
/*   Updated: 2023/12/04 15:18:07 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int check_redir_1(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ('>'))
		{
			if (str[i+1] == '<')
				return (syntax_error(3));
			else if (str[i+1] == '>')
			{
				if (str[i+2] == '>' || str[i+2] == '<')
				   return (syntax_error(3));
				//else
				//   return(2);
			}
			i++;//return(1);
		}
		//else
		//   return (0);
		i++;
	}
	return (0);
}*/
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

int redir(char *str)
{
    int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' && check_redir_1(&str[i]) == 3)
			return (3);
		else if (str[i] == '<' && check_redir_2(&str[i]) == 3)
			return (3);
		i++;
	}
	return (1);
}
// TO-DO: essta funcion tiene que chequear todos los casos de redirecciones solas que nos dan segv.
/// @param str
/// @return
int error_redir(char *str)
{
	int i;

	i = 0;
	while (str[i])
}
