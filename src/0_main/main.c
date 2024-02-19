/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 17:55:55 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	g_err = 0;

static void	ft_dup_env(t_master *master, const char **env)
{
	int		i;
	char	*dup;

	i = 0;
	while (env != NULL && env[i])
	{
		dup = ft_strdup(env[i]);
		if (!dup)
			exit_error("Malloc error\n");
		if (master->env == NULL)
			master->env = ft_lstnew(dup);
		else
			ft_lstadd_back(&master->env, ft_lstnew(dup));
		i++;
	}
}

static void	set_term(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void	minishell_magic(t_master *master)
{
	create_token_list(master, master->line);
	create_word_list(master, master->node);
	execute_cmds(master);
	free_all(master, 0);
}

static void	minishell_starts(t_master *master)
{
	int	i;

	i = 0;
	while (1)
	{
		set_signals(0);
		if (read_line(master) == 1)
			continue ;
		add_history(master->line);
		if (!checking_syntax(master->line))
			minishell_magic(master);
		i++;
	}
}

int	main(int ac, char **av, const char **env)
{
	t_master	*master;

	(void)av;
	if (ac > 1)
		exit_error("Minishell doesn't require any argument\n!");
	set_term();
	master = ft_calloc(1, sizeof(t_master));
	if (!master)
		exit_error("Malloc error\n");
	ft_dup_env(master, env);
	minishell_starts(master);
	free_all(master, 1);
	return (0);
}
