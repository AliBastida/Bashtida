/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:00 by abastida          #+#    #+#             */
/*   Updated: 2023/11/27 15:14:01 by abastida         ###   ########.fr       */
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
        if(checking_syntax(master->line) == 1)   //TODO check syntax nodos, concretamente este ejemplo:   >|
        {
            line_divided_in_tokens(master->line);
            if (!create_nodeandlist(master->line))
                free(master->line);
            else
                divided_by_word(master->node);
                //running_through_nodes(create_nodeandlist(master->line));
        }
        free(master->line);
    }
    free (master);
    return (0);
}
//TODO meter Gitignore
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
        if (read_line(master))
            continue ;
       // line_divided_in_tokens(master->line);
    //    printf("valor de strchar: %d\n", ft_strchar(master->line, '|'));
        line_divided_in_tokens(master->line);
        create_node(master->line, master);
        free(master->line);
        // return (0);
       // printf ("resultado de check_dolar: %d\n", check_dollar(master));
    }
    free (master);
    return (0);
}*/