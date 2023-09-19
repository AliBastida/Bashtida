/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:13:11 by abastida          #+#    #+#             */
/*   Updated: 2023/09/18 15:35:26 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void *read_line(t_master *master)
{
    master->line = readline(BBLU "Bashtida: "RESET);
    
    if(!master->line)
    {
        printf("Exit\n");
        free(master);
        exit(1);
    }
    printf("%s\n", master->line);
    free (master);
    return (0);
}

