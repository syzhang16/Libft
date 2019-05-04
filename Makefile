# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 17:00:55 by syzhang           #+#    #+#              #
#    Updated: 2019/05/01 17:38:20 by syzhang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS =  -Wall -Werror -Wextra -I inc/
MAKE = make
RM = rm -f
RMRF = rm -rf

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRCS = \
		printf/ft_width.c \
		printf/ft_unicode.c \
		printf/ft_strset.c \
		printf/ft_str_lower.c \
		printf/ft_s_cap.c \
		printf/ft_printf.c \
		printf/ft_print_argument.c \
		printf/ft_prefix.c \
		printf/ft_precision.c \
		printf/ft_parsing.c \
		printf/ft_max.c \
		printf/ft_itoa_b.c \
		printf/ft_isspace.c \
		printf/ft_isdigit.c \
		printf/ft_init_flags.c \
		printf/ft_get_flags.c \
		printf/ft_format_iul.c \
		printf/ft_format_csp.c \
		printf/ft_char_to_str.c \
		printf/ft_c_cap.c \
		printf/ft_abs.c \
		libft/ft_atoi.c	\
		libft/ft_isalpha.c \
		libft/ft_isprint.c \
		libft/ft_memcmp.c \
		libft/ft_memset.c \
		libft/ft_strcmp.c \
		libft/ft_strlcat.c \
		libft/ft_strncmp.c \
		libft/ft_strrchr.c \
		libft/ft_toupper.c \
		libft/ft_bzero.c \
		libft/ft_isascii.c \
		libft/ft_memccpy.c \
		libft/ft_memcpy.c \
		libft/ft_strcat.c \
		libft/ft_strcpy.c \
		libft/ft_strlen.c \
		libft/ft_strncpy.c \
		libft/ft_strstr.c \
		libft/ft_isalnum.c \
		libft/ft_memchr.c \
		libft/ft_memmove.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_strncat.c \
		libft/ft_strnstr.c \
		libft/ft_tolower.c \
		libft/ft_itoa.c \
		libft/ft_putchar.c \
		libft/ft_putendl_fd.c \
		libft/ft_putstr.c \
		libft/ft_strdel.c \
		libft/ft_striteri.c \
		libft/ft_strmapi.c \
		libft/ft_strsplit.c \
		libft/ft_memalloc.c \
		libft/ft_putchar_fd.c \
		libft/ft_putnbr.c \
		libft/ft_putstr_fd.c \
		libft/ft_strequ.c \
		libft/ft_strjoin.c \
		libft/ft_strnequ.c \
		libft/ft_strsub.c \
		libft/ft_memdel.c \
		libft/ft_putendl.c \
		libft/ft_putnbr_fd.c \
		libft/ft_strclr.c \
		libft/ft_striter.c \
		libft/ft_strmap.c \
		libft/ft_strnew.c \
		libft/ft_strtrim.c \
		libft/ft_lstnew.c \
		libft/ft_lstdelone.c \
		libft/ft_lstdel.c \
		libft/ft_lstadd.c \
		libft/ft_lstiter.c \
		libft/ft_lstmap.c \
		libft/ft_strindexchr.c \
	  	getnextline/get_next_line.c

HEADER = \
		 inc/ft_printf.h \
		 inc/libft.h \
		 inc/get_next_line.h

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJS_DIRS = $(sort $(dir $(OBJ)))

# PROGRESS BAR
T = $(words $(SRCS))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C '*' 100 / $T`%]"

#Color
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
		@mkdir $(OBJ_DIR) 2> /dev/null || true
		@mkdir $(OBJS_DIRS) 2> /dev/null || true
		@printf "%-60b\r" "$(ECHO) $(_GREEN) Compiling $@ $(_END)"
		@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RMRF) $(OBJ_DIR)
	@rmdir $(OBJS_DIRS) 2> /dev/null || true

fclean: clean
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all re clean fclean build
