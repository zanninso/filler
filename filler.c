/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:10 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/21 17:44:32 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void heat_map(t_filler *filler, t_list *queue)
{
	int x;
	int y;
	t_point *t;
	t_point new;

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

void free_all_and_exit(t_filler *filler)
{
	free_piece(filler);
	free_board(filler);
	exit(0);
}

_Bool init(t_filler *filler)
{
	char *line;
	char *tmp;

	ft_bzero(filler, sizeof(t_filler));
	filler->output_fd = 2;
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

int main()
{
	t_filler filler;

	init(&filler);
	while (1)
	{
		filler.score = INT32_MAX;
		filler.best_position = (t_point){0, 0, 0};
		heat_map(&filler, filler.opponent_edges);
		find_best_pos(&filler, filler.my_edges);
		ft_printf("%d %d\n", filler.best_position.y - filler.piece.ship_y,filler.best_position.x - filler.piece.ship_x);
		filler.opponent_edges = NULL;
		filler.my_edges = NULL;
		free_piece(&filler);
		if (!update_board(&filler) || !get_new_piece(&filler))
			free_all_and_exit(&filler);
	}
}

// int main()
// {
// 	t_filler filler;
// 	const int fd = open("output3", O_RDONLY);

// 	dup2(fd, 0);
// 	init(&filler);
// 	while (1)
// 	{
// 		filler.score = INT32_MAX;
		
// 		filler.best_position = (t_point){0, 0, 0};
// 		heat_map(&filler, filler.opponent_edges);
// 		print_map(1, &filler.board);
// 		//print_ship(1, &filler.piece);
// 		find_best_pos(&filler, filler.my_edges);
// 		ft_printf("%d %d\n", filler.best_position.x - filler.piece.ship_x,
// 								filler.best_position.y - filler.piece.ship_y);
// 		filler.opponent_edges = NULL;
// 		filler.my_edges = NULL;
// 		if (!update_board(&filler) || !get_new_piece(&filler))
// 			free_all_and_exit(&filler);
// 	}
// }

// int main()
// {
// 	char *line;

// 	line = NULL;
// 	while (get_next_line(0, &line))
// 	{
// 		ft_putendl_fd(line, 2);
// 	}
// 	return (0);
// }
