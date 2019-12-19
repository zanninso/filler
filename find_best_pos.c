/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 03:14:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/19 01:42:44 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

_Bool can_place_it(t_piece *piece, t_board *board, t_point position)
{
	int x;
	int y;

	y = 0;
    while(y < piece->height)
	{
		x = 0;
		while(x < piece->width)
		{
			if(board[])
		}
		
	}
	
}

t_point find_best_pos(t_filler *filler)
{
	t_point best_p;

	ft_bzero(&best_p, sizeof(t_point));
	return (best_p);
}