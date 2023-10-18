/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:32:26 by abastida          #+#    #+#             */
/*   Updated: 2023/10/17 10:33:40 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int syntax_error(int n)
{
    if (n == 0)
        ft_putstr_fd("Syntax Error\n", 2);
    else if (n == 1)
        ft_putstr_fd("Error\n", 2);
    else if (n == 3)
        ft_putstr_fd("Syntax Error\n", 2);

    return (n);
}

int checking_syntax(char *str, t_master *master)
{
    if (paired_quotes(str) == 1)
    {
        if (check_syntax_pipes(str) == 1)
        {
            if (redir(str) == 1)
            {
                printf("%s\n", clean_line(str, master));
                return (0);
            }
        }
    }
    return (syntax_error(3));
}