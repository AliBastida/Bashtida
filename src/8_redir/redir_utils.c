/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:04:03 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 17:36:59 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *filename_path(char *name)
{
	char work_dir[256];
	char *filename;

	filename = NULL;
	getcwd(work_dir, sizeof(work_dir));
	filename = ft_strjoin(work_dir, "/");
	filename = ft_strjoin(filename, name);
	return (filename);
}

int ft_access(char *filename, int mod)
{
	if ((!mod && access(filename, R_OK) == 0) || (mod == 1 && access(filename, W_OK) == 0) || (mod == 2 && access(filename, X_OK) == 0))
		return (0);
	if ((!mod || mod == 1) && access(filename, F_OK) == 0)
	{
		if (!mod)
			return (FILE_NOT_READ);
		else
			return (FILE_NOT_WRITE);
	}
	else if (mod == 2)
	{
		if (access(filename, F_OK) == 0)
			return (COMMAND_FOUND_NOT_EX);
		return (COMMAND_NOT_FOUND);
	}
	return (FILE_NOT_FOUND);
}

void manage_redir(t_word *redir, t_cmd *cmd)
{
	if (redir->type == 1)
		redir_heredoc(redir, cmd);
	else if (redir->type == 2)
		append_mode(redir, cmd);
	else if (redir->type == 3)
		redir_input(redir, cmd);
	else
		redir_output(redir, cmd);
}

/*// el primer if lo que hace es chequear que mod es cero y si el archivo se puede leer,
o si el mod es 1(output)y se puede escribir,
	o si mod es 2 y es ejecutable(es cmd),
	retorna 0.
	// el resto de los if gestionar errores. El primer if de errores,
	si mod es 0 o 1 y el archivo existe,
	puede ser que no se pueda leer o que no se pueda escribir.
	// Si es un cmd (mod = 2) si el archivo existe puede que no sea ejecutable,
	si no,
	puede ser que no sea ejecutable.Y por ultimo,
		el ultimo error puede ser que el archivo no exista.
*/
