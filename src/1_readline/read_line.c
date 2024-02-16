/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:13:11 by abastida          #+#    #+#             */
/*   Updated: 2024/02/16 16:08:56 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int read_line(t_master *master)
{
	int i;

	i = 0;
	master->line = readline(BBLU "Bashtida: " RESET);
	if (!master->line)
	{
		write(2, "exit\n", 5);
		exit(1);
	}
	if (master->line[0] == ' ' || master->line[0] == '\t')
	{
		while (master->line[i] == ' ' || master->line[0] == '\t')
			i++;
		if (master->line[i] == '\0')
			exit_error("Malloc error\n");
	}
	else if (!ft_strncmp(master->line, "", 1))
	{
		free(master->line);
		return (1);
	}
	return (0);
}
