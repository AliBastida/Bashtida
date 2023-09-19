NAME := libftprintf.a

###########################
#COLORS:

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

SRC := /src/ft_atoi.c  /src/ft_bzero.c /src/ft_calloc.c /src/ft_hexa.c /src/ft_isalnum \
	/src/ft_isascii.c /src/ft_isdigit.c /src/ft_isprint.c /src/ft_itoa.c /src/ft_lstadd_back_bonus.c \
	/src/ft_lstadd_front_bonus.c /src/ft_lstclear_bonus.c /src/ft_lstdelone_bonus.c \
	/src/ft_lstiter_bonus.c /src/ft_lstlast_bonus.c /src/ft_lstmap_bonus.c /src/ft_lstnew_bonus.c \
	/src/ft_lstnew_bonus.c /src/ft_lstsize_bonus.c /src/ft_memchr.c /src/ft_memcmp.c /src/ft_memcpy.c \
	/src/ft_memmove.c /src/ft_memset.c /src/ft_printf.c /src/ft_putchar_fd.c /src/ft_putendl_fd.c \
	/src/ft_putnbr_fd.c /src/ft_putstr_fd.c /src/ft_split.c /src/ft_src.c /src/ft_strchr.c \
	/src/ft_strdup.c /src/ft_striteri.c /src/ft_strjoin.c /src/ft_strlcat.c /src/ft_strlcpy.c \
	/src/ft_strlen.c /src/ft_strmapi.c /src/ft_strncmp.c /src/ft_strnstr.c /src/ft_strrchr.c \
	/src/ft_strtrim.c /src/ft_substr.c /src/ft_tolower.c /src/ft_toupper.c

.OBJ := $(addprefix .,$(addsuffix .o,$(notdir $(basename $(SRC)))))
.DEP := $(addprefix .,$(addsuffix .d, $(basename $(SRC))))
INCLUDE := libft.h
MKDIR := mkdir -p
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
RM := rm -fr
AR := ar rcs

.%.o : src/%.c
	@$(CC) $(CFLAGS)  -c $< -o $@

all : $(NAME)

$(NAME) : $(.OBJ)
	@$(AR) $(NAME) $(.OBJ)
	@ranlib $(NAME)

clean :
	@$(RM) $(.OBJ) $(.DEP)
	@echo "$(COLOR_CYAN)$(COLOR_BOLD)=== 🗑️  Objects and Dependencies from libft are being removed 🗑️  ===$(COLOR_RESET)"

fclean :
	@$(MAKE) clean
	@$(RM) $(NAME)

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
