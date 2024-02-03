/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:01:59 by abastida          #+#    #+#             */
/*   Updated: 2024/01/31 12:43:41 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_env(t_master *master)
{
	while (master->env)
	{
		printf("===%s===\n", (char *)master->env->content);
		master->env = master->env->next;
	}
}
