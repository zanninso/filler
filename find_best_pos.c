/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 03:14:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/19 19:13:29 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

_Bool can_place_it(t_piece *piece, t_board *board, t_point position)
{
	int x;
	int y;
	int contact;

	if (position.x + piece->ship_width >= board->width)
		return (0);
	if (position.y + piece->ship_height >= board->height)
		return (0);
	contact = 0;
	y = 0;
	while (y < piece->height && contact < 1)
	{
		x = 0;
		while (x < piece->width && contact < 1)
		{
			if (piece->piece[piece->ship_y + y][piece->ship_x + x] == '*')
				contact += (board->board[position.y + y][position.x + x] > 0);
			x++;
		}
		y++;
	}
	return (contact == 1);
}

void update_score(t_piece *piece, t_board *board, t_point position)
{
	int score;
	int min_edge_score;
	int x;
	int y;

	score = board->width + board->height;
	min_edge_score = board->width;
	if (can_place_it(piece, board, position))
	{
		while (y < piece->height)
		{
			x = 0;
			while (x < piece->width)
			{
				if (piece->piece[piece->ship_y + y][piece->ship_x + x] == '*')
					score = ft_min(board->board[position.y + y][position.x + x], score);
				x++;
			}
			y++;
		}
	}
}

t_point find_best_pos(t_filler *filler, t_list *queue)
{
	const t_board *board = &filler->board;
	t_point best_p;
	t_point point;
	int x;
	int y;

	ft_bzero(&best_p, sizeof(t_point));
	while (queue)
	{
		y = -1;
		while (++y < filler->piece.height)
		{
			x = -1;
			while (++x < filler->piece.width && filler->piece.piece[y][x] == '*')
			{
				point.x = ((t_board_place *)queue->content)->x - x;
				point.y = ((t_board_place *)queue->content)->y - y;
				if (BETWEEN(x, 0, board->width) && BETWEEN(y, 0, board->width))
					update_score(&filler->piece, &filler->board, point);
			}
		}
		queue = queue->next;
	}
	return (best_p);
}