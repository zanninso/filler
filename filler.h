/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:06 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/19 01:46:28 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_point
{
	int x;
	int y;
	int value;
}				t_point;

typedef struct	s_board
{
	char	**board;
	int		width;
	int		height;
}				t_board;

typedef struct	s_piece
{
	char	**piece;
	int		ship_x;
	int		ship_y;
	int		ship_height;
	int		ship_width;
	int		width;
	int		height;
}				t_piece;

typedef struct	s_filler
{
	t_board board;
	t_piece piece;
	char	me;
	char	opponent;
	t_list	*my_edge;
	t_list *opponent_edge;
}				t_filler;

void			free_board(t_filler *filler);
_Bool			get_new_board(t_filler *filler);
void			free_piece(t_filler *filler);
_Bool			get_new_piece(t_filler *filler);
void			heat_map(t_filler *filler, t_list *queue);
t_point			find_best_pos(t_filler *filler);


#endif
