# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:49:17 by rofontai          #+#    #+#              #
#    Updated: 2023/03/16 15:31:26 by rofontai         ###   ########.fr        #
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

#VARIABLE------------------------------------------------------------------------
all: creat ${NAME} ${NAME_C}
	@echo "$GMINITALK DONE$W"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

serv: creat ${NAME}

people: creat ${NAME_C}

${NAME}: ${OBJ}
	@${CC}  -o ${NAME} ${OBJ}
${NAME_C}: ${OBJ_C}
	@ar -rcs  ${NAME_C} ${OBJ_C}

creat:
	@mkdir -p ${OBJ_DIR}

clean:
	@rm -f ${OBJ} ${OBJ_C}
	@rm -rf ${OBJ_DIR}
	@echo "$RMINITALK CLEAN$W"

fclean: clean
	@rm -f ${NAME} ${NAME_C}

re: fclean all

.PHONY: all clean fclean re creat