/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:27:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/28 16:56:44 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_executer.h"

int		get_button(t_button *buttons, int x, int y)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (BETWEEN(x, buttons[i].p1.x, buttons[i].p2.x))
			if (BETWEEN(y, buttons[i].p1.y, buttons[i].p2.y))
				return (i);
		i++;
	}
	return (-1);
}

void	redraw_button(t_executer *env, t_button *button, int color)
{
	draw_rectangle(button->p1, button->p2, color, env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
}

int		key_press(int keycode, t_executer *env)
{
	(void)env;
	if (keycode == 53)
		exit(0);
	return (1);
}

int		mouse_press(int button, int x, int y, t_executer *env)
{
	int	i;
	int	*player;
	int	color;

	if (BETWEEN(button, 1, 2) && (i = get_button(env->buttons, x, y)) >= 0)
	{
		if (BETWEEN(i, 7, 9))
		{
			redraw_button(env, &env->buttons[env->map + 7], 0x211f17);
			redraw_button(env, &env->buttons[i], MAP_COLOR);
			draw_buttons_name(env, env->buttons);
			env->map = i - 7;
			return (0);
		}
		player = button == 1 ? &env->player1 : &env->player2;
		color = button == 1 ? PLYR1_COLOR : PLYR2_COLOR;
		redraw_button(env, &env->buttons[*player], 0x211f17);
		redraw_button(env, &env->buttons[i], color);
		draw_buttons_name(env, env->buttons);
		*player = i;
	}
	if (button == 1 && BETWEEN(y, 328, env->win_height))
		run_game(env);
	return (0);
}

void	attach_hooks(t_executer *env)
{
	mlx_hook(env->win_ptr, 2, 1, key_press, env);
	mlx_hook(env->win_ptr, 4, 1, mouse_press, env);
}
