/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:11:56 by abastida          #+#    #+#             */
/*   Updated: 2023/09/22 15:10:58 by pabastid         ###   ########.fr       */
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
// # include <readline/history.h>
# include <stdbool.h>

#define METACHARACTERS " \n\t|<>&()" // `;' not implemented

//===== MAIN =====//
int main(int ac, char **av, char **env);


//===== READ_LINE =====//
void *read_line(t_master *master);
int is_word(t_master *master);

//===== SPLIT =====//
int is_space(t_master *master);
int count_words(t_master *master);
char *saved_word(t_master *master, int start, int end);
char **split_line(t_master *master);
int count_char(t_master *master);

//===== QUOTES =====//
bool paired_quotes(t_master *master);
char *clean_line(t_master *master);
int memory_alloc(t_master *master);
bool what_type_ofquotes(t_master *master);
#endif
