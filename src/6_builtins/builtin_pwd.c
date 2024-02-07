/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:18:18 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/07 10:50:38 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_pwd(void)
{
	char cwd[1024];
	// es por esto lo de los parametros--> If buf is NULL, space is allocated as necessary to store the pathname and size is ignored.  This space may later be free(3)'d.

	if (getcwd(cwd, sizeof(cwd)) != NULL) //(getcwd(pwd, sizeof(pwd))) -> habria que crear char pwd[1024]--> getcwd aloca memoria y al darle estos valores lo hace automaticamente.
	// if (cwd != NULL)		// si exite cwd lo printeas. Si no, llamamos a perror aqui??? o la usamos en execve.c
	{
		printf("%s\n", cwd);
		// free(cwd);
		/*
		if (la flag activada en builtin_cd esta ok == 1)
		{
			write(1, "/", 1);
			reseteas la flag = 0;
		}
		*/
	}
	else // es buena idea imprimir error en cada funcion y que retorne 1 o 0 si da error o no.
	{
		perror("getcwd() error");
		return (1);
	}
	return (0);
}
