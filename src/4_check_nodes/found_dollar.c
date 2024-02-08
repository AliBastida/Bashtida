/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:05:23 by abastida          #+#    #+#             */
/*   Updated: 2024/02/08 08:29:53 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Esta funcion recibe t_token y guarda cada nodo limpio de comillas y con dollar expandido
void line_ready_to_use(t_token *token, t_master *master)
{
	t_token *tmp;
	char *var_con_dolar_expandido;
	t_word *node;
	tmp = token;
	while (tmp)
	{

		node = token->words;
		while (node)
		{
			categorizing_words(node); // FIXME: TENEMOS QUE ENCONTRAR DONDE COLOCAR Y REVISAR ESTA FUNCION PORQUE SE QUEDA EN BUCLE.
			var_con_dolar_expandido = extract_dollar(node, master->env);
			printf("Dollar expanded: ----%s----\n", var_con_dolar_expandido); // es para borrar
			clean_line(var_con_dolar_expandido, master);
			printf("Quotes deleted: ----%s----\n", master->clean_line); // es para borrar
			free(node->word);
			node->word = ft_strdup(master->clean_line);
			free(master->clean_line);
			master->clean_line = NULL;
			node = node->next;
		}
		tmp = tmp->next;
	}
}

// char *ft_expand_dollar(t_word *node, t_list *env, int idx)
// {
// 	char *tmp;

// 	tmp = ft_strdup(node->word);
// 	free(node->word);
// 	printf("Getenv: -%s-\n", ft_getenv(tmp, env, idx));
// 	node->word = ft_strdup(ft_getenv(tmp, env, idx));
// 	printf("Here: %p\t%p\n", tmp, node->word); // TODO: tenemos que mirar porque da segfault si $VBLE y la vble no existe.
// 	free(tmp);
// 	return (node->word);
// }

// int checking_quotes(char *line)
// {
// 	int i;
// 	int flag;

// 	i = 0;
// 	flag = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == '\'' && flag == 0)
// 			flag = 1;
// 		else if (line[i] == '\"' && flag == 0)
// 			flag = 2;
// 	}
// 	return (flag);
// }

// return nde->word si no han habido cambios;
// char *check_to_expand(t_word *node, t_list *env)
// {
// 	int i;
// 	// char *word;
// 	int start;

// 	i = 0;
// 	start = 0;
// 	node->flag_quote = 0;
// 	printf("Node word: %s\n", node->word);
// 	while (node->word[i])
// 	{
// 		// if (node->word[i] == '\'' && node->flag_quote == 0)
// 		//{
// 		//	node->flag_quote = 1;
// 		//	start = next_quote(node->word, i + 1, node->word[i]);
// 		//	printf("node->flag_quote %d **el valor de i: %d\n", node->flag_quote, i);
// 		// }
// 		// else if (node->word[i] == '\"' && node->flag_quote == 0)
// 		//	node->flag_quote = 2;
// 		if
// 			//	else if ((node->word[i] == '$' && (is_space(node->word[i + 1]) == 0) && node->word[i + 1] != '\0' && node->flag_quote == 1))
// 			//	{
// 			//		node->flag_quote = 0;
// 			//		printf("word_quoted: ----%s------,end_node->flag_quote %d ----> el valor de i: %d\n", ft_substr(node->word, i, start - i), node->flag_quote, i);
// 			//		return (ft_substr(node->word, i, start - i));
// 			//	}
// 			i
// 			++;
// 	}
// 	return (node->word);
// }

int next_start(char *word, int i)
{
	while (ft_isalpha(word[i]) || word[i] == '_')
		i++;
	return (i);
}

static int check_quotes(t_word *node, int *i)
{
	if (node->word[*i] == '\'' && node->flag_quote == 0)
	{
		*i = next_quote(node->word, *i + 1, node->word[*i]) + 1;
		printf("node->flag_quote %d **el valor de i: %d\n", node->flag_quote, *i);
		return (1);
	}
	if (node->word[*i] == '\"' && node->flag_quote == 0)
		node->flag_quote = 2;
	if (node->word[*i] == '\"' && node->flag_quote == 2)
		node->flag_quote = 0;
	return (0);
}

char *extract_dollar(t_word *node, t_list *env)
{
	int i;
	int start;
	char *line;
	// char *var;

	i = 0;
	start = 0;
	line = ft_strdup("");
	while (node->word[i])
	{
		if (check_quotes(node, &i))
			continue;
		if (node->word[i] == '$')
		{
			line = ft_strjoin(line, ft_substr(node->word, start, i - start));
			// var = ft_getenv(&node->word[i], env, 0);
			line = ft_strjoin(line, ft_getenv(&node->word[i], env, 0));
			start = next_start(node->word, i + 1);
			i = start;
			continue;
		}
		i++;
	}
	line = ft_strjoin(line, ft_substr(node->word, start, i - start));
	free(node->word);
	node->word = line;
	return (line);
}

// TODO rehacer esta funcion
char *line_without_quo(t_word *node)
{
	// char *clean_line;
	// char *new_line;
	// int start;
	// int end;

	// clean_line = "\0";
	// end = 0;
	// start = 0;
	// if (node->word[*i + 1] && (node->word[*i] == '\'' || node->word[*i] == '\"') && node->flag_quote == 0)
	// {
	// 	start = *i + 1;
	// 	end = next_quote(node->word, *i + 1, node->word[*i]);
	// 	clean_line = ft_substr(node->word, start, end - start);
	// 	*i = end;
	// }
	// new_line = ft_substr(node->word, end + 1, ft_strlen(node->word));
	// // node->word = ft_strjoin(clean_line, new_line);
	// //	printf("*new_nodeword:%s*\n", node->word);
	return (node->word);
}
// TODO: despues de un $ solo puede ir una vble de entorno. + metacaracterres. redir o |
