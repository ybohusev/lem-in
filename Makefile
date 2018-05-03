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

FLAGS += -Wall -Wextra -Werror

LIBFT = ./libft/
LIB = ./libft/libft.a
DIR_SRC = srcs
DIR_OBJ = objectives
INC = ./includes

SRC = 

SRC += lem_in.c
SRC += bfs.c
SRC += link_nodes.c
SRC += read_data.c
SRC += parse.c
SRC += fill_nodes.c
SRC += validation.c
SRC += is_link.c
SRC += exeptions.c
SRC += exeptions2.c
SRC += exeptions3.c
SRC += del_data.c
SRC += is_valid_room.c
SRC += is_valid_link.c
SRC += get_path.c
SRC += display_path.c

SRCS = $(addprefix $(DIR_SRC)/,$(SRC))
OBJS = $(addprefix $(DIR_OBJ)/,$(SRC:.c=.o))

all: get_lib $(NAME)

get_lib:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	@$(C) $(FLAGS) -o $(NAME) $(OBJS) $(LIB) -I $(LIBFT) -I $(INC)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	@$(C) $(FLAGS) -c -I $(LIBFT) -I $(INC) -o $@ -c $<

clean:
	@rm -rf $(DIR_OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
