/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 02:07:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/28 17:07:01 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

_Bool	allocat_peice(t_filler *filler)
{
	int		i;
	char	**piece;

	if (filler->piece.height == 0 || filler->piece.width == 0)
		return (0);
	if (!(piece = (char **)ft_memalloc(sizeof(char *) * filler->piece.height)))
		return (0);
	i = 0;
	while (i < filler->piece.height)
	{
		if (!(piece[i] = (char *)ft_strnew(filler->piece.width)))
		{
			ft_free_2d_tab(piece);
			return (0);
		}
		i++;
	}
	filler->piece.piece = piece;
	return (1);
}

void	analyse_piece(t_piece *p)
{
	int	i;
	int	j;
	int	max;

	i = -1;
	j = 0;
	max = 0;
	while (++i < p->height)
		if (ft_strchr(p->piece[i], '*'))
			break ;
	p->ship_y = i;
	while (i < p->height && ft_strchr(p->piece[i], '*'))
	{
		p->ship_x = ft_min(ft_strindexof(p->piece[i], '*'), p->ship_x);
		max = ft_max(ft_strrchr(p->piece[i], '*') - p->piece[i], max);
		i++;
		j++;
	}
	p->ship_height = j;
	p->ship_width = (max - p->ship_x) + 1;
}

_Bool	get_new_piece(t_filler *filler)
{
	char	*line;
	char	*tmp;
	int		i;

	line = NULL;
	i = 0;
	if (get_next_line(0, &line) > 0 && (tmp = ft_strchr(line, ' ')))
	{
		filler->piece.height = ft_atoi(tmp);
		filler->piece.width = ft_atoi(ft_strchr(tmp + 1, ' '));
		ft_putendl_fd(line, filler->output_fd);
	}
	ft_strdel(&line);
	if (!allocat_peice(filler))
		return (0);
	while (i < filler->piece.height && get_next_line(0, &line) > 0)
	{
		ft_strncpy(filler->piece.piece[i], line, filler->piece.width);
		ft_putendl_fd(line, filler->output_fd);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	return (i == filler->piece.height);
}
