# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 16:19:53 by ybohusev          #+#    #+#              #
#    Updated: 2018/04/20 16:19:54 by ybohusev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, get_lib

NAME = lem-in

C = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

LIB = ./libft/libft.a

SRC = 

SRC += lem-in.c
SRC += bfs.c
SRC += link_nodes.c
SRC += read_data.c
SRC += parse.c
SRC += validation.c
SRC += is_link.c
SRC += exeptions.c
SRC += del_data.c

all: get_lib $(NAME)

get_lib:
	@make -C $(LIBFT)

$(NAME):
	@$(C) $(FLAGS) -o $(NAME) $(SRC) $(LIB) -I $(LIBFT) 
clean:
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
