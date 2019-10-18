/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:10 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/10/18 03:23:17 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	if(get_next_line(0, &line))
	{
		 filler->me = (ft_strstr(line, "p1") ? 'x' : 'o');
		 filler->opponent = (filler->me == 'o' ? 'x' : 'o');
		 ft_strdel(&line);
	}
	if(get_next_line(0, &line))
	{
		tmp = ft_strstr(line, "Plateau ");
		filler->board.height = ft_atoi(tmp);
		filler->board.width = ft_atoi(ft_strstr(tmp," "));
		ft_strdel(&line);
	}
	if(!get_new_board(filler) || !get_new_piece(filler))
		return (0);
	return (1);
}

 int main()
 {
	 t_filler filler;
	 t_point best_position;

	 init(&filler);
	 while(1)
	 {
		if(!get_new_board(&filler) || !get_new_piece(&filler))
		 	free_all_and_exit(&filler);
		heat_map(&filler);
		best_position = find_best_pos(&filler);
		ft_printf("%d, %d", best_position.x, best_position.y);
	 }
 }

// int main()
// {
// 	char *line = "$$$ exec p1 : [../aait-ihi]";
// 	int fd;

// 	line = NULL;
// 	fd = open("output", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
// 	fd = fd == -1 ? 2 : fd;
// 	while(get_next_line(0, &line))
// 		ft_putendl_fd(line, fd);
// }
