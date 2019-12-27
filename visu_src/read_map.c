/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:42:17 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/23 23:40:40 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

int		get_player_name(char *player)
{
	int		ret;
	char	*line;
	char	*tmp;

	line = NULL;
	ret = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "launched"))
		{
			if ((tmp = ft_strrchr(line, '/')))
			{
				ft_strreplace(tmp, '.', 0);
				ret = 1;
				ft_strncpy(player, tmp + 1, 20);
			}
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (ret);
}

t_point	get_map_size(void)
{
	t_point	size;
	char	*line;
	char	*tmp;

	size = (t_point){0, 0};
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			tmp = ft_strchr(line, ' ');
			size.y = ft_atoi(tmp);
			size.x = ft_atoi(ft_strchr(tmp + 1, ' '));
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (size);
}

int		skip_lines(void)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "    "))
		{
			ret = 1;
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (ret);
}

int		read_map(char **map, int hieght, int width)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	line = NULL;
	if (!skip_lines())
		return (0);
	while (i < hieght && get_next_line(0, &line) > 0)
	{
		if (!(tmp = ft_strchr(line, ' ')) || (int)ft_strlen(tmp + 1) < width)
			break ;
		ft_memcpy(map[i], tmp + 1, width);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	return (i == hieght);
}

void	put_pixel(t_visu *visu, int x, int y, int color)
{
	if (BETWEEN(x, 0, visu->win_width) && BETWEEN(y, 0, visu->win_height))
		visu->data[y * visu->win_width + x] = color;
}
