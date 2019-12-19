/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 01:37:28 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/19 01:33:50 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

_Bool allocat_board(t_filler *filler)
{
	int i;
	char **board;

    if(filler->board.height == 0 || filler->board.width == 0)
        return(0);
	if(!(board = (char **)malloc(sizeof(char*) * filler->board.height)))
		return (0);
	i = 0;
	while(i < filler->board.height)
	{
		if(!(board[i] = (char *)ft_memalloc(sizeof(char) * filler->board.width)))
		{
			while(i--)
				free(board[i]);
			free(board);
			return(0);
		}
		i++;
	}
	filler->board.board = board; 
	return(1);
}

void    free_board(t_filler *filler)
{
    int i;

    i = 0;
    while(i < filler->board.height)
	{
		free( filler->board.board[i]);
		i++;
	}
    filler->board.height = 0;
    filler->board.width = 0;
    free( filler->board.board);
}

_Bool get_new_board(t_filler *filler)
{
    char *line;
    char *tmp;
    int i;

    i = 0;
    line  = NULL;
    if(!allocat_board(filler))
        return(0);
    get_next_line(0, &line);
    ft_strdel(&line);
    while(i < filler->board.height && get_next_line(0, &line) > 0)
    {
        if(!(tmp =ft_strchr(line, ' ')))
            break;
        tmp = ft_translate(tmp + 1, ".", "\200");
        ft_strcpy(filler->board.board[i], line);
        ft_strdel(&line);
        i++;
    }
    ft_strdel(&line);
    return(i != filler->board.height);
}