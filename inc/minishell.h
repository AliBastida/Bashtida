/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:11:56 by abastida          #+#    #+#             */
/*   Updated: 2023/11/07 14:58:50 by abastida         ###   ########.fr       */
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
int     main(int ac, char **av);

//******UTILS******//
int     syntax_error(int n);
void ft_free_single(char *str);

//===== READLINE =====//
int     read_line(t_master *master);

//===== CHECK_SYNTAX =====//
//******QUOTES_SYNTAX******//
bool    paired_quotes(char *line);
char    *clean_line(char *line, t_master *master);
char    *memory_alloc(t_master *master);

//******PIPE_SYNTAX******//
bool    something_before(char *str);
bool    there_is_sth(char *str);
bool    something_after(char *str);
bool    check_syntax_pipes(char *str);

//******REDIR_SYNTAX******//
int     check_redir_1(char *str);
int     check_redir_2(char *str);
int     redir(char *str);

//******UTILS_SYNTAX******//
void    checking_syntax(char *str, t_master *master);

//===== SPLIT_PER_PIPES =====//
//******GENERAL_SPLIT******//
char    *substr_token(char *str, int pipe, int i);
int     next_quote(char *str, int i, char c);
char    **line_divided_in_tokens(char *str);
int     how_many_pipes(char *str);

//******LIST_PER_PIPES******//
t_token *ft_newnode(void *content);
 void    *create_node(char *str, t_master *master);

//******LIST_UTILS******//
t_token	*lst_last(t_token **lst);
void	lst_add_back(t_token **first, t_token *new_el);
void	lstdelone(t_token *lst, void (*del)(void*));
void	lstclear(t_token **lst, void (*del)(void*));

//===== CHECK_NODES =====//
//******UTILS_NODES******//
int len_nodes(char *token);
int	ft_strcmp(char *s1, char *s2);
char *clean_word(char *str);

//******FOUND_DOLLAR******//


//bool check_dollar(t_master *line);

#endif
