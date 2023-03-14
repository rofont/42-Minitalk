# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 11:36:23 by rofontai          #+#    #+#              #
#    Updated: 2023/03/14 13:08:34 by rofontai         ###   ########.fr        #
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
NAME = libftprintf.a

SRC = ft_printf.c 		\
		ft_printbase.c 	\
		ft_printchar.c	\
		ft_printstr.c	\
		ft_arg_value.c	\
		ft_printptr.c	\

OBJ_DIR	= ./obj
OBJS	= ${SRC:%.c=${OBJ_DIR}/%.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

#VARIABLE----------------------------------------------------------------------
all: creat ${NAME}
	@echo "$GFT_PRINTF DONE$W"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@ar -rcs  ${NAME} ${OBJS}

creat:
	@mkdir -p ${OBJ_DIR}

clean:
	@rm -f ${OBJS}
	@rm -rf ${OBJ_DIR}
	@echo "$RFT_PRINTF CLEAN$W"

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re creat