/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:03:58 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/24 03:26:53 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISU_H

# define FILLER_VISU_H
# include <pthread.h>
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define TITLE "FILLER VISUALISER"
# define WHITH 0x098cd9
# define RED 0xfe2619
# define TRANSPARENT 0xff000000
# define RED 0xfe2619
# define BACK_GROUND 0x01ffffff

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_visu
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		**map;
	char		player1[21];
	char		player2[21];
	int			*data;
	t_point		size;
	int			runing;
	int			start_x;
	int			start_y;
	int			x_piece;
	int			o_piece;
	int			round;
	int			cell_size;
	int			win_width;
	int			win_height;
	double		percent_width;
	double		percent_start_x;
	int			start_menu;
}				t_visu;

int				run_game(t_visu *visu);

int				draw_map(t_visu *visu, int cell_size);
void			draw_menu(t_visu *visu);

void			attach_hooks(t_visu *visu);

t_point			get_map_size(void);
int				read_map(char **map, int hieght, int width);
int				get_player_name(char *player);

void			put_pixel(t_visu *visu, int x, int y, int color);

#endif
