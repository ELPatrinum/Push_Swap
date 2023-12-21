# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 14:34:45 by muel-bak          #+#    #+#              #
#    Updated: 2023/12/21 16:31:46 by muel-bak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_FILES = ./helping_functions/ft_atoi.c  ./helping_functions/ft_join_args.c ./helping_functions/ft_split.c \
			./input/input_error.c ./input/input_error__.c		\
			./OP/push.c ./OP/reverse_rotate.c ./OP/rotate.c ./OP/swap.c			\
			./stack/creation.c ./stack/push_and_pop.c ./stack/stack_tools.c		\
			./sorting/sorting_tools.c ./sorting/sorting_algorithm.c	\
			./push_swap_main.c		\


OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER_FILE = ./header_file/push_swap.h

NAME = push_swap
all: $(NAME)
	@make clean
	@echo "Programe created succesfuly : push_swap"

$(NAME): $(OBJ_FILES) $(HEADER_FILE)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
