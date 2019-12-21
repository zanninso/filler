# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 14:24:44 by aait-ihi          #+#    #+#              #
#    Updated: 2019/12/20 18:17:31 by aait-ihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = aait-ihi.filler

CFLAGS = -Wall -Werror -Wextra -g

CC = gcc

SRCS = filler.c board.c piece.c debug.c find_best_pos.c

LIBFT = libft/libft.a

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) -g $(CFLAGS) $(OBJ) $(LIBFT) libft/list/ft_lstenqueue.c -o $(NAME)

$(LIBFT) : libf

libf :
	make -C libft
$(OBJ) : filler.h

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
