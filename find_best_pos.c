/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 03:14:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/19 22:37:11 by aait-ihi         ###   ########.fr       */
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
	while (y < piece->ship_height && contact < 1)
	{
		x = 0;
		while (x < piece->ship_width && contact < 1)
		{
			if (piece->piece[piece->ship_y + y][piece->ship_x + x] == '*')
				contact += (board->board[position.y + y][position.x + x] > 0);
			x++;
		}
		y++;
	}
	return (contact == 1);
}

void update_score(t_filler *filler,t_piece *piece, t_board *board, t_point p)
{
	int score;
	int edg;
	int x;
	int y;

	score = INT32_MAX;
	edg = INT32_MAX;
	if (!can_place_it(piece, board, p))
		return (0);
	y = -1;
	while (++y < piece->ship_height && (x = -1))
		while (++x < piece->ship_width)
			if (piece->piece[piece->ship_y + y][piece->ship_x + x] == '*')
				if (board->board[p.y + y][p.x + x] < 0)
				{
					score = ft_min(board->board[p.y + y][p.x + x], score);
					edg = ft_min((board->width - p.x + x) % board->width, edg);
				}
	if(score + edg < score)
	{
		filler->best_position = p;
		filler->score = score + edg;
	}
}

void find_best_pos(t_filler *filler, t_list *queue)
{
	const t_board *board = &filler->board;
	t_point point;
	int x;
	int y;

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
				if (BETWEEN(x, 0, board->width) && BETWEEN(y, 0, board->height))
					update_score(filler, &filler->piece, &filler->board, point);
			}
		}
		ft_lstdequeue(&queue, ft_memdel);
	}
}