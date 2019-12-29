/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:13:00 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/28 17:56:21 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_executer.h"

static void	put_pixel(t_executer *env, int x, int y, int color)
{
	if (BETWEEN(x, 0, env->win_width) && BETWEEN(y, 0, env->win_height))
		env->data[y * env->win_width + x] = color;
}

void		draw_rectangle(t_point p1, t_point p2, int color, t_executer *env)
{
	int	i;

	while (p1.y < p2.y)
	{
		i = p1.x;
		while (i < p2.x)
		{
			put_pixel(env, i, p1.y, color);
			i++;
		}
		p1.y++;
	}
}

void		draw_buttons_name(t_executer *env, t_button *buttons)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_string_put(env->mlx_ptr,
						env->win_ptr,
						buttons[i].p1.x + 2,
						buttons[i].p1.y + 10,
						0xffffff,
						buttons[i].name);
		i++;
	}
	mlx_string_put(env->mlx_ptr,
						env->win_ptr,
						60,
						355,
						0xffffff,
						"Click here to start");
}

void		draw_buttons(t_executer *env, t_button *buttons, int count)
{
	int			i;
	const int	color[3] = {PLYR1_COLOR, PLYR2_COLOR, 0x211f17};

	i = 0;
	while (i < count)
	{
		draw_rectangle(buttons[i].p1, buttons[i].p2, color[i > 1 ? 2 : i], env);
		i++;
	}
}

void		draw_menu(t_executer *env)
{
	draw_rectangle((t_point){0, 0}, (t_point){315, 328}, BACK_GROUND, env);
	draw_buttons(env, env->buttons, 10);
	redraw_button(env, &env->buttons[env->map + 7], MAP_COLOR);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
	draw_buttons_name(env, env->buttons);
}
