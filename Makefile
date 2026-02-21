# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 21:53:05 by antoinebuet       #+#    #+#              #
#    Updated: 2026/02/21 19:32:57 by antoinebuet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -g
CC 	= cc
ARGS ?= 10 87 38 21 43 72
################################################################################
## SOURCES

HEADER = push_swap.h

OPTION = -c -I $(HEADER)

SRC_FILES = main.c push.c reverse.c rotate.c swap.c ft_atoi.c ft_split.c ft_strlcpy.c ft_init.c check_move.c sorting.c number_move.c\

OBJ_FILES =  $(SRC_FILES:.c=.o)

################################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean: 
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

launch : all 
	@./$(NAME) $(ARGS)
	@make fclean
.PHONY: all clean fclean launch re