# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 11:24:34 by abastida          #+#    #+#              #
#    Updated: 2024/02/16 13:51:21 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################

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

###########################

NAME := libftprintf.a

SRC := src/ft_atoi.c src/ft_atol.c src/ft_bzero.c src/ft_calloc.c src/ft_hexa.c src/ft_isalnum \
	src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_itoa.c src/ft_lstadd_back_bonus.c \
	src/ft_lstadd_front_bonus.c src/ft_lstclear_bonus.c src/ft_lstdelone_bonus.c \
	src/ft_lstiter_bonus.c src/ft_lstlast_bonus.c src/ft_lstmap_bonus.c src/ft_lstnew_bonus.c \
	src/ft_lstnew_bonus.c src/ft_lstsize_bonus.c src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c \
	src/ft_memmove.c src/ft_memset.c src/ft_printf.c src/ft_putchar_fd.c src/ft_putendl_fd.c \
	src/ft_putnbr_fd.c src/ft_putstr_fd.c src/ft_split.c src/ft_src.c src/ft_strchr.c \
	src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c src/ft_strlcat.c src/ft_strlcpy.c \
	src/ft_strlen.c src/ft_strmapi.c src/ft_strncmp.c src/ft_strnstr.c src/ft_strrchr.c \
	src/ft_strtrim.c src/ft_substr.c src/ft_tolower.c src/ft_toupper.c src/ft_strcmp.c \
	src/ft_free_double.c

SRC_DIR := src/
BUILD_DIR := .build/

HEADER := .
INCLUDE := $(addprefix -I , $(HEADER))
OBJ := $(addprefix $(BUILD_DIR), $(addsuffix .o, $(notdir $(basename $(SRC)))))
DEP := $(addprefix $(BUILD_DIR), $(addsuffix .d, $(notdir $(basename $(SRC)))))

CC := gcc
AR := ar rcs
RM := rm -rf
MKDIR := mkdir -p
CFLAGS := -Wall -Werror -Wextra -MMD

$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(COLOR_GREEN)$(COLOR_BOLD)=== 🤩 Libft compiled 🤩 === $(COLOR_RESET)"

clean :
	@$(RM) $(BUILD_DIR)
	@echo "$(COLOR_CYAN)$(COLOR_BOLD)=== 🗑️  Objects and Dependencies from libft are being removed 🗑️  ===$(COLOR_RESET)"

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
