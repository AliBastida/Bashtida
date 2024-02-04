/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 06:34:22 by abastida          #+#    #+#             */
/*   Updated: 2024/02/04 12:39:39 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **take_path(t_master *path)
{
	char **split;

	int i = 0;

	split = ft_split(get_path(path), ':');
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
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
