/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 01:37:28 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/24 01:19:19 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_edge(int x, int y, t_board *board, char c)
{
	int	ret;

	ret = 0;
	if (y - 1 >= 0 && x - 1 >= 0)
		ret |= board->board[y - 1][x - 1] < 0;
	if (y - 1 >= 0 && x + 1 < board->width)
		ret |= board->board[y - 1][x + 1] < 0;
	if (y - 1 >= 0)
		ret |= board->board[y - 1][x] < 0;
	if (x - 1 >= 0)
		ret |= board->board[y][x - 1] < 0;
	if (x + 1 < board->width)
		ret |= board->board[y][x + 1] < 0;
	if (y + 1 < board->height && x - 1 >= 0)
		ret |= board->board[y + 1][x - 1] < 0;
	if (y + 1 < board->height)
		ret |= board->board[y + 1][x] < 0;
	if (y + 1 < board->height && x + 1 < board->width)
		ret |= board->board[y + 1][x + 1] < 0;
	if (ret && ft_toupper(board->board[y][x]) == c)
		ret = 2;
	return (ret);
}

void	get_edges(t_filler *filler)
{
	int				y;
	int				x;
	t_board_place	place;
	t_list			*new;
	int				is_edg;

	y = -1;
	while (++y < filler->board.height && (x = -1))
		while (++x < filler->board.width)
		{
			is_edg = 0;
			place = (t_board_place){x, y, -127};
			if (filler->board.board[y][x] > 0)
				is_edg = is_edge(x, y, &filler->board, filler->opponent);
			if (is_edg == 1)
			{
				new = ft_lstnew(&place, sizeof(t_board_place));
				ft_lstenqueue(&filler->my_edges, new);
			}
			else if (is_edg == 2)
			{
				new = ft_lstnew(&place, sizeof(t_board_place));
				ft_lstenqueue(&filler->opponent_edges, new);
			}
		}
}

void	skip_lines(t_filler *filler)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_putendl_fd(line, filler->output_fd);
		if (ft_strstr(line, "0123456"))
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

_Bool	update_board(t_filler *filler)
{
	char	*line;
	char	*tmp;
	int		i;

	line = NULL;
	skip_lines(filler);
	i = 0;
	while (i < filler->board.height && get_next_line(0, &line) > 0)
	{
		ft_putendl_fd(line, filler->output_fd);
		if (!(tmp = ft_strchr(line, ' ')) ||
								(int)ft_strlen(tmp + 1) != filler->board.width)
			break ;
		tmp = ft_translate(tmp + 1, ".", "\xff");
		ft_memcpy(filler->board.board[i], tmp, filler->board.width);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	get_edges(filler);
	return (i == filler->board.height);
}

_Bool	get_new_board(t_filler *filler)
{
	t_board *bord;

	bord = &filler->board;
	bord->board = (char **)ft_malloc2d(bord->height, bord->width, ft_memalloc);
	if (!bord->board)
		return (0);
	return (update_board(filler));
}
