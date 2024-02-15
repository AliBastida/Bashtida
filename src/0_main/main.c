/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2024/02/10 16:41:18 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	g_err = 0;

static void minishell_starts(t_master *master)
{
	while (1)
	{
		if (read_line(master) == 1)
			continue;
		add_history(master->line);
		if (!checking_syntax(master->line))
		{
			if (line_divided_in_tokens(master->line) == NULL || (!create_nodeandlist(master, master->line)) || !create_nodeandlist_word(master, master->node) || !execute_cmds(master))
			{
				// TODO hacer control, cambiar los mallloc por Calloc.
				free_all(master);
				exit(1);
			}
		}
		free(master->line);
		// system("leaks minishell");
		// exit(0);
	}
}

int main(int ac, char **av, const char **env)
{
	(void)ac;
	(void)av;

	if (ac > 1)
		exit_error("Minishell doesn't require any argument\n!");
	t_master *master;
	master = ft_calloc(1, sizeof(t_master));
	ft_dup_env(master, env);
	minishell_starts(master);
	ft_lstclear(&master->env, &free);
	free(master);
	return (0);
}
