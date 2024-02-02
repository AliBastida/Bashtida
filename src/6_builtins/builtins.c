/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:46:52 by abastida          #+#    #+#             */
/*   Updated: 2024/02/02 13:12:23 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 5) == 0)
		ejecutas echo;
	else if (ft_strcmp(cmd, "pwd", 4) == 0)
		ejcuta pwd;
	else if (ft_strcmp(cmd, "cd", 3) == 0)
		ejecuta cd;
	else if (ft_strcmp(cmd, "export", 7) == 0)
		ejecuta export;
	else if (ft_strcmp(cmd, "unset", 6) == 0)
		ejecuta unset;
	else if (ft_strcmp(cmd, "env", 4) == 0)
		ejecuta env;
	else if (ft_strcmp(cmd, "exit", 5) == 0)
		ejecuta exit;
	else
		return (false);
	return (true);
}
