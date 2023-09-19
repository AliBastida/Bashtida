/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2023/09/18 15:34:11 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
Hacemos calloc porque sino, nos daba segfault, al guardar la linea leida en la estructura.

*/
int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    (void) env;
    
    t_master *master;
    master = ft_calloc(1, sizeof(t_master));
    if (!master)
        return (1);
    while (1)
    {
        read_line(master);
      //  printf("%d\n", paired_quotes(master));
        printf("%s\n", clean_line(master));
    }
    free(master);
}