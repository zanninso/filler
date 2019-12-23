/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 00:14:08 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/22 03:42:28 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

int key_press(int keycode, t_visu *visu)
{
    if (keycode == 49)
        visu->runing ^= 1;
    if(keycode == 53)
        exit(0);
    return (1);
}

void attach_hooks(t_visu *visu)
{
    // mlx_hook(fdf->win_ptr, 4, 1, mouse_press, fdf);
    // mlx_hook(fdf->win_ptr, 5, 1, mouse_release, fdf);
    // mlx_hook(fdf->win_ptr, 6, 1, mouse_move, fdf);
    mlx_hook(visu->win_ptr, 2, 1, key_press, visu);
}
