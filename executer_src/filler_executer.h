/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_executer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:10:38 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/28 17:01:04 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_EXECUTER_H

# define FILLER_EXECUTER_H
# include "../libft/includes/libft.h"
# include "mlx.h"
# define TITLE "FILLER EXECUTER"
# define PLYR1_COLOR 0x098cd9
# define PLYR2_COLOR 0xfe2619
# define MAP_COLOR 0xff9800
# define TRANSPARENT 0xff000000
# define RED 0xfe2619
# define BACK_GROUND 0x01ffffff

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_button
{
	t_point		p1;
	t_point		p2;
	char		name[20];
	int			selected;
	int			value;
}				t_button;

typedef struct	s_executer
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	int			*data;
	int			win_height;
	int			win_width;
	int			player1;
	int			player2;
	int			map;
	t_button	buttons[10];
}				t_executer;

void			draw_menu(t_executer *env);
void			redraw_button(t_executer *env, t_button *button, int color);
void			draw_buttons_name(t_executer *env, t_button *buttons);
void			draw_rectangle(t_point p1, t_point p2, int c, t_executer *env);

void			attach_hooks(t_executer *env);
void			run_game(t_executer *env);

#endif
