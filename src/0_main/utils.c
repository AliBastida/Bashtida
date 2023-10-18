/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:31:30 by abastida          #+#    #+#             */
/*   Updated: 2023/10/16 11:43:06 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char *memory_alloc(t_master *master)
{
    int len; 

    len = ft_strlen(master->line);
    master->clean_line = ft_calloc(len+1, sizeof(t_master));
    if (!master->clean_line)
        return (NULL);
    else
        return (master->clean_line);
}
