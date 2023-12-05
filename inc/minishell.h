/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:11:56 by abastida          #+#    #+#             */
/*   Updated: 2023/12/05 11:48:11 by pabastid         ###   ########.fr       */
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

#define PRINT_TOKENS(list) \
t_token *random_tmp = list; \
printf("----------------------\n"); \
while (random_tmp != NULL) { \
    printf("random_tmp: *%s*\n", random_tmp->content_token); \
    printf("len: %d\n", len_nodes(random_tmp->content_token)); \
    random_tmp = random_tmp->next; } printf("----------------------\n");

#define PRINT_ARRAY(cadena) \
printf("----------------------\n"); \
int random_i = 0; \
while (cadena[random_i] != NULL) { \
    printf("cadena: %s\n", cadena[random_i]); \
    random_i++; } printf("----------------------\n");




//===== MAIN =====//
int main(int ac, char **av, char **env);
//int     main(int ac, char **av);

//******UTILS******//
int     syntax_error(int n);
void    ft_free_single(char *str);
bool    is_space(unsigned char c);
void    *free_all(t_master *line);

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
int error_redir(char *str);
int     redir(char *str);

//******UTILS_SYNTAX******//
int    checking_syntax(char *str);

//===== SPLIT_PER_PIPES =====//
//******GENERAL_SPLIT******//
char    *substr_token(char *str, int pipe, int i);
int     next_quote(char *str, int i, char c);
char    **line_divided_in_tokens(char *str);
int     how_many_pipes(char *str);

//******LIST_PER_PIPES******//
t_token *ft_newnode(void *content);
t_token *create_nodeandlist(t_master *master, char *str);

//******LIST_UTILS******//
t_token	*lst_last(t_token **lst);
void	lst_add_back(t_token **first, t_token *new_el);
void	lstdelone(t_token *lst, void (*del)(void*));
void	lstclear(t_token **lst, void (*del)(void*));

//******SPLIT_UTILS******//
int	ft_strchar(char *s, int c);

//===== CHECK_NODES =====//
//******PARSING_NODEWORD******//
int parsing_quotes_nodeword(t_word *node);
void categorizing_words(t_word *node);

//******UTILS_NODES******//
int len_nodes(char *token);
int	ft_strcmp(char *s1, char *s2);
char *clean_word(char *str);

int ft_copy_line(char **dest, char *str);

//******FOUND_DOLLAR******//

//===== NODES =====//
//******SPLIT_WORDS******//
t_word *running_through_nodes(t_token *token);
t_word *ft_newnode_word(void *content);
char *divided_by_word(t_token *node);
t_word	*lst_last_word(t_word **lst);
void	lst_add_back_word(t_word **first, t_word *new_node);
t_word *create_nodeandlist_word(t_token *token);

//bool check_dollar(t_master *line);

#endif
