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

static char	*check_full_path(char **new_path, char **cmd, int *ok)
{
	int	res;

	res = ft_access(*new_path, 2);
	if (!res)
	{
		free(*cmd);
		return (*new_path);
	}
	else if (res == 2)
	{
		if (!*ok)
			*ok = 3;
		free(*new_path);
		return (*cmd);
	}
	free(*new_path);
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
		*ok = 2;
	free(new_path);
	return (cmd);
}

void	ft_take_cmd(t_cmd *new, t_master *master)
{
	char	*cmd;
	char	*path;
	char	**split;

	cmd = ft_strdup(new->args[0]);
	path = ft_strdup(ft_getenv("PATH", master->env, -1));
	split = ft_split(path, ':');
	if (!cmd || !path || !split)
		exit_error("Malloc error");
	free(path);
	new->cmd = checking_path(split, cmd, &new->ok);
	ft_free_double(split);
}
