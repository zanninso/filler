/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 03:14:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/23 01:55:32 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

_Bool can_place_it(t_piece *piece, t_board *board, t_point position)
{
	int x;
	int y;
	int contact;
	const int width = piece->ship_width;

	if (position.x + piece->ship_width > board->width)
		return (0);
	if (position.y + piece->ship_height > board->height)
		return (0);
	contact = 0;
	y = 0;
	while (y < piece->ship_height && contact < 2)
	{
		x = 0;
		x = 0;
		while (x < width)
		{
			if (piece->piece[piece->ship_y + y][piece->ship_x + x] == '*')
				contact += (board->board[position.y + y][position.x + x] > 0);
			x++;
		}
		y++;
	}
	return (contact == 1);
}

int get_score(t_piece *piece, t_board *board, t_point p)
{
	int x;
	int y;
	int score;
	int edg;

	
	edg = INT32_MAX;
	score = INT32_MAX;
	y = 0;
	while (y < piece->ship_height)
	{
		x = 0;
		while (x < piece->ship_width)
		{
			if (piece->piece[piece->ship_y + y][piece->ship_x + x] == '*')
			{
				score = ft_min(board->board[p.y + y][p.x + x], score);
				edg = ft_min((board->width - p.x + x) % board->width, edg);
			}
			x++;
		}
		y++;
	}
	//edg = 0; 
	return (score + edg / 1);
}

void update_score(t_filler *filler, t_piece *piece, t_board *board, t_point p)
{
	int score;

	if (!can_place_it(piece, board, p))
		return;
	score = get_score(piece, board, p);
	if (score < filler->score)
	{
		filler->best_position = p;
		filler->score = score ;
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
		while (++y < filler->piece.ship_height)
		{
			x = -1;
			while (++x < filler->piece.ship_width)
				if (filler->piece.piece[filler->piece.ship_y + y][filler->piece.ship_x + x] == '*')
				{
					point.x = ((t_board_place *)queue->content)->x - x;
					point.y = ((t_board_place *)queue->content)->y - y;
					if (BETWEEN(point.x, 0, board->width) && BETWEEN(point.y, 0, board->height))
						update_score(filler, &filler->piece, &filler->board, point);
				}
		}
		ft_lstdequeue(&queue, ft_memdel);
	}
}