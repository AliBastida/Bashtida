/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:11:56 by abastida          #+#    #+#             */
/*   Updated: 2023/09/18 15:24:38 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libftprintf/libft.h"
# include "colors.h"
# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
//# include <readline/history.h>
# include <stdbool.h>




//===== MAIN =====//
int main(int ac, char **av, char **env);

//===== READ_LINE =====//
void *read_line(t_master *master);

//===== QUOTES =====//
bool paired_quotes(t_master *master);
char *clean_line(t_master *master);

#endif
