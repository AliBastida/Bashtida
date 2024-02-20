/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:30:51 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/15 17:46:59 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_cd(t_master *master, char *dir)
{
	if (dir == NULL)
	{
		if (!ft_strcmp(ft_getenv("HOME", master->env, -1), ""))
		{
			printf("bash: cd: HOME not set\n");
			return (1);
		}
		chdir(ft_getenv("HOME", master->env, -1));
	}
	else if (!ft_strncmp(dir, "-", 2))
	{
		if (!ft_strcmp(ft_getenv("OLDPWD", master->env, -1), ""))
		{
			printf("bash: cd: OLDPWD not set\n");
			return (1);
		}
		chdir(ft_getenv("OLDPWD", master->env, -1));
	}
	else if (chdir(dir) == -1)
		return (4);
	return (0);
}
