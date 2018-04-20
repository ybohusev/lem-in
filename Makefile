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

LIBFT = ./libft

LIB = ./libft/libft.a

TMP = ./temporary

INCLUDES = -I ./libft

INCLUDES += -I ./libft

SRC = 

SRC += bfs.c
SRC += lem-in.c
SRC += link_nodes.c
SRC += read_data.c

OBJS = $(addprefix $(TMP)/,$(SRC:.c=.o))

all: get_lib $(NAME)

get_lib:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	@$(C) $(FLAGS) -o $(NAME) $(TMP) $(LIB) -I $(INCLUDES)

$(TMP)/%.o: $(SRC)
	@mkdir -p $(TMP)
	@$(C) $(FLAGS) -c -I $(INCLUDES) -o $@ -c $<


clean:
	@rm -rf $(TMP)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
