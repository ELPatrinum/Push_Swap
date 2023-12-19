# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 14:34:45 by muel-bak          #+#    #+#              #
#    Updated: 2023/12/19 15:51:03 by muel-bak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = 

SRC_FILES = push_swap_main.c operations.c operations_.c operations__.c input_error.c ft_atoi.c \
			ft_split.c stack.c
OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER_FILE = push_swap.h

# BONUS_FILES = z_pipex_bonus.c z_utils_bonus.c z_utils1_bonus.c z_z_heredo.c\
# 	z_z_herdoc1.c z_z_herdoc2.c

# OBJ_BONUS = $(BONUS_FILES:.c=.o)
# BONUS_HEADER_FILE = z_pipex_bonus.h

NAME = push_swap
all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER_FILE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

# $(NAME_BONUS) : $(OBJ_BONUS) $(BONUS_HEADER_FILE)
# 	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

bonus: $(NAME_BONUS)

%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

# %.o: %.c $(BONUS_HEADER_FILE)
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
