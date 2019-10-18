/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 02:07:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/10/18 03:18:16 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

_Bool allocat_peice(t_filler *filler)
{
	int i;
	char **piece;

    if(filler->piece.height == 0 || filler->piece.width == 0)
        return(0);
	if(!(piece = (char **)malloc(sizeof(char*) * filler->piece.height)))
		return (0);
	i = 0;
	while(i < filler->piece.height)
	{
		if(!(piece[i] = (char *)ft_memalloc(sizeof(char) * filler->piece.width)))
		{
			while(i--)
				free(piece[i]);
			free(piece);
			return(0);
		}
		i++;
	}
	filler->piece.piece= piece; 
	return(1);
}

void    free_piece(t_filler *filler)
{
    int i;

    i = 0;
    while(i < filler->piece.height)
	{
		free( filler->piece.piece[i]);
		i++;
	}
    filler->piece.height = 0;
    filler->piece.width = 0;
    free(filler->piece.piece);
}

void fillter_piece(t_filler *filler)
{

}

_Bool get_new_piece(t_filler *filler)
{
    char *line;
    char *tmp;
    int i;

    free_piece(filler);
    line = NULL;
    i = 0;
    if(get_next_line(0,&line) > 0 && (tmp = ft_strstr(line,"Piece ")))
    {
        filler->piece.height = ft_atoi(tmp);
        filler->piece.width = ft_atoi(strstr(tmp," "));
         ft_strdel(&line);
    }
    if(!allocat_peice(filler))
        return(0);
    while(i < filler->piece.height && get_next_line(0,&line) > 0 )
    {
        ft_strcpy(filler->piece.piece[i],line);
        ft_strdel(&line);
        i++;
    }
    if(i == filler->piece.height)
        fillter_piece(filler);
    return(i == filler->piece.height);
}