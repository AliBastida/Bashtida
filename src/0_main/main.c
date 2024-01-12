/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2024/01/12 10:58:39 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, const char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	t_master *master;
	master = ft_calloc(1, sizeof(t_master));
	ft_dup_env(master, env);
	// PRINT_LIST(master->env);
	while (1)
	{
		if (read_line(master) == 1)
			continue;
		if (checking_syntax(master->line) == 1)
		{
			if (line_divided_in_tokens(master->line) == NULL || (!create_nodeandlist(master, master->line)) || !create_nodeandlist_word(master->node, env))
			{
				free_all(master);
				exit(1);
			}
			if (master->line && *master->line != '\0')
				add_history(master->line);
			// running_through_nodes(create_nodeandlist(master->line));
		}
		free(master->line);
	}
	ft_lstclear(&master->env, &free);
	free(master);
	return (0);
}
