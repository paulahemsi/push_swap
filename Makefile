# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 21:18:02 by phemsi-a          #+#    #+#              #
#    Updated: 2021/06/08 10:49:48 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a

LIBFT_PATH = ./libraries/libft/

SRC = ./source/

FILES = $(SRC)push_swap.c $(SRC)operations.c $(SRC)sort.c $(SRC)sort_aux.c $(SRC)quick_sort.c $(SRC)system.c $(SRC)choose_rotation.c $(SRC)init.c $(SRC)init_stack_a.c $(SRC)send_to_b.c $(SRC)return_to_a.c $(SRC)reduce_instructions.c
OBJECTS = push_swap.o operations.o sort.o sort_aux.o quick_sort.o system.o choose_rotation.o init.o init_stack_a.o send_to_b.o return_to_a.o reduce_instructions.o

CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -lft

$(LIBFT):
	make -C $(LIBFT_PATH) $(LIBFT)

$(OBJECTS): $(FILES)
	$(CC) $(CFLAGS) -g -c $(FILES)

objects_no_warnings : $(FILES)
	$(CC) -g -c $(FILES)

no_warnings: objects_no_warnings $(LIBFT)
	$(CC) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -lft

clean:
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	
re: fclean all 

.PHONY: all clean fclean re 
