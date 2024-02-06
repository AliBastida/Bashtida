/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:18:18 by pabastid          #+#    #+#             */
/*   Updated: 2024/02/06 13:47:34 by pabastid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_pwd(void)
{
	char *cwd;
	int i;

	cwd = getcwd(NULL, 0); //(getcwd(pwd, sizeof(pwd))) -> habria que crear char pwd[1024]
	i = 0;
	if (cwd != NULL) // si exite cwd lo printeas. Si no, llamamos a perror aqui??? o la usamos en execve.c
	{
		while (cwd[i])
			printf("%s\n", cwd);
		free(cwd);
		/*
		if (la flag activada en builtin_cd esta ok == 1)
		{
			write(1, "/", 1);
			reseteas la flag = 0;
		}
		*/
		printf("\n");
	}
	/*else
	{
		perror("getcwd() error");
		return (1);
	}*/
	return (0);
}
