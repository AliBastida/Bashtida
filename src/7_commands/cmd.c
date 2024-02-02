/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/02 15:52:10 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *checking_path(char **path, char *cmd, int *ok)
{
	char *new_path;
	int i;

	i = 0;
	// if (is_builtin(cmd) == TRUE)
	//	return (cmd);
	while (path[i])
	{
		new_path = ft_strjoin(path[i], "/");
		new_path = ft_strjoin(new_path, cmd);
		if (access(new_path, X_OK) == 0)
		{
			printf("este es mi cmd: %s \n", new_path);
			*ok = 0;
			return (new_path);
		}
		else if (access(new_path, F_OK) == 0)
		{
			*ok = 3;
			printf("%s", g_error_array[*ok - 1]);
			free(new_path);
			return (cmd);
		}
		i++;
	}
	*ok = 2;
	printf("%s", g_error_array[*ok - 1]);
	free(new_path);
	return (cmd);
}

void ft_take_cmd(t_cmd *new, t_word *words, t_master *master)
{
	char *cmd;
	char **split;

	if (words->type == 1 || words->type == 2 || words->type == 3 || words->type == 4)
		cmd = ft_strdup(words->next->next->word);
	else
		cmd = ft_strdup(words->word);
	split = ft_split(get_path(master), ':');
	new->cmd = checking_path(split, cmd, &new->ok);
	free(cmd);
	ft_free_double(split);
}

char *get_path(t_master *master)
{
	char *path;
	path = ft_strdup(ft_getenv("PATH", master->env, -1));
	return (path);
}
