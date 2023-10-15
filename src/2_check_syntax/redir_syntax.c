/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:30:43 by abastida          #+#    #+#             */
/*   Updated: 2023/10/15 19:38:22 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int check_redir_1(char *str)
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
                //else
                //   return(2);
            }
            i++;//return(1);
        }
        //else
        //   return (0);
        i++;
    }
    return (0);
}*/
int check_redir_1(char *str)
{
    int i;

    i = 0;
    if (str[i] == ('>'))
    {
        if (str[i+1] == '<')
               return (syntax_error(3));    
        else if (str[i+1] == '>')
        {
            if (str[i+2] == '<' || str[i+2] == '>')
                return (syntax_error(3));
            //    else
            //       return(2);
        }
            //return(1);
    }
    return (0);
}

int check_redir_2(char *str)
{
    int i;

    i = 0;
    if (str[i] == ('<'))
    {
        if (str[i+1] == '>')
               return (syntax_error(3));    
        else if (str[i+1] == '<')
        {
            if (str[i+2] == '>' || str[i+2] == '<')
                return (syntax_error(3));
            //    else
            //       return(2);
        }
            //return(1);
    }
    return (0);
}

int redir(char *str)
{
    int i;
    
    i = 0;
    while (str[i]) //&& (*str == '>' || *str == '<'))
    {
        if (str[i] == '>' && check_redir_1(&str[i]) == 3)
            return (3);    
        else if (str[i] == '<' && check_redir_2(&str[i]) == 3)
            return(3);
        i++;    
    }
    return (1);
}

