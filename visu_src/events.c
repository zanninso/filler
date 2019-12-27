/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 00:14:08 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/24 02:54:07 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

int		key_press(int keycode, t_visu *visu)
{
	if (keycode == 49)
		visu->runing ^= 1;
	if (keycode == 53)
	{
		ft_free_2d_tab(visu->map);
		exit(0);
	}
	return (1);
}

void	attach_hooks(t_visu *visu)
{
	mlx_hook(visu->win_ptr, 2, 1, key_press, visu);
}
