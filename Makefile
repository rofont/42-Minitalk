# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:49:17 by rofontai          #+#    #+#              #
#    Updated: 2023/03/23 21:37:57 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BANNER-----------------------------------------------------------------------

define BANNER

   _____   __        __  __          __   __
  /     \ |__| ____ |__|/  |______  |  | |  | __
 /  \ /  \|  |/    \|  \   __\__  \ |  | |  |/ /
/    Y    \  |   |  \  ||  |  / __ \|  |_|    /__
\____|____/__|___|__/__||__| (______/____/__|___/

endef
export

# COLORS-----------------------------------------------------------------------

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
W = $(shell tput -Txterm setaf 7)
C = $(shell tput -Txterm setaf 6)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

# VARIABLES--------------------------------------------------------------------

NAME	=
SERVER	= server
CLIENT	= client

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

OBJ_SRC	= ./src
SRC_S	= server.c
SRC_C	= client.c

OBJ_DIR	= ./obj
OBJ_S	= $(SRC_S:%.c=$(OBJ_DIR)/%.o)
OBJ_C	= $(SRC_S:.c=.o)



# ARGUMENTS--------------------------------------------------------------------

$(OBJ_DIR)/%.o : $(OBJ_SRC)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

all : creat $(SERVER)
	@echo $G"$$BANNER"$W

$(SERVER) : $(OBJ_S)
	$(CC) $(CFLAGS) -o $@ $^


creat :
	mkdir -p $(OBJ_DIR)

clean :
	rm -rf $(OBJ_S) $(OBJ_DIR)

fclean : clean
	rm -f $(SERVER)

re : fclean all
.PHONY: all clean creat fclean re