/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:13:11 by abastida          #+#    #+#             */
/*   Updated: 2023/11/08 16:06:49 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int read_line(t_master *master)
{
    int i;

    i = 0;
    master->line = readline(BBLU "Bashtida: "RESET);
    if (master->line[0] == ' ')
    {
        while (master->line[i] == ' ')
            i++;
   /*     if (master->line[i] == '\0')
        {
            free(master->line); // Para quitar el leak del readline
            return (0);
        }*/
    }
    else if (!ft_strncmp(master->line, "", 1))
    {
        //free(master->line); // Para quitar el leak del readline
        return (1);
    }
    else if(!master->line)
    {
        printf("Exit\n");
       // free(master);
        exit(1);
    }
    return (0);
}
