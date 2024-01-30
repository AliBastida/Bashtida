/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastida <abastida@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:47:58 by abastida          #+#    #+#             */
/*   Updated: 2024/01/30 12:53:05 by abastida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

enum e_token_type
{
	WORD,
	REDIR_A,
	REDIR_B,
	REDIR_C,
	REDIR_D,
	DOLLAR,
};

enum e_error_type
{
	OPEN_FAILED,
	COMMAND_NOT_FOUND,
	COMMAND_FOUND_NOT_EX,
	FILE_NOT_FOUND,
	FILE_NOT_READ,
	FILE_NOT_WRITE,
};

const static char *g_error_array[] = {
	"OPEN ERROR\n",
	"COMMAND NOT FOUND\n",
	"PERMISSION DENIED\n",
	"NO SUCH FILE OR DIRECTORY\n",
	"FILE NOT READABLE\n",
	"FILE NOT WRITEABLE\n",
};

typedef struct s_cmd
{
	int ok;
	int in_fd;
	int out_fd;
	char *cmd;
	char **args;
	struct s_cmd *next;
} t_cmd;

typedef struct s_word
{
	char *word;
	int single_quotes;
	int type;
	int flag_quote;
	struct s_word *next;
} t_word;

typedef struct s_token
{
	char *content_token;
	char **word_node;
	t_word *words;
	struct s_token *next;
} t_token;

typedef struct s_master
{
	char *line;
    char *clean_line;
	int n_pipes;
	t_cmd *cmds;
	t_token *node;
	t_list *env;
}t_master;

#endif
