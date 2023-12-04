/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_nodeword.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:17:11 by pabastid          #+#    #+#             */
/*   Updated: 2023/12/04 15:03:39 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// con esta funcion si encontramos '' o "" en el nodo de t_word expandimos la variable o lo dejamos tal cual
int parsing_quotes_nodeword(t_word *node)
{
	int i;

	i = 0;
	while (node->word[i])
	{
		if (node->word[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

// con esta funcion adjudicamos un valor a cada redir usando ENUM
void categorizing_words(t_word *node)
{
	int i;

	i = 0;
	while (node->word[i])
	{
		if (node->word[i] == '<' && node->word[i + 1] == '<')
		{
			node->type = REDIR_A;
			i++;
		}
		else if (node->word[i] == '>' && node->word[i + 1] == '>')
		{
			node->type = REDIR_B;
			i++;
		}
		else if (node->word[i] == '<')
			node->type = REDIR_C;
		else if (node->word[i] == '>')
			node->type = REDIR_D;
		else if (node->word[i] == '$')
			node->type = EXPANSION;
		i++;
	}
}

// con esta funcion si la redireccion es ok, retorna (1), continua trabajando y llamariamos a valid_redir; si no es ok, retorna (0) y retorna (syntax error)
/*int parsing_redir_nodeword(t_word *node, char *word)
{
}*/

// Aqui hacemos el parsing final de forma que ejecuta tanto las comillas como las redirecciones en caso de esten correctas
// parsing_nodeword(char *word)
