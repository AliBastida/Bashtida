/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 10:37:35 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char g_err = 0;

void ft_free_double(char **str)
{
	int i;

	i = 0;
	if (str == NULL)
		return;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

static _Bool isatty_check(t_master *master)
{
	if (isatty(STDIN_FILENO) == 0 && !master->line)
		return (1);
	return (0);
}

// static void minishell_magic(t_master *master)
// {
// 	if (line_divided_in_tokens(master->line) == NULL || (!create_nodeandlist(master, master->line)) || !create_nodeandlist_word(master, master->node) || !execute_cmds(master))
// 	{
// 		// TODO hacer control, cambiar los mallloc por Calloc.
// 		free_all(master);
// 		exit(1);
// 	}
// 	// return (0) // todo ha ido bien;
// }

static void minishell_starts(t_master *master)
{
	while (1)
	{
		set_term();
		init_signal(3, master);
		if (read_line(master) == 1)
			continue;
		add_history(master->line);
		if (!checking_syntax(master->line))
		{
			init_signal(0, master);
			if (line_divided_in_tokens(master->line) == NULL || (!create_nodeandlist(master, master->line)) || !create_nodeandlist_word(master, master->node) || !execute_cmds(master))
			{
				// TODO hacer control, cambiar los mallloc por Calloc.
				free_all(master);
				exit(1);
			}
		}
		else
			free(master->line);
		init_signal(1, master);
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
	g_err = 0;
	t_master *master;
	master = ft_calloc(1, sizeof(t_master));
	ft_dup_env(master, env);
	master->status = isatty_check(master);
	while (!master->status)
		minishell_starts(master);
	ft_lstclear(&master->env, &free);
	free(master);
	return (0);
}
