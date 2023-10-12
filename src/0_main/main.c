/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2023/10/12 14:56:08 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int main(int ac, char **av, char **env)
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
        {
            if (check_syntax_pipes(master->line))
            {
                printf("Lo habeeis hecho bien\n");
                printf("%s\n", clean_line(master));
            }
        }
        else
            printf("Not paired quotes\n");
    }
    free (master);
    return (0);
}*/

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    
    t_master    *master;
    master = ft_calloc(1, sizeof(t_master));
    if (!master)
        return (0);
    while (1)
    {
        read_line(master);
        printf("el valor de return es: %d\n", check_redir_1(master->line));
    }
    free (master);
    return (0);
}

