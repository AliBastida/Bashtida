/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2023/12/05 11:55:26 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	t_master *master;
	master = ft_calloc(1, sizeof(t_master));
	while (1)
	{
		read_line(master);
		if (checking_syntax(master->line) == 1)
		{
			if (line_divided_in_tokens(master->line) == NULL || (!create_nodeandlist(master, master->line)) || !create_nodeandlist_word(master->node))
			{
				free_all(master);
				exit(1);
			}
			// running_through_nodes(create_nodeandlist(master->line));
		}
		free(master->line);
	}
	free(master);
	return (0);
}
// TODO meter Gitignore
/*int main(int ac, char **av)
{
	(void) ac;
	(void) av;

	t_master    *master;
	master = ft_calloc(1, sizeof(t_master));
	if (!master)
		return (0);
	while (1)
	{
		if (read_line(master))
			continue ;
	   // line_divided_in_tokens(master->line);
	//    printf("valor de strchar: %d\n", ft_strchar(master->line, '|'));
		line_divided_in_tokens(master->line);
		create_node(master->line, master);
		free(master->line);
		// return (0);
	   // printf ("resultado de check_dolar: %d\n", check_dollar(master));
	}
	free (master);
	return (0);
}*/
