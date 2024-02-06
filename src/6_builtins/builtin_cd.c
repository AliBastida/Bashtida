/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:30:51 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/06 14:03:18 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_cd(char *dir)
{
	/* if (t_cmd->args[1] == 47) aqui recogemos el caso cd /
	y ponemos activamos una flag que habra que crear, que usaremos como caso especial en builtin_pwd */
	if (dir == NULL)
		chdir(ft_getenv("HOME", NULL, 0));
	else if (!ft_strncmp(dir, "-", 2))
		chdir(ft_getenv("OLDPWD", NULL, 0));
	else if (chdir(dir) == -1)
		return (4);
	return (0);
}

//no hace falta cd /
