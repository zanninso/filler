/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:55:09 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/23 22:47:35 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_board(t_board *board)
{
	int	i;

	i = 0;
	while (i < board->height)
	{
		free(board->board[i]);
		i++;
	}
	board->height = 0;
	board->width = 0;
	free(board->board);
}

void	free_piece(t_piece *piece)
{
	int	i;

	i = 0;
	while (i < piece->height)
	{
		free(piece->piece[i]);
		i++;
	}
	free(piece->piece);
	ft_bzero(piece, sizeof(t_piece));
}

void	free_all_and_exit(t_filler *filler)
{
	free_piece(&filler->piece);
	free_board(&filler->board);
	exit(0);
}
