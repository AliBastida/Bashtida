/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:11:56 by abastida          #+#    #+#             */
/*   Updated: 2024/02/15 17:52:14 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>
#include "../libftprintf/libft.h"
#include "colors.h"
#include "history.h"
#include "readline.h"
#include "struct.h"

#define PRINT_LIST(list)                                                       \
	t_list *random_tmp = list;                                                 \
	printf("------------LIST----------\n");                                    \
	while (random_tmp != NULL)                                                 \
	{                                                                          \
		printf("random_tmp: *%p*---*%s*-\n", random_tmp, random_tmp->content); \
		random_tmp = random_tmp->next;                                         \
	}                                                                          \
	printf("----------------------\n");

#define PRINT_WORD(list)                                                \
	t_word *tmp = list;                                                 \
	printf("-----------WORDS-----------\n");                            \
	while (tmp != NULL)                                                 \
	{                                                                   \
		printf("tmp: *%s*\t%p\tType: %d\n", tmp->word, tmp, tmp->type); \
		tmp = tmp->next;                                                \
	}                                                                   \
	printf("----------------------\n");

#define PRINT_TOKENS(list)                                       \
	t_token *random_tmp = list;                                  \
	printf("----------------------\n");                          \
	while (random_tmp != NULL)                                   \
	{                                                            \
		printf("random_tmp: *%s*\n", random_tmp->content_token); \
		random_tmp = random_tmp->next;                           \
	}                                                            \
	printf("----------------------\n");

#define PRINT_ARRAY(cadena)                       \
	printf("------------ARRAY----------\n");      \
	int random_i = 0;                             \
	while (cadena[random_i] != NULL)              \
	{                                             \
		printf("cadena: %s\n", cadena[random_i]); \
		random_i++;                               \
	}                                             \
	printf("----------------------\n");

#define PRINT_CMD(list)                                                       \
	t_cmd *random_tmp = list;                                                 \
	printf("-----------CMD-----------\n");                                    \
	while (random_tmp != NULL)                                                \
	{                                                                         \
		printf("tmp_cmd: *%p\n", random_tmp);                                 \
		printf("n: *%i\n", random_tmp->n);                                    \
		printf("ok: *%i\n", random_tmp->ok);                                  \
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
		printf("\n");                                                         \
		random_tmp = random_tmp->next;                                        \
	}                                                                         \
	printf("----------------------\n");

//=====0_MAIN=====//
//******FREE******//
void free_cmds(t_cmd *cmds);
void free_tokens(t_token *tk);
void free_all(t_master *master, int mode);

//******MAIN******//
int main(int ac, char **av, const char **env);

//******UTILS******//
int next_quote(char *str, int i, char c);
int syntax_error(char *str, char c, int out);
bool is_space(unsigned char c);
void exit_error(char *str);
char **converting(t_list *env);

//===== 1_READLINE =====//
int read_line(t_master *master);

//===== 2_CHECK_SYNTAX =====//
//******PIPE_SYNTAX******//
bool check_syntax_pipes(char *str);

//******UTILS_SYNTAX******//
int checking_syntax(char *str);

//===== 3_SPLIT_PER_PIPES =====//
//******GENERAL_SPLIT******//
char **line_divided_in_tokens(char *str, int n_pipes);

//******LIST_PIPES******//
void create_token_list(t_master *master, char *str);

//******LIST_UTILS******//
void lst_add_back(t_token **first, t_token *new_el);
void lstclear(t_token **lst, void (*del)(void *));

//===== 4_CHECK_NODES =====//
//******CLEAN_LINE******//
void clean_line(char *line, t_word *node);

//******FOUND_DOLLAR******//
char *extract_dollar(t_word *node, t_list *env);

//******UTILS_ENV******//
char *clean_vble(char *str, int idx);
char *ft_getenv(const char *name, t_list *env, int idx);

//******UTILS_NODES******//
int is_redir(char *str, int i);
void categorizing_words(t_word *node);
void line_ready_to_use(t_token *token, t_master *master);
char *substr_words(t_token *tmp, int start, int i);

//===== 5_NODES =====//
//******SPLIT_WORDS******//
void create_word_list(t_master *master, t_token *token);

//===== 6_BUILTINS =====//
//******BUILTIN_CD******//
int builtin_cd(char *dir);

//******BUILTIN_ECHO******//
int builtin_echo(char **args);

//******BUILTIN_ENV******//
int print_env(t_list *env);

//******BUILTIN_EXIT******//
int builtin_exit(char **args);

//******BUILTIN_EXPORT******//
int builtin_export(t_master *master, char **args);

//******BUILTIN_EXPORT_UTILS******//
int len_until_equal(char *str);
int checking_format(char *str);
void join_var(t_list *aux, char *arg);
t_list *get_envnode_export(t_list *env, char *arg);

//******BUILTIN_PWD******//
int builtin_pwd(void);

//******BUILTIN_UNSET******//
int builtin_unset(t_list **env, char **args);

//******BUILTINS******//
int is_builtin(char *cmd);
int ft_len_dptr(char **arr);

//===== 7_COMMANDS =====//
//******CMD_LIST_UTILS******//
t_cmd *create_list_cmd(t_token *token, t_master *master);

//******CMD_UTILS******//
int n_args(t_word *words);
void lst_add_back_cmd(t_cmd *list, t_cmd *node);

//******CMD******//
void ft_take_cmd(t_cmd *new, t_master *master);

//===== 8_REDIR =====//
//******INPUT < ******//
void redir_input(t_word *redir, t_cmd *cmd);

//******OUTPUT > ******//
void redir_output(t_word *redir, t_cmd *cmd);

//******HEREDOC << ******//
void redir_heredoc(t_word *redir, t_cmd *cmd);

//******APPEND_MODE >> ******//
void append_mode(t_word *redir, t_cmd *cmd);

//******REDIR_UTILS******//
int ft_access(char *filename, int mod);
void manage_redir(t_word *redir, t_cmd *cmd);
char *filename_path(char *name);

//===== 9_EXECUTE =====//
//******EXECUTE_CMDS******//
int execute_cmds(t_master *master);
int run_builtin(t_master *master, t_cmd *tmp);
void take_exit_value(t_cmd *cmd);

//******EXECVE******//
int one_builtin(t_master *master, t_cmd *cmd, char **env);
int close_all_pipes(t_master *master, pid_t *pids, t_pipes pipes, char **env);
void close_here_doc(t_master *master);
pid_t one_cmd(t_master *master, t_cmd *tmp, t_pipes pipes, char **env);

//******PIPES******//
int check_ok(t_cmd **cmd);
int check_cmd_and_pipes(t_cmd **cmd, t_pipes *pipes);
void redirect_pipes(t_cmd *cmd, t_pipes pipes);

//******RUN_HEREDOC******//
void ft_take_heredoc(t_cmd *cmd);

//===== 10_SIGNALS =====//
//******SIGNALS******//
void set_signals(int mode);
void ign_signal(int signal);
void heredoc_handler(int sig);
void interact_handler(int sig);
void norm_handler(int sig);

#endif
