# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romain <romain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:49:17 by rofontai          #+#    #+#              #
#    Updated: 2023/04/12 21:30:09 by romain           ###   ########.fr        #
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

NAME	= minitalk
SERVER	= server
CLIENT	= client

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

DIR_SRC	= ./src
SRC_S	= server.c utils.c
SRC_C	= client.c utils.c

DIR_OBJ	= ./obj
OBJ_S	= $(addprefix $(DIR_OBJ)/, $(SRC_S:.c=.o))
OBJ_C	= $(addprefix $(DIR_OBJ)/, $(SRC_C:.c=.o))

INC		= -I include

DIR_LIBFT	= ./libft
LIBFT	= $(DIR_LIBFT)/libft.a

DIR_PRINTF	= ./ft_printf
PRINTF	= $(DIR_PRINTF)/libftprintf.a

# ARGUMENTS--------------------------------------------------------------------

all	:	$(CLIENT) $(SERVER)
	@echo $G"$$BANNER"$W
	@echo "\n#-----$C MINITALK ready$W ✅---------------#\n"

$(DIR_OBJ)/%.o	:	$(DIR_SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$G Compilation : $Z $(notdir $<)"$W

$(SERVER)	:	$(LIBFT) $(PRINTF) $(OBJ_S)
	@$(CC) $(OBJ_S) -o $@ $(PRINTF) $(LIBFT)

$(CLIENT)	:	$(DIR_OBJ) $(LIBFT) $(PRINTF) $(OBJ_C)
	@$(CC) $(OBJ_C) -o $@ $(PRINTF) $(LIBFT) -fsanitize=address


$(DIR_OBJ) :
	@mkdir -p $@

$(LIBFT) :
	@make -C $(DIR_LIBFT)

$(PRINTF) :
	@make -C $(DIR_PRINTF)

clean :
	@$(RM) $(DIR_OBJ)
	@make clean -C $(DIR_LIBFT)
	@make clean -C $(DIR_PRINTF)
	@echo "\n#-----$R MINITALK clean$W ❌---------------#\n"
fclean : clean
	@rm -f $(SERVER) $(CLIENT)
	@make fclean -C $(DIR_LIBFT)
	@make fclean -C $(DIR_PRINTF)
	@echo "\n#-----$R MINITALK all clean$W ❌-----------#\n"

re : fclean all

bonus : re

.PHONY: all clean creat fclean re bonus

# DIVERS-----------------------------------------------------------------------