/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:11:56 by abastida          #+#    #+#             */
/*   Updated: 2023/10/23 09:27:39 by abastida         ###   ########.fr       */
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
# include <readline/history.h>
# include <stdbool.h>

//===== MAIN =====//
//int main(int ac, char **av, char **env);
int main(int ac, char **av);

//******UTILS******//
int syntax_error(int n);

//===== READLINE =====//
void *read_line(t_master *master);

//===== CHECK_SYNTAX =====//
//******QUOTES_SYNTAX******//
bool paired_quotes(char *line);
char *clean_line(char *line, t_master *master);
char *memory_alloc(t_master *master);

//******PIPE_SYNTAX******//
bool something_before(char *str);
bool there_is_sth(char *str);
bool something_after(char *str);
bool check_syntax_pipes(char *str);

//******REDIR_SYNTAX******//
int check_redir_1(char *str);
int check_redir_2(char *str);
int redir(char *str);

//******UTILS_SYNTAX******//
void checking_syntax(char *str, t_master *master);
void checking_pipe_quoted(char *str);
int pipe_quoted(char *str, int i);
int next_quote(char *str, int i, char c);
void look_for_char(char *str);

#endif
