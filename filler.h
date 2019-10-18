/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:06 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/10/18 16:57:27 by aait-ihi         ###   ########.fr       */
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
	int		width;
	int		height;

}				t_piece;

typedef struct	s_filler
{
	t_board board;
	t_piece piece;
	char	me;
	char	opponent;
	t_point my_position;
}				t_filler;

void			free_board(t_filler *filler);
_Bool			get_new_board(t_filler *filler);
void			free_piece(t_filler *filler);
_Bool			get_new_piece(t_filler *filler);
void			heat_map(t_filler *filler);
t_point			find_best_pos(t_filler *filler);


#endif
