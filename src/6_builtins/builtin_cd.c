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

int	builtin_cd(char *dir)
{
	if (dir == NULL)
		chdir(ft_getenv("HOME", NULL, 0));
	else if (!ft_strncmp(dir, "-", 2))
		chdir(ft_getenv("OLDPWD", NULL, 0));
	else if (chdir(dir) == -1)
		return (4);
	return (0);
}
