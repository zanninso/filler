# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 14:24:44 by aait-ihi          #+#    #+#              #
#    Updated: 2019/12/22 00:54:36 by aait-ihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler_visu

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC =	draw.c events.c main.c read_map.c

LIB_FT = libft/libft.a

MLX_PATH = /usr/local/

OBJ = $(SRC:%c=%o)

all : $(NAME)


$(LIB_FT) : lib

lib:
	make -C libft

$(NAME) :$(LIB_FT) $(OBJ)  filler_visu.h
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_FT) -lmlx  -L  $(MLX_PATH)lib/ -I $(MLX_PATH)include -framework OpenGL -framework AppKit

%.o : %.c filler_visu.h
	$(CC) $(CFLAGS) -I . -o $@ -c $<

clean :
	make clean -C libft
	/bin/rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	/bin/rm -rf $(NAME)

re : fclean all