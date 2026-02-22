# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 21:53:05 by antoinebuet       #+#    #+#              #
#    Updated: 2026/02/22 13:34:57 by antoinebuet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -g -arch x86_64
CC 	= cc
ARGS ?= 49 17 29 52 37 64 66 86 73 100 88 96 14 33 30 89 24 76 10 72 19 18 1 61 15 54 87 23 36 70 82 77 39 28 57 56 78 13 99 83 50 81 53 26 71 20 92 6 43 94 80 35 74 62 8 21 45 7 34 31 11 38 25 47 4 40 91 98 44 90 69 42 51 16 85 48 93 65 84 79 97 95 46 3 68 75 12 63 60 27 59 41 55 9 5 32 22 67 2 58
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