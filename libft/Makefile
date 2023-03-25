# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:49:17 by rofontai          #+#    #+#              #
#    Updated: 2023/03/24 21:17:50 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS-----------------------------------------------------------------------

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
W = $(shell tput -Txterm setaf 7)
C = $(shell tput -Txterm setaf 6)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

# VARIABLES--------------------------------------------------------------------

NAME = libft.a


SRCS_DIR	= ./src
SRCS        = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_putstr_fd.c ft_putchar_fd.c \
	ft_putnbr_fd.c ft_putendl_fd.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS_DIR    = ./obj
OBJS        = ${SRCS:%.c=${OBJS_DIR}/%.o}

CC   = gcc

CFLAGS = -Wall -Wextra -Werror

# RULES------------------------------------------------------------------------

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "$G Compilation : $Z $<"$W

all: creat ${NAME}
	@echo "\n#-----$CLIBFT already$W ✅-------------------#\n"

${NAME}: ${OBJS}
	@ar -rsc  ${NAME} ${OBJS}

creat:
	@mkdir -p ${OBJS_DIR}

clean:
	@rm -rf ${OBJS} ${OBJS_DIR}
	@echo "\n#-----$RLIBFT clean$W ❌-------------------#\n"

fclean: clean
	@rm -f ${NAME}
	@echo "\n#-----$RLIBFT full clean$W ❌--------------#\n"

re: fclean all

.PHONY: all clean fclean re creat