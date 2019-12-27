/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:10 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/24 01:21:52 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	heat_map(t_filler *filler, t_list *queue)
{
	int		x;
	int		y;
	t_point	*t;
	t_point	new;

	while (queue)
	{
		t = (t_point *)queue->content;
		y = -1 * (t->y > 0);
		while (y < 2 && t->y + y < filler->board.height)
		{
			x = (-1 * (t->x > 0)) - 1;
			while (++x < 2 && t->x + x < filler->board.width)
				if (filler->board.board[t->y + y][t->x + x] < 0)
					if (filler->board.board[t->y + y][t->x + x] > t->value + 1)
					{
						filler->board.board[t->y + y][t->x + x] = t->value + 1;
						new = (t_point){t->x + x, t->y + y, t->value + 1};
						ft_lstenqueue(&queue, ft_lstnew(&new, sizeof(t_point)));
					}
			y++;
		}
		ft_lstdequeue(&queue, ft_memdel);
	}
}

_Bool	init(t_filler *filler)
{
	char	*line;
	char	*tmp;

	ft_bzero(filler, sizeof(t_filler));
	filler->output_fd = open("input", O_WRONLY | O_CREAT, 0666);
	line = NULL;
	if (get_next_line(0, &line))
	{
		filler->me = (ft_strstr(line, "p1") ? 'O' : 'X');
		filler->opponent = (filler->me == 'O' ? 'X' : 'O');
		ft_putendl_fd(line, filler->output_fd);
		ft_strdel(&line);
	}
	if (get_next_line(0, &line))
	{
		tmp = ft_strchr(line, ' ');
		filler->board.height = ft_atoi(tmp);
		filler->board.width = ft_atoi(ft_strchr(tmp + 1, ' '));
		ft_putendl_fd(line, filler->output_fd);
		ft_strdel(&line);
	}
	if (!get_new_board(filler) || !get_new_piece(filler))
		return (0);
	return (1);
}

int		main(void)
{
	t_filler	filler;

	if (!init(&filler))
		free_all_and_exit(&filler);
	analyse_piece(&filler.piece);
	while (1)
	{
		filler.score = INT32_MAX;
		filler.best_position = (t_point){0, 0, 0};
		heat_map(&filler, filler.opponent_edges);
		find_best_pos(&filler, &filler.piece, &filler.board, filler.my_edges);
		ft_printf("%d ", filler.best_position.y - filler.piece.ship_y);
		ft_printf("%d\n", filler.best_position.x - filler.piece.ship_x);
		filler.opponent_edges = NULL;
		filler.my_edges = NULL;
		free_piece(&filler.piece);
		if (!update_board(&filler) || !get_new_piece(&filler))
			free_all_and_exit(&filler);
		analyse_piece(&filler.piece);
	}
}
