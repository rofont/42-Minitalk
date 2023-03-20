# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:49:17 by rofontai          #+#    #+#              #
#    Updated: 2023/03/20 08:26:50 by rofontai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS------------------------------------------------------------------------

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
W = $(shell tput -Txterm setaf 7)
C = $(shell tput -Txterm setaf 6)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

#ARGUMENTS---------------------------------------------------------------------
NAME    = libft.a

SRC     = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_putstr_fd.c ft_putchar_fd.c \
		ft_putnbr_fd.c ft_putendl_fd.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_free_tab.c ft_swap.c \

OBJ_DIR = ./obj
OBJS     = ${SRC:%.c=${OBJ_DIR}/%.o}
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

#VARIABLE------------------------------------------------------------------------
all: creat ${NAME}
	@echo "$GLIBFT DONE$W"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@ar -rcs  ${NAME} ${OBJS}

creat:
	@mkdir -p ${OBJ_DIR}

clean:
	@rm -f ${OBJS}
	@rm -rf ${OBJ_DIR}
	@echo "$RLIBFT CLEAN$W"

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re creat