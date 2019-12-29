/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:12:26 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/28 16:54:32 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_executer.h"

void	set_button_name(char *name, int i)
{
	if (i == 0)
		(ft_strcpy(name, "Aait-ihi"));
	else if (i == 1)
		(ft_strcpy(name, "champely"));
	else if (i == 2)
		(ft_strcpy(name, "grati"));
	else if (i == 3)
		(ft_strcpy(name, "abanlin"));
	else if (i == 4)
		(ft_strcpy(name, "hcao"));
	else if (i == 5)
		(ft_strcpy(name, "Carli"));
	else if (i == 6)
		(ft_strcpy(name, "Superjeannot"));
	else if (i == 7)
		(ft_strcpy(name, "Map00"));
	else if (i == 8)
		(ft_strcpy(name, "Map01"));
	else if (i == 9)
		(ft_strcpy(name, "Map02"));
}

void	set_buttons(t_executer *executer)
{
	int		i;
	t_point	p;
	int		x_step;

	x_step = 190;
	i = 0;
	p = (t_point){0, 0};
	while (i < 10)
	{
		executer->buttons[i].p1 = p;
		executer->buttons[i].p2 = (t_point){p.x + x_step, p.y + 45};
		set_button_name(executer->buttons[i].name, i);
		p.y += 47;
		i++;
		if (i == 7)
		{
			p = (t_point){195, 0};
			x_step = 120;
		}
	}
}

void	run_game(t_executer *env)
{
	pid_t	pid;
	char	cmd[1024];

	(void)env;
	pid = 0;
	cmd[0] = 0;
	ft_strcat(cmd, "resources/filler_vm -f resources/maps/map0");
	ft_strcat(cmd, (char[2]){env->map + 48, ' '});
	ft_strcat(cmd, "-p1 resources/players/");
	ft_strcat(cmd, env->buttons[env->player1].name);
	ft_strcat(cmd, ".filler -p2  resources/players/");
	ft_strcat(cmd, env->buttons[env->player2].name);
	ft_strcat(cmd, ".filler | ./filler_visu");
	pid = fork();
	if (pid == 0)
	{
		system(cmd);
		exit(0);
	}
}

void	init(t_executer *env)
{
	int	n;

	ft_bzero(env, sizeof(t_executer));
	set_buttons(env);
	env->player1 = 0;
	env->player2 = 1;
	env->win_width = 315;
	env->win_height = 415;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->win_width,
														env->win_height, TITLE);
	env->img = mlx_new_image(env->mlx_ptr, env->win_width, env->win_height);
	env->data = (int *)mlx_get_data_addr(env->img, &n, &n, &n);
	attach_hooks(env);
}

int		main(void)
{
	t_executer	env;

	init(&env);
	draw_menu(&env);
	mlx_loop(env.mlx_ptr);
}
