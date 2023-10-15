/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2023/10/15 20:31:39 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
        checking_syntax(master->line);
    }
    free (master);
    return (0);
}

/*int main(int ac, char **av)
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
        printf("return de redir: %d\n", redir(master->line));
       // printf("el valor de return es: %d\n", check_redir_1(master->line));
       // printf("el valor de return es: %d\n", check_redir_2(master->line));
    }
    free (master);
    return (0);
}*/

