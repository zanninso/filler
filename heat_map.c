/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:08:53 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/01 21:36:07 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

fill_vertically(t_filler *filler, int x, int y)
{
	int i;

	i = 1;
	while(y >= 0 && filler->board.board[y - i][x] == '.')
		filler->board.board[y - i][x] == i++;
	while(y < filler->board.width && filler->board.board[y][x] == filler->opponent)
		y++;
	i = 1;
	while(y + i < filler->board.width && filler->board.board[y + i][x] == '.')
		filler->board.board[y + i][x] == i++;
}

void heat_map(t_filler *filler)
{
	int y = filler->opponent_position.y;
	int x = filler->opponent_position.x;
	while(x < filler->board.width)
	{
		while(filler->board.board[y][x])
			y++;
		fill_vertically(filler ,x , y);
	}
}
