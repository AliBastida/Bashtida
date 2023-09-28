/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2023/09/22 15:08:41 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
no hace falta hacer calloc. es una estructura estatica.

*/
int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    (void) env;

	t_master *master;
	master = ft_calloc(1, sizeof(t_master));
	while (1)
	{
		read_line(master);
		if (paired_quotes(master) == 1)
		{
			ft_split(master->line); // printf("%d\n", what_type_ofquotes(master));
			printf("%s\n", clean_line(master));
		}
		else
			printf("Not paired quotes\n");
		// TODO: revisar esto: free(master->clean_line);
		// TODO: chequear este ejemplo: gngn '' "" ; no trabaja bien el clean line
	}
	free(master);
	return (0);
}
