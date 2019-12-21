/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:28:20 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/21 01:24:20 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_map(int fd, t_board *board)
{
    int y;
    int x;

    (void)fd;
    y = 0;
    while(y < board->height)
    {
        x = 0;
        while(x < board->width)
        {
            ft_printf("\e[38;5;%dm %4d\e[m", board->board[y][x] * -1 + 80, board->board[y][x]);
            x++;
        }
        ft_printf("\n");
        y++;
    }
}

void print_ship(int fd, t_piece *piece)
{
    int y;

    (void)fd;
    y = 0;
    while(y < piece->height)
    {
        ft_printf("%.*s\n",piece->ship_width, piece->piece[piece->ship_y + y] + piece->ship_x);
        y++;
    }
}