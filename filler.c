/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:10 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/18 22:36:36 by aait-ihi         ###   ########.fr       */
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
		y = -1 * t->y > 0;
		while (y < 2 && t->y + y < filler->board.height)
		{
			x = (-1 * t->x > 0) - 1;
			while (++x < 2 && t->x + x < filler->board.width)
				if (filler->board.board[t->y + y][t->x + x] >= t->value)
				{
					filler->board.board[t->y + y][t->x + x] = t->value + 1;
					new = (t_point){t->x + x, t->y + y, t->value + 1}
					ft_lstenqueue(queue,ft_lstnew(&new, sizeof(t_point)));
				}
			y++;
		}
		ft_lstdequeue(&filler->queue);
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
	int i;

	ft_bzero(filler, sizeof(t_filler));
	line = NULL;
	if (get_next_line(0, &line))
	{
		filler->me = (ft_strstr(line, "p1") ? 'x' : 'o');
		filler->opponent = (filler->me == 'o' ? 'x' : 'o');
		ft_strdel(&line);
	}
	if (get_next_line(0, &line))
	{
		tmp = ft_strstr(line, "Plateau ");
		filler->board.height = ft_atoi(tmp);
		filler->board.width = ft_atoi(ft_strstr(tmp, " "));
		ft_strdel(&line);
	}
	if (!get_new_board(filler) || !get_new_piece(filler))
		return (0);
	return (1);
}

int main()
{
	t_filler filler;
	t_point best_position;

	init(&filler);
	while (1)
	{
		if (!get_new_board(&filler) || !get_new_piece(&filler))
			free_all_and_exit(&filler);
		heat_map(&filler);
		best_position = find_best_pos(&filler);
		//ft_printf("%d, %d", best_position.x, best_position.y);
	}
}

int main()
{
	// char *line = "$$$ exec p1 : [../aait-ihi]";
	// int fd;

	// line = NULL;
	// fd = open("output", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	// fd = fd == -1 ? 2 : fd;
	// while(get_next_line(0, &line))
	// 	ft_putendl_fd(line, fd);
	char *line;

	while (get_next_line(0, &line))
	{
		ft_putendl_fd(line, 2);
	}
	return (0);
}
