/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:11:56 by abastida          #+#    #+#             */
/*   Updated: 2024/02/06 13:40:13 by pabastid         ###   ########.fr       */
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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PRINT_LIST(list)                                   \
	t_list *random_tmp = list;                             \
	printf("----------------------\n");                    \
	while (random_tmp != NULL)                             \
	{                                                      \
		printf("random_tmp: *%s*\n", random_tmp->content); \
		random_tmp = random_tmp->next;                     \
	}                                                      \
	printf("----------------------\n");

#define PRINT_WORD(list)                                                \
	t_word *random_tmp = list;                                          \
	printf("----------------------\n");                                 \
	while (random_tmp != NULL)                                          \
	{                                                                   \
		printf("random_tmp: *%s*\t%p\n", random_tmp->word, random_tmp); \
		random_tmp = random_tmp->next;                                  \
	}                                                                   \
	printf("----------------------\n");

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

#define PRINT_CMD(list)                                                       \
	t_cmd *random_tmp = list;                                                 \
	printf("----------------------\n");                                       \
	while (random_tmp != NULL)                                                \
	{                                                                         \
		printf("tmp_cmd: *%p\n", random_tmp);                                 \
		printf("cmd: *%s*\n", random_tmp->cmd);                               \
		printf("in fd: *%i*\n", random_tmp->in_fd);                           \
		printf("out fd: *%i*\n", random_tmp->out_fd);                         \
		int i = 0;                                                            \
		while (random_tmp->args[i])                                           \
		{                                                                     \
			printf("arg %d: *%s*\n", i, random_tmp->args[i]);                 \
			i++;                                                              \
		}                                                                     \
		printf("has heredoc: *%s*\n", random_tmp->hd != NULL ? "YES" : "NO"); \
		random_tmp = random_tmp->next;                                        \
	}                                                                         \
	printf("----------------------\n");

//=====0_MAIN =====//
int main(int ac, char **av, const char **env);
//int     main(int ac, char **av);

//******UTILS******//
int     syntax_error(int n);
void    ft_free_single(char *str);
bool    is_space(unsigned char c);
void    *free_all(t_master *line);
void ft_free_double(char **str);

//===== 1_READLINE =====//
int     read_line(t_master *master);

//===== 2_CHECK_SYNTAX =====//
//******PIPE_SYNTAX******//
bool    something_before(char *str);
bool    there_is_sth(char *str);
bool    something_after(char *str);
bool    check_syntax_pipes(char *str);

//******QUOTES_SYNTAX******//
bool paired_quotes(char *line);
char *clean_line(char *line, t_master *master);
char *memory_alloc(t_master *master);

//******REDIR_SYNTAX******//
int     check_redir_1(char *str);
int     check_redir_2(char *str);
int error_redir(char *str);
int     redir(char *str);

//******UTILS_SYNTAX******//
int    checking_syntax(char *str);

//===== 3_SPLIT_PER_PIPES =====//
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

//===== 4_CHECK_NODES =====//
//******FOUND_DOLLAR******//
void check_to_expand(t_word *node, t_list *env);
void check_dollar(t_token *token, t_list *env);
void ft_expand_dollar(t_word *node, t_list *env, int idx);

//******UTILS_NODES******//
int len_nodes(char *token);
void categorizing_words(t_word *node);
int is_redir(char *str, int i);
char *substr_words(t_token *tmp, int start, int i);

//******UTILS_ENV******//
void ft_dup_env(t_master *token, const char **env);
char *ft_getenv(const char *name, t_list *env, int idx);
char *clean_vble(char *str, int idx);

//===== 5_NODES =====//
//******SPLIT_WORDS******//
t_word *ft_newnode_word(void *content);
char *divided_by_word(t_token *node);
t_word *lst_last_word(t_word **lst);
void lst_add_back_word(t_word **first, t_word *new_node);
t_word *create_nodeandlist_word(t_master *master, t_token *token);
char *divide_if_redir(t_token *node);

//===== 6_BUILTINS =====//
//******BUILTINS_PWD******//
int builtin_pwd(void);

//******BUILTINS_CD******//
int builtin_cd(char *dir);

//******BUILTINS******//
int is_builtin(char *cmd);

//******ENV******//
void print_env(t_master *master);

//===== 7_COMMANDS =====//
//******CMD******//
t_cmd *saving_arg(t_master *master);
int node_counter(t_word *words);
char *get_path(t_master *master);
void ft_take_cmd(t_cmd *cmd, t_word *words, t_master *master);
char *checking_path(char **path, char *cmd, int *ok);

//******CMD_LIST_UTILS******//
int n_args(t_word *words);
t_cmd *create_node_cmd(t_word *words, t_master *master);
t_cmd *create_list_cmd(t_token *token, t_master *master);
void lst_add_back_cmd(t_cmd *list, t_cmd *node);
t_cmd *lst_last_cmd(t_cmd *list);

//******CMD_ERROR******//
//******CMD_UTILS******//
char *filename_path(char *name);
char **take_path(t_master *path);
int ft_access(char *filename, int mod);

//******EXECVE******//
int execute_cmds(t_master *master);
char **converting(t_list *env);
void ft_take_heredoc(t_cmd *cmd);

//===== 8_REDIR =====//
//******REDIR.C ******//
void manage_redir(t_word *redir, t_cmd *cmd);

//******INPUT < ******//
void redir_input(t_word *redir, t_cmd *cmd);

//******OUTPUT > ******//
void redir_output(t_word *redir, t_cmd *cmd);

//******HEREDOC << ******//
void redir_heredoc(t_word *redir, t_cmd *cmd);

//******APPEND_MODE >> ******//

#endif
