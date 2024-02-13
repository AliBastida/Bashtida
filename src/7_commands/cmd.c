/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:32 by abastida          #+#    #+#             */
/*   Updated: 2024/02/10 16:33:28 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *check_full_path(char **new_path, char **cmd, int *ok)
{
	int res;

	res = ft_access(*new_path, 2);
	if (!res)
	{
		printf("este es mi cmd: %s \n", *new_path);
		// *ok = 0;
		free(*cmd);
		return (*new_path);
	}
	else if (res == 2)
	{
		if (!*ok)
			*ok = 3;
		//		printf("%s", g_error_array[*ok - 1]);
		free(*new_path);
		return (*cmd);
	}
	return (NULL);
}

char *checking_path(char **path, char *cmd, int *ok)
{
	int i;
	char *ret;
	char *new_path;

	i = 0;
	if (is_builtin(cmd) == 1)
		return (cmd);
	while (path[i])
	{
		new_path = ft_strjoin(path[i], "/");
		new_path = ft_strjoin(new_path, cmd);
		ret = check_full_path(&new_path, &cmd, ok);
		if (ret)
			return (ret);
		// res = ft_access(new_path, 2);
		// 		if (access(new_path, X_OK) == 0)
		// 		{
		// 			printf("este es mi cmd: %s \n", new_path);
		// 			// *ok = 0;
		// 			free(cmd);
		// 			return (new_path);
		// 		}
		// 		else if (access(new_path, F_OK) == 0)
		// 		{
		// 			if (!*ok)
		// 				*ok = 3;
		//			printf("%s", g_error_array[*ok - 1]);
		// 			free(new_path);
		// 			return (cmd);
		// 		}
		i++;
	}
	if (!*ok)
		*ok = 2;
	//	printf("%s", g_error_array[*ok - 1]);
	free(new_path);
	return (cmd);
}

void ft_take_cmd(t_cmd *new, t_word *words, t_master *master)
{
	char *cmd;
	char *path;
	char **split;

	(void)words;

	// if (words->type == 1 || words->type == 2 || words->type == 3 || words->type == 4)
	// {
	// 	cmd = ft_strdup(words->next->next->word);
	// 	printf("el next next->word: %s y cmd: %s\n", words->next->next->word, cmd);
	// }
	// else
	cmd = ft_strdup(new->args[0]);
	path = ft_strdup(ft_getenv("PATH", master->env, -1));
	split = ft_split(path, ':');
	free(path);
	new->cmd = checking_path(split, cmd, &new->ok);
	ft_free_double(split);
}

// char *get_path(t_master *master)
// {
// 	char *path;
// 	path = ft_strdup(ft_getenv("PATH", master->env, -1));
// 	return (path);
// }
