/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:32:26 by abastida          #+#    #+#             */
/*   Updated: 2023/10/16 11:05:06 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void checking_syntax(char *str, t_master *master)
{
    if (paired_quotes(str) == 1)
        {
            if (check_syntax_pipes(str) == 1)
            {
                if (redir(str) == 1)
                //printf("Lo habeeis hecho bien\n");
                    printf("%s\n", clean_line(str, master));
            }
        }
        else
            printf("syntax error :<\n");
}