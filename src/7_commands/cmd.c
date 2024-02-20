/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 18:10:13 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*take_relative_cmd(char *cmd)
{
	char	*tmp;
	char	*new;
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		tmp = ft_strjoin(cwd, "/");
		if (!tmp)
			exit_error("Malloc error\n");
		new = ft_strjoin(tmp, cmd);
		if (!new)
			exit_error("Malloc error\n");
		free(tmp);
		return (new);
	}
	exit_error("Getcwd error\n");
	return (NULL);
}

static char	*check_full_path(char **new_path, char **cmd, int *ok)
{
	int	res;

	res = ft_access(*new_path, 2);
	if (!res)
	{
		free(*cmd);
		return (*new_path);
	}
	else if (res == COMMAND_FOUND_NOT_EX)
	{
		if (!*ok)
			*ok = res;
		free(*new_path);
		return (*cmd);
	}
	free(*new_path);
	*new_path = NULL;
	return (NULL);
}

static char	*checking_path(char **path, char *cmd, int *ok)
{
	int		i;
	char	*ret;
	char	*tmp;
	char	*new_path;

	i = -1;
	if (is_builtin(cmd) == 1)
		return (cmd);
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			exit_error("Malloc error");
		new_path = ft_strjoin(tmp, cmd);
		if (!new_path)
			exit_error("Malloc error");
		free(tmp);
		ret = check_full_path(&new_path, &cmd, ok);
		if (ret)
			return (ret);
	}
	if (!*ok)
		*ok = COMMAND_NOT_FOUND;
	free(new_path);
	return (cmd);
}

void	ft_take_cmd(t_cmd *new, t_master *master)
{
	char	*cmd;
	char	*path;
	char	**split;

	cmd = ft_strdup(new->args[0]);
	path = ft_getenv("PATH", master->env, -1);
	if (path[0] == '\0' && !is_builtin(cmd))
	{
		free(path);
		new->cmd = cmd;
		new->ok = 1;
		return ;
	}
	split = ft_split(path, ':');
	if (!cmd || !path || !split)
		exit_error("Malloc error");
	if (cmd[0] == '/')
		new->cmd = cmd;
	else if (cmd[0] == '.' && cmd[1] == '/')
		new->cmd = take_relative_cmd(cmd);
	else
		new->cmd = checking_path(split, cmd, &new->ok);
	ft_free_double(split);
}
