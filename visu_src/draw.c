/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:04:37 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/23 23:37:36 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

void	draw_rectangle(t_point p1, t_point p2, int color, t_visu *visu)
{
	int	i;

	while (p1.y < p2.y)
	{
		i = p1.x;
		while (i < p2.x)
		{
			put_pixel(visu, i, p1.y, color);
			i++;
		}
		p1.y++;
	}
}

int		draw_map(t_visu *visu, int cell_size)
{
	int		x;
	int		y;
	int		piece;
	t_point	p1;
	t_point	p2;

	y = -1;
	piece = 0;
	while (++y < visu->size.y)
	{
		x = -1;
		while (++x < visu->size.x)
		{
			p1 = (t_point){x * cell_size + 1, y * cell_size + 1};
			p2 = (t_point){p1.x + cell_size - 2, p1.y + cell_size - 2};
			if (visu->map[y][x] == 'o' || visu->map[y][x] == 'x')
			{
				piece = visu->map[y][x];
				draw_rectangle(p1, p2, piece == 'o' ? WHITH : RED, visu);
			}
		}
	}
	return (piece);
}

void	draw_percentag(t_visu *visu)
{
	t_point	p1;
	t_point	p2;
	double	p1_percent;

	if (visu->x_piece == 0 || visu->o_piece == 0)
		return ;
	p1_percent = (float)visu->o_piece * 100 /
										(float)(visu->x_piece + visu->o_piece);
	p1 = (t_point){visu->percent_start_x, visu->start_menu};
	p2 = (t_point){p1.x + (visu->percent_width / 100.) * p1_percent,
														visu->start_menu + 50};
	draw_rectangle(p1, p2, WHITH, visu);
	p1 = (t_point){p2.x, visu->start_menu};
	p2 = (t_point){visu->percent_start_x + visu->percent_width,
														visu->start_menu + 50};
	draw_rectangle(p1, p2, RED, visu);
}

void	draw_players_name_score(t_visu *visu)
{
	int		x;
	int		y;
	int		width;
	char	*tmp;

	x = visu->percent_start_x;
	y = visu->start_menu - 30;
	width = visu->percent_width + visu->percent_start_x;
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, x, y, WHITH, visu->player1);
	x = width - ft_declen(visu->o_piece) * 10;
	if ((tmp = ft_itoa(visu->o_piece)))
		mlx_string_put(visu->mlx_ptr, visu->win_ptr, x, y, WHITH, tmp);
	free(tmp);
	x = visu->percent_start_x;
	y = visu->start_menu + 60;
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, x, y, RED, visu->player2);
	x = width - ft_declen(visu->x_piece) * 10;
	if ((tmp = ft_itoa(visu->x_piece)))
		mlx_string_put(visu->mlx_ptr, visu->win_ptr, x, y, RED, tmp);
	free(tmp);
}

void	draw_menu(t_visu *visu)
{
	t_point	p1;
	t_point	p2;

	p1 = (t_point){0, visu->start_y};
	p2 = (t_point){visu->win_width, visu->win_height};
	if (visu->round == 0)
	{
		draw_rectangle(p1, p2, BACK_GROUND, visu);
		draw_rectangle((t_point){0, 0},
					(t_point){visu->win_width, visu->start_y}, 0x2a2d33, visu);
	}
	if (visu->round % 2)
		draw_percentag(visu);
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->img, 0, 0);
	draw_players_name_score(visu);
}
