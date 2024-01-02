# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 14:34:45 by muel-bak          #+#    #+#              #
#    Updated: 2024/01/02 08:27:19 by muel-bak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_FILES = ./helping_functions/ft_atoi.c  ./helping_functions/ft_join_args.c ./helping_functions/ft_split.c \
			./input/input_error.c ./input/input.c		\
			./OP/push.c ./OP/reverse_rotate.c ./OP/rotate.c ./OP/swap.c			\
			./stack/creation.c ./stack/push_and_pop.c ./stack/stack_tools.c	./stack/indixing.c	\
			./sorting/sorting_tools.c ./sorting/sorting_algorithm.c	./sorting/sort_small.c ./sorting/utile.c \
			./bonus/_excute_bonus.c ./bonus/_read_and_check_bonus.c \
			./bonus/push_bonus.c ./bonus/swap_bonus.c ./bonus/rotate_bonus.c ./bonus/reverse_rotate_bonus.c \
			./git_next_line/get_next_line.c ./git_next_line/get_next_line_utils.c \

MAIN = ./push_swap_main.c
OBJ_FILES = $(SRC_FILES:.c=.o) $(MAIN:.c=.o)
HEADER_FILE = ./header_file/push_swap.h

BONUS_MAIN = main_bonus.c
OBJ_BONUS = $(SRC_FILES:.c=.o) $(BONUS_MAIN:.c=.o)

#------------------------------------

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER_FILE)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILE)
	@$(CC) $(CFLAGS) -c $< -o $@

#------------------------------------

BONUS_NAME = checker

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(HEADER_FILE)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_BONUS)

#------------------------------------
clean:
	@rm -f $(OBJ_FILES) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
