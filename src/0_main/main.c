/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 18:52:38 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char g_err = 0;

void set_term(void)
{
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

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

static void minishell_magic(t_master *master)
{
	if ((!create_nodeandlist(master, master->line)) || !create_nodeandlist_word(master, master->node) || !execute_cmds(master))
	{
		// TODO hacer control, cambiar los mallloc por Calloc.
		free_all(master);
		exit(1);
	}
	// return ((0) // todo ha ido bien);
}

static void minishell_starts(t_master *master)
{
	while (1)
	{
		set_signals(0);
		if (read_line(master) == 1)
			continue;
		add_history(master->line);
		if (!checking_syntax(master->line))
			minishell_magic(master);
		free(master->line);
		// system("leaks minishell");
		// exit(0);
	}
}

int main(int ac, char **av, const char **env)
{
	t_master *master;

	(void)av;
	if (ac > 1)
		exit_error("Minishell doesn't require any argument\n!");
	g_err = 0;
	set_term();
	master = ft_calloc(1, sizeof(t_master));
	ft_dup_env(master, env);
	minishell_starts(master);
	ft_lstclear(&master->env, &free);
	free(master);
	return (0);
}
