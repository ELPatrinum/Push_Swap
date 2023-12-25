# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 14:34:45 by muel-bak          #+#    #+#              #
#    Updated: 2023/12/25 12:11:14 by muel-bak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_FILES = ./helping_functions/ft_atoi.c  ./helping_functions/ft_join_args.c ./helping_functions/ft_split.c \
			./input/input_error.c ./input/input.c		\
			./OP/push.c ./OP/reverse_rotate.c ./OP/rotate.c ./OP/swap.c			\
			./stack/creation.c ./stack/push_and_pop.c ./stack/stack_tools.c	./stack/indixing.c	\
			./sorting/sorting_tools.c ./sorting/sorting_algorithm.c	\
			./push_swap_main.c		\


OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER_FILE = ./header_file/push_swap.h

NAME = push_swap
all: $(NAME)

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
