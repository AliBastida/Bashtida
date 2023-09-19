/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2023/09/19 15:13:38 by abastida         ###   ########.fr       */
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
    
    t_master    *master;
    master = ft_calloc(1, sizeof(t_master));
    while (1)
    {
        read_line(master);
        if (paired_quotes(master) == 1)
            printf("%s\n", clean_line(master));
        else
            printf("Not paired quotes\n");
        //TO-DO: revisar esto: free(master->clean_line);
    }
    free (master);
    return (0);
}
