# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:49:17 by rofontai          #+#    #+#              #
#    Updated: 2023/03/20 08:38:12 by rofontai         ###   ########.fr        #
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

NAME 	= serveur
NAME_C	= client

SRC		= serveur.c
SRC_C	= client.c

OBJ_DIR	= ./obj
OBJ		= ${SRC:%.c=${OBJ_DIR}/%.o}
OBJ_C	= ${SRC_C:%.c=${OBJ_DIR}/%.o}
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

DIR_LIBFT	= ./libft
LIBFT		=libft.a

DIR_PRINTF	= ./ft_printf
PRINTF		= libftprintf.a

#VARIABLE------------------------------------------------------------------------
all: creat  ${NAME} ${NAME_C}
	@echo "$GMINITALK DONE$W"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

serv: creat ${NAME}

people: creat ${NAME_C}

${NAME}: ${DIR_LIBFT}/${LIBFT} ${DIR_PRINTF}/${PRINTF} ${OBJ} ${SRC}
	@echo $GSERVEUR DONE$W
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${DIR_LIBFT}/${LIBFT} ${DIR_PRINTF}/${PRINTF}

${NAME_C}: ${DIR_LIBFT}/${LIBFT} ${DIR_PRINTF}/${PRINTF} ${OBJ_C} ${SRC_C}
	@echo $GCLIENT DONE$W
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME_C} ${DIR_LIBFT}/${LIBFT} ${DIR_PRINTF}/${PRINTF}

${DIR_LIBFT}/${LIBFT}:
	@make -C ${DIR_LIBFT}

${DIR_PRINTF}/${PRINTF}:
	@make -C ${DIR_PRINTF}

creat:
	@mkdir -p ${OBJ_DIR}

clean:
	@rm -f ${OBJ} ${OBJ_C}
	@rm -rf ${OBJ_DIR}
	@make clean -C ${DIR_LIBFT}
	@echo $RCLIENT CLEAN$W
	@echo $RSERVEUR CLEAN$W
	@make clean -C ${DIR_PRINTF}
	@echo "$RMINITALK CLEAN$W"

fclean: clean

	@rm -f ${NAME} ${NAME_C} ${DIR_PRINTF}/${PRINTF} ${DIR_LIBFT}/${LIBFT}

re: fclean all

.PHONY: all clean fclean re creat