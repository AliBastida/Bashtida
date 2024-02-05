/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:04:03 by abastida          #+#    #+#             */
/*   Updated: 2024/02/04 17:29:32 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *filename_path(char *name)
{
	char work_dir[256];
	char *filename = NULL;

	getcwd(work_dir, sizeof(work_dir));
	filename = ft_strjoin(work_dir, "/");
	filename = ft_strjoin(filename, name);
	return (filename);
}

char **take_path(t_master *path)
{
	char **split;

	// int i = 0;

	split = ft_split(get_path(path), ':');
	// while (split[i])
	//{
	//	printf("%s\n", split[i]);
	//	i++;
	// }
	return (split);
}

int ft_access(char *filename, int mod)
{
	if ((!mod && access(filename, R_OK) == 0)
		|| (mod == 1 && access(filename, W_OK) == 0)
		|| (mod == 2 && access(filename, X_OK) == 0))
		return (0);
	if ((!mod || mod == 1) && access(filename, F_OK) == 0)
	{
		if (!mod)
			return (FILE_NOT_READ);
		else
			return (FILE_NOT_WRITE);
	}
	else if (mod == 2)
	{
		if (access(filename, F_OK) == 0)
			return (COMMAND_FOUND_NOT_EX);
		return (COMMAND_NOT_FOUND);
	}
	return (FILE_NOT_FOUND);
}
