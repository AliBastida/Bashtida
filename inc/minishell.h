/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:11:56 by abastida          #+#    #+#             */
/*   Updated: 2023/10/11 16:05:27 by abastida         ###   ########.fr       */
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


//===== READLINE =====//
void *read_line(t_master *master);

//===== CHECK_SYNTAX =====//
bool paired_quotes(t_master *master);
char *clean_line(t_master *master);
int memory_alloc(t_master *master);
//******PIPE_SYNTAX******//
bool something_before(char *str);
bool there_is_sth(char *str);
bool something_after(char *str);
bool check_syntax_pipes(char *str);
#endif
