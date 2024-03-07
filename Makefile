# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 12:29:13 by anastruc          #+#    #+#              #
#    Updated: 2024/03/06 17:59:28 by anastruc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Werror -Wextra -g3
NAME    = push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC	= ft_split.c input_check.c input_check_utils.c \
main.c move_nodes.c push_swap.c set_nodes.c set_nodes_2.c \
push.c reverse_rotate.c rotate.c stack_init_utils.c stack_init.c \
swap.c pre_sort_b.c algo_utils.c set_nodes_utils.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ	= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
HEAD	= -I ./header/

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) -g3 $(CFLAGS) -c $< -o $@ $(HEAD)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
