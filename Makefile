# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 21:18:02 by phemsi-a          #+#    #+#              #
#    Updated: 2021/05/24 22:03:21 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a

LIBFT_PATH = ./libraries/libft/

SRC = ./source/
#PARSE = $(SRC)parse_scene/
#RENDER = $(SRC)render_cub/
#SYSTEM = $(SRC)system/

FILES = $(SRC)push_swap.c
OBJECTS = push_swap.o

CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -lft

$(LIBFT):
	make -C $(LIBFT_PATH) $(LIBFT)

$(OBJECTS): $(FILES)
	$(CC) $(CFLAGS) -g -c $(FILES)

clean:
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	
re: fclean all 

.PHONY: all clean fclean re 
