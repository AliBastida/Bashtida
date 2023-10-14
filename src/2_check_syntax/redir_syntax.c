/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:30:43 by abastida          #+#    #+#             */
/*   Updated: 2023/10/12 15:18:07 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_redir_1(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ('>'))
        {
            if (str[i+1] == '<')
                return (syntax_error(3));    
            else if (str[i+1] == '>')
            {
                if (str[i+2] == '>' || str[i+2] == '<')
                   return (syntax_error(3));
                else
                    return(2);
            }
            return(1);
        }
        else
            return (0);
        i++;
    }
    return (0);
}

int check_redir_2(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ('<'))
        {
            if (str[i+1] == '>')
                return (syntax_error(3));    
            else if (str[i+1] == '<')
            {
                if (str[i+2] == '>' || str[i+2] == '<')
                   return (syntax_error(3));
                else
                    return(2);
            }
            return(1);
        }
        i++;
    }
    return (0);
}
TODO

char *redir(char *str)
{
    while (str[i])
    {
        if (str[i] == '>')
            check_redir_1;
        else if (str[i] == '<')
            check_redir_2;
    }
}