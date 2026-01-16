# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 21:53:05 by antoinebuet       #+#    #+#              #
#    Updated: 2026/01/16 21:55:27 by antoinebuet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -g
cc 	= cc

################################################################################
## SOURCES

HEADER = push_swap.h

OPTION = -c -I $(HEADER)

SRC_FILES = main.c p.c reverse.c rotate.c swap.c\

OBJ_FILES =  $(SRC_FILES:.c=.o)

################################################################################
## RULES

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(OPTION) $(SRC_FILES)
	@ar rc $(NAME) $(OBJ_FILES)
	

clean: 
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

launch : all 
	@$(CC) $(NAME)
	@./a.out
	@make fclean
.PHONY: all clean fclean launch re