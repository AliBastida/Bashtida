/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:52:12 by abastida          #+#    #+#             */
/*   Updated: 2024/02/14 18:14:26 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// execve(cmd, args, env);
// tengo que hacer una funcion que me convierta la lista del env a char ** para pasarsela a la funcion exec_ve. Esta funcion sera llamada por exec_cmd y el retorno de la transformacion
// es lo que le pasare a execve.

int run_builtin(t_master *master, t_cmd *tmp)
{
	if (ft_strncmp(tmp->cmd, "echo", 5) == 0)
		builtin_echo(tmp->args);
	if (ft_strncmp(tmp->cmd, "pwd", 4) == 0)
		builtin_pwd();
	else if (ft_strncmp(tmp->cmd, "cd", 3) == 0)
		builtin_cd(tmp->args[1]);
	else if (ft_strncmp(tmp->cmd, "export", 7) == 0)
		builtin_export(master, tmp->args);
	else if (ft_strncmp(tmp->cmd, "unset", 6) == 0)
		builtin_unset(&master->env, tmp->args);
	else if (ft_strncmp(tmp->cmd, "env", 4) == 0)
		print_env(master->env);
	else if (ft_strncmp(tmp->cmd, "exit", 5) == 0)
		builtin_exit(tmp->args);
	return (0);
}

char **converting(t_list *env)
{
	char **env_char;
	int i;

	i = 0;
	env_char = ft_calloc(sizeof(char *), (ft_lstsize(env) + 1));
	if (!env_char)
		return (NULL);
	while (env && env->content)
	{
		env_char[i] = ft_strdup(env->content);
		env = env->next;
		i++;
	}
	return (env_char);
}

void execute_heredoc(t_cmd *cmds)
{
	t_cmd *tmp;

	tmp = cmds;
	while (tmp)
	{
		if (tmp->hd)
			ft_take_heredoc(tmp);
		tmp = tmp->next;
	}
}

// TODO gestionar la vable global $?
int execute_cmds(t_master *master)
{
	int i;
	pid_t *pids;
	t_cmd *tmp;
	t_pipes pipes;

	i = 0;
	pipes.p[0] = -1;
	pipes.p[1] = -1;
	pipes.tmp_fd = -1;
	tmp = master->cmds;
	execute_heredoc(master->cmds);
	pids = ft_calloc(master->n_cmds, sizeof(pid_t));
	while (tmp)
	{
		if (check_cmd_and_pipes(&tmp, &pipes))
			continue;
		if (master->n_cmds == 1 && is_builtin(tmp->cmd))
		{
			g_err = run_builtin(master, tmp);
			break;
		}
		pids[i] = loop_cmds(master, tmp, pipes);
		tmp = tmp->next;
		i++;
	}
	close_all_pipes(master, pids, pipes);
	return (1);
}
