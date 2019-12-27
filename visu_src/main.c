/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:01:52 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/24 03:26:30 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

void	clac_size(t_visu *visu)
{
	visu->win_width = 1000;
	visu->cell_size = visu->win_width / visu->size.x;
	visu->win_width = visu->cell_size * visu->size.x;
	visu->win_height = visu->cell_size * visu->size.y + 200;
	visu->start_y = visu->cell_size * visu->size.y;
	visu->start_menu = visu->start_y + 75;
	visu->percent_width = (((double)visu->win_width / 100.) * 70.);
	visu->percent_start_x = ((visu->win_width - visu->percent_width) / 2);
}

void	update_piece(t_visu *visu, char piece)
{
	if (piece == 'o')
		visu->o_piece++;
	else if (piece == 'x')
		visu->x_piece++;
}

int		run_game(t_visu *visu)
{
	if (!visu->runing || !read_map(visu->map, visu->size.y, visu->size.x))
		return (visu->runing);
	update_piece(visu, draw_map(visu, visu->cell_size));
	visu->round++;
	draw_menu(visu);
	return (visu->runing);
}

int		init(t_visu *visu)
{
	int	n;

	ft_bzero(visu, sizeof(t_visu));
	if (!get_player_name(visu->player1))
		return (0);
	if (!get_player_name(visu->player2))
		return (0);
	visu->size = get_map_size();
	if (visu->size.y <= 0 || visu->size.x <= 0)
		return (0);
	clac_size(visu);
	visu->map = (char **)ft_malloc2d(visu->size.y, visu->size.x, ft_memalloc);
	visu->mlx_ptr = mlx_init();
	visu->win_ptr = mlx_new_window(visu->mlx_ptr, visu->win_width,
													visu->win_height, TITLE);
	visu->img = mlx_new_image(visu->mlx_ptr, visu->win_width, visu->win_height);
	visu->data = (int *)mlx_get_data_addr(visu->img, &n, &n, &n);
	return (visu->mlx_ptr && visu->win_ptr && visu->map);
}

int		main(void)
{
	t_visu	visu;

	if (init(&visu))
	{
		draw_menu(&visu);
		mlx_loop_hook(visu.mlx_ptr, run_game, &visu);
		attach_hooks(&visu);
		mlx_loop(visu.mlx_ptr);
	}
	else
	{
		ft_free_2d_tab(visu.map);
		exit(1);
	}
}
