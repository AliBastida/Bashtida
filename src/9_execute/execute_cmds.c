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

static void	execute_heredoc(t_cmd *cmds)
{
	t_cmd	*tmp;

	tmp = cmds;
	while (tmp)
	{
		if (tmp->hd)
			ft_take_heredoc(tmp);
		tmp = tmp->next;
	}
}

static void	take_more_exit(char **str, int i)
{
	int		j;
	char	*last;

	j = 1;
	last = ft_strdup(ft_itoa(g_err));
	while (str[i][++j])
	{
		if (str[i][j] == '$' && str[i][j + 1] == '?')
			((last = ft_strjoin(last, ft_strdup(ft_itoa(g_err)))) && (++j));
		else if (ft_strchr(str[i] + j, '$'))
		{
			last = ft_strjoin(last, ft_substr(str[i], j, ft_strchr(str[i] + j,
							'$') - &str[i][j]));
			j += ft_strchr(str[i] + j, '$') - &str[i][j] - 1;
		}
		else if (!ft_strchr(str[i] + j, '$'))
		{
			last = ft_strjoin(last, ft_substr(str[i], j, ft_strlen(str[i])
						- j));
			break ;
		}
	}
	free(str[i]);
	str[i] = ft_strdup(last);
	free(last);
}

void	take_exit_value(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->args[++i])
	{
		if (!ft_strncmp(cmd->args[i], "$?", 3))
		{
			free(cmd->args[i]);
			cmd->args[i] = ft_strdup(ft_itoa(g_err));
		}
		else if (!ft_strncmp(cmd->args[i], "$?", 2))
			take_more_exit(cmd->args, i);
	}
	g_err = 0;
}

int	run_builtin(t_master *master, t_cmd *tmp)
{
	int	res;

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

int	execute_cmds(t_master *master)
{
	int		i;
	t_cmd	*tmp;
	pid_t	*pids;
	t_pipes	pipes;
	char	**env;

	i = -1;
	pipes.tmp_fd = -1;
	tmp = master->cmds;
	execute_heredoc(master->cmds);
	env = converting(master->env);
	if (master->n_cmds == 1 && is_builtin(tmp->cmd) && !check_ok(&tmp))
		return (one_builtin(master, tmp, env));
	pids = ft_calloc(master->n_cmds, sizeof(pid_t));
	while (tmp)
	{
		take_exit_value(tmp);
		if (check_cmd_and_pipes(&tmp, &pipes))
			continue ;
		pids[++i] = one_cmd(master, tmp, pipes, env);
		tmp = tmp->next;
	}
	return (close_all_pipes(master, pids, pipes, env));
}
