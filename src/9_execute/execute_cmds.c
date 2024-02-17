/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:52:12 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 18:57:32 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// execve(cmd, args, env);
// tengo que hacer una funcion que me convierta la lista del env a char ** para pasarsela a la funcion exec_ve. Esta funcion sera llamada por exec_cmd y el retorno de la transformacion
// es lo que le pasare a execve.

static void execute_heredoc(t_cmd *cmds)
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

int run_builtin(t_master *master, t_cmd *tmp)
{
	int res;

	res = 0;
	if (ft_strncmp(tmp->cmd, "echo", 5) == 0)
		res = builtin_echo(tmp->args);
	else if (ft_strncmp(tmp->cmd, "pwd", 4) == 0)
		res = builtin_pwd();
	else if (ft_strncmp(tmp->cmd, "cd", 3) == 0)
		res = builtin_cd(tmp->args[1]);
	else if (ft_strncmp(tmp->cmd, "export", 7) == 0)
		res = builtin_export(master, tmp->args);
	else if (ft_strncmp(tmp->cmd, "unset", 6) == 0)
		res = builtin_unset(&master->env, tmp->args);
	else if (ft_strncmp(tmp->cmd, "env", 4) == 0)
		res = print_env(master->env);
	else if (ft_strncmp(tmp->cmd, "exit", 5) == 0)
		res = builtin_exit(tmp->args);
	return (res);
}

// TODO gestionar la vable global $?
int execute_cmds(t_master *master)
{
	int i;
	t_cmd *tmp;
	pid_t *pids;
	t_pipes pipes; // Structura que tiene el pipe y el file descriptor temporal

	PRINT_CMD(master->cmds);
	i = 0;
	pipes.p[0] = -1;
	pipes.p[1] = -1;
	pipes.tmp_fd = -1;
	tmp = master->cmds;
	execute_heredoc(master->cmds);					 // Aqui voy a ejecutar todos los heredocs
	pids = ft_calloc(master->n_cmds, sizeof(pid_t)); // Aqui hago el malloc del puntero de todos los pids de los hijos
	while (tmp)
	{
		if (check_cmd_and_pipes(&tmp, &pipes)) // Aqui checkeo si el comando está bien y creo el pipe y gestiono el fd temporal
			continue;
		if (master->n_cmds == 1 && is_builtin(tmp->cmd)) // Este es para mirar si hay solo un comando y es un builtin
		{
			g_err = run_builtin(master, tmp);
			break;
		}
		pids[i] = one_cmd(master, tmp, pipes); // Este es la ejecucion del comando
		tmp = tmp->next;
		i++;
	}
	close_all_pipes(master, pids, pipes);
	return (1);
}
