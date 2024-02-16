# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 11:24:34 by abastida          #+#    #+#              #
#    Updated: 2024/02/15 17:57:46 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################

#COLORS

COLOR_RESET = \033[0m
COLOR_BOLD = \033[1m
COLOR_UNDERLINE = \033[4m
COLOR_RED = \033[31m
COLOR_GREEN = \033[32m
COLOR_YELLOW = \033[33m
COLOR_BLUE = \033[34m
COLOR_MAGENTA = \033[35m
COLOR_CYAN = \033[36m

###################

NAME := minishell

SRC :=  0_main/main.c 0_main/utils.c 0_main/free.c \
			1_readline/read_line.c\
			2_check_syntax/pipe_syntax.c 2_check_syntax/utils_syntax.c \
			3_split_per_pipes/general_split.c 3_split_per_pipes/list_pipes.c \
			3_split_per_pipes/list_utils.c 3_split_per_pipes/split_utils.c  \
			4_check_nodes/found_dollar.c 4_check_nodes/utils_envp.c 4_check_nodes/clean_line.c \
			5_nodes/split_words.c 5_nodes/utils_nodes.c \
			6_builtins/builtin_env.c 6_builtins/builtins.c 6_builtins/builtin_cd.c \
			6_builtins/builtin_pwd.c 6_builtins/builtin_unset.c  6_builtins/builtin_echo.c\
			6_builtins/builtin_export.c 6_builtins/builtin_export_utils.c 6_builtins/builtin_exit.c \
			7_commands/cmd.c 7_commands/cmd_list_utils.c 7_commands/cmd_utils.c \
			8_redir/redir_utils.c 8_redir/input.c 8_redir/output.c 8_redir/redir_heredoc.c 8_redir/redir_append_mode.c \
			9_execute/execve.c 9_execute/run_heredoc.c 9_execute/pipes.c \
			9_execute/execute_cmds.c \
			10_signals/signals.c

SRC_DIR := src/
BUILD_DIR := .build/

OBJ := $(addprefix $(BUILD_DIR), $(SRC:.c=.o))
DEP := $(addprefix $(BUILD_DIR), $(SRC:.c=.d))

CC := gcc
RM := rm -rf

LIBS := libftprintf/libftprintf.a
LIBPATH := -L libftprintf -lftprintf
LIBREAD := -L readline -lreadline -lncurses

HEADER := inc/ readline/
INCLUDE := $(addprefix -I , $(HEADER))

CFLAGS := -Wall -Werror -Wextra -g -MMD -DREADLINE_LIBRARY -fsanitize='address,undefined'

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(LIBS):
	@$(MAKE) -C libftprintf

$(NAME): $(LIBS) $(OBJ) Makefile
	@$(CC) $(CFLAGS) $(LIBPATH) $(LIBREAD) $(OBJ) -o $(NAME)
	@echo "$(COLOR_BOLD)$(COLOR_GREEN)=== 🤩 Minishell compiled 🤩 === $(COLOR_RESET)"

clean:
	@$(RM) $(BUILD_DIR)
	@echo "$(COLOR_BOLD)$(COLOR_CYAN)=== 🗑️  Objects and Dependencies from minishell are being removed 🗑️  === $(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libftprintf
#	@$(MAKE) clean

re: fclean all
# @$(MAKE) fclean
# $(MAKE) all

.PHONY: all clean fclean re

-include $(DEP)
