# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabastid <pabastid@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 11:24:34 by abastida          #+#    #+#              #
#    Updated: 2023/09/22 14:36:18 by pabastid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
CC := gcc
CFLAGS := -Wall -Werror -Wextra
DFLAGS_MAIN	= -MMD -MP -MF $(DEP_DIR_MAIN)/$*.d
DFLAGS_PARS	= -MMD -MP -MF $(DEP_DIR_PARS)/$*.d

SRC_MAIN	:=	src/main/main.c src/main/utils.c
SRC_PARS	:=	src/parsing/read_line.c src/parsing/quotes.c src/parsing/split.c 
		
SRC_DIR := src
OBJ_DIR := .obj
DEP_DIR := .dep
SRC_DIR_MAIN := $(SRC_DIR)/main
OBJ_DIR_MAIN := $(OBJ_DIR)/main
DEP_DIR_MAIN := $(DEP_DIR)/main
SRC_DIR_PARS := $(SRC_DIR)/parsing
OBJ_DIR_PARS := $(OBJ_DIR)/parsing
DEP_DIR_PARS := $(DEP_DIR)/parsing

OBJ_MAIN	:=	$(patsubst $(SRC_DIR_MAIN)/%, $(OBJ_DIR_MAIN)/%, $(SRC_MAIN:.c=.o))
DEP_MAIN	:=	$(patsubst $(SRC_DIR_MAIN)/%, $(DEP_DIR_MAIN)/%, $(SRC_MAIN:.c=.d))
OBJ_PARS	:=	$(patsubst $(SRC_DIR_PARS)/%, $(OBJ_DIR_PARS)/%, $(SRC_PARS:.c=.o))
DEP_PARS	:=	$(patsubst $(SRC_DIR_PARS)/%, $(DEP_DIR_PARS)/%, $(SRC_PARS:.c=.d))

LIBS := libftprintf/libftprintf.a
LIBPATH := -L libftprintf -lftprintf
HEADER := inc/

INCLUDE := -I $(HEADER)
RM := rm -rf
MKDIR	:= mkdir -p

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

$(OBJ_DIR_MAIN)/%.o: $(SRC_DIR_MAIN)/%.c
	@$(CC) $(CFLAGS) $(DFLAGS_MAIN) $(INCLUDE) -c $< -o $@
	@echo "$(COLOR_YELLOW)$<\tcompiled!$(COLOR_RESET)"

$(OBJ_DIR_PARS)/%.o: $(SRC_DIR_PARS)/%.c
	@$(CC) $(CFLAGS) $(DFLAGS_PARS) $(INCLUDE) -c $< -o $@
	@echo "$(COLOR_YELLOW)$<\tcompiled!$(COLOR_RESET)"

all:
	@$(MKDIR) $(OBJ_DIR)
	@$(MKDIR) $(DEP_DIR)
	@$(MKDIR) $(OBJ_DIR_MAIN)
	@$(MKDIR) $(DEP_DIR_MAIN)
	@$(MKDIR) $(OBJ_DIR_PARS)
	@$(MKDIR) $(DEP_DIR_PARS)
	@$(MAKE) $(NAME)

$(LIBS):
	@$(MAKE) -C libftprintf

-include $(DEP_MAIN)
-include $(DEP_PARS)

$(NAME): $(LIBS) $(OBJ_MAIN) $(OBJ_PARS)
	@$(CC) $(CFLAGS) $(LIBPATH) $^ -o $(NAME) -lreadline
	@echo "$(COLOR_BOLD)$(COLOR_GREEN)=== 🤩 Minishell compiled 🤩 === $(COLOR_RESET)"

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(DEP_DIR)
	@$(MAKE) clean -C libftprintf
	@echo "$(COLOR_BOLD)$(COLOR_CYAN)=== 🗑️  Objects and Dependencies are being removed 🗑️  === $(COLOR_RESET)"

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libftprintf

re:
	@$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
