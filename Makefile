# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 14:24:44 by aait-ihi          #+#    #+#              #
#    Updated: 2019/12/29 00:09:42 by aait-ihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = aait-ihi.filler

VISU = filler_visu

EXECUTER = filler_executer

CFLAGS = -Wall -Werror -Wextra -g

CC = gcc

FILLER_SRCS = $(addprefix filler_src/,filler.c board.c piece.c find_best_pos.c free.c)

VISU_SRCS = $(addprefix visu_src/,draw.c events.c main.c read_map.c)

EXECUTER_SRCS = $(addprefix executer_src/,draw.c events.c main.c)

FILLER_OBJ = $(FILLER_SRCS:.c=.o)

VISU_OBJ = $(VISU_SRCS:.c=.o)

EXECUTER_OBJ = $(EXECUTER_SRCS:.c=.o)

LIBFT = libft/libft.a

MLX_PATH = /usr/local/

all : $(NAME) $(VISU) $(EXECUTER)

$(NAME) : $(FILLER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(FILLER_OBJ) $(LIBFT) -o $(NAME)

$(VISU) :$(LIBFT) $(VISU_OBJ)  visu_src/filler_visu.h
	$(CC) -o $(VISU) $(CFLAGS) $(VISU_OBJ)  $(LIBFT) -lmlx  -L  $(MLX_PATH)lib/ -I $(MLX_PATH)include -framework OpenGL -framework AppKit

$(EXECUTER) :$(LIBFT) $(EXECUTER_OBJ) executer_src/filler_executer.h
	$(CC) -o $(EXECUTER) $(CFLAGS) $(EXECUTER_OBJ)  $(LIBFT) -lmlx  -L  $(MLX_PATH)lib/ -I $(MLX_PATH)include -framework OpenGL -framework AppKit

$(LIBFT) : libf

libf :
	make -C libft
	
$(FILLER_OBJ) : filler_src/filler.h
$(VISU_OBJ) : visu_src/filler_visu.h
$(EXECUTER_OBJ) : executer_src/filler_executer.h

clean:
	make clean -C libft
	rm -f $(FILLER_OBJ) $(VISU_OBJ) $(EXECUTER_OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(VISU) $(EXECUTER)

re: fclean all
