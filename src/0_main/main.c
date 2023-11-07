/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2023/11/07 15:05:23 by abastida         ###   ########.fr       */
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
        checking_syntax(master->line, master);
        line_divided_in_tokens(master->line);
        free(master->line);
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
        if (read_line(master))
            continue ;
       // line_divided_in_tokens(master->line);
        create_node(master->line, master);
        free(master->line);
        // return (0);
       // printf ("resultado de check_dolar: %d\n", check_dollar(master));
    }
    free (master);
    return (0);
}