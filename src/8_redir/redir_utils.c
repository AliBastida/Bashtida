/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:04:03 by abastida          #+#    #+#             */
/*   Updated: 2024/02/04 10:11:18 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *filename_path(char **path, char *name)
{
	char *filename = NULL;
	int i;

	i = 0;
	// if (is_builtin(cmd) == TRUE)
	//	return (cmd);
	while (path[i])
	{
		filename = ft_strjoin(path[i], "/");
		printf("newpath %s\n", filename);
		filename = ft_strjoin(filename, name);
		printf("filename %s\n", filename);
		if (ft_access(filename) == 0)
			return (filename);
		else
			i++;
	}
	//*ok = 0;
	return (name);
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

int ft_access(char *filename)
{
	if (access(filename, R_OK) == 0)
		return (0);
	else if (access(filename, F_OK) == 0)
		return (FILE_NOT_READ);
	return (FILE_NOT_FOUND);
}
