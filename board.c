/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 01:37:28 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/21 00:58:49 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

_Bool allocat_board(t_filler *filler)
{
    int i;
    char **board;

    if (filler->board.height == 0 || filler->board.width == 0)
        return (0);
    if (!(board = (char **)ft_memalloc(sizeof(char *) * filler->board.height)))
        return (0);
    i = 0;
    while (i < filler->board.height)
    {
        if (!(board[i] = (char *)ft_memalloc(filler->board.width)))
        {
            ft_free_2d_tab(board);
            return (0);
        }
        i++;
    }
    filler->board.board = board;
    return (1);
}

int is_edge(int x, int y, t_board *board, char c)
{
    int ret;

    ret = 0;
    if (y - 1 >= 0 && x - 1 >= 0)
        ret |= board->board[y - 1][x - 1] < 0;
    if (y - 1 >= 0 && x + 1 < board->width)
        ret |= board->board[y - 1][x + 1] < 0;
    if (y - 1 >= 0)
        ret |= board->board[y - 1][x] < 0;
    if (x - 1 >= 0)
        ret |= board->board[y][x - 1] < 0;
    if (x + 1 < board->width)
        ret |= board->board[y][x + 1] < 0;
    if (y + 1 < board->height && x - 1 >= 0)
        ret |= board->board[y + 1][x - 1] < 0;
    if (y + 1 < board->height)
        ret |= board->board[y + 1][x] < 0;
    if (y + 1 < board->height && x + 1 < board->width)
        ret |= board->board[y + 1][x + 1] < 0;
    if (ret && ft_toupper(board->board[y][x]) == c)
        ret = 2;
    return (ret);
}

void get_edges(t_filler *filler)
{
    int y;
    int x;
    t_board_place place;
    t_list *new;
    int is_edg;

    y = -1;
    while (++y < filler->board.height && (x = -1))
        while (++x < filler->board.width)
        {
            is_edg = 0;
            place = (t_board_place){x, y, -127};
            if (filler->board.board[y][x] > 0)
                is_edg = is_edge(x, y, &filler->board, filler->opponent);
            if (is_edg == 1)
            {
                new = ft_lstnew(&place, sizeof(t_board_place));
                ft_lstenqueue(&filler->my_edges, new);
            }
            else if (is_edg == 2)
            {
                new = ft_lstnew(&place, sizeof(t_board_place));
                ft_lstenqueue(&filler->opponent_edges, new);
            }
        }
}

void skip_lines(t_filler *filler)
{
    char *line;

    line = NULL;
    while (get_next_line(0, &line))
    {
        ft_putendl_fd(line, filler->output_fd);
        if(ft_strstr(line,"0123456"))
        {
            ft_strdel(&line);
            break;
        }
        ft_strdel(&line);
    }
}

_Bool update_board(t_filler *filler)
{
    char *line;
    char *tmp;
    int i;

    line = NULL;
    skip_lines(filler);
    i = 0;
    while (i < filler->board.height && get_next_line(0, &line) > 0)
    {
        ft_putendl_fd(line, filler->output_fd);
        if (!(tmp = ft_strchr(line, ' ')))
            break;
        tmp = ft_translate(tmp + 1, ".", "\xff");
        ft_strcpy(filler->board.board[i], tmp);
        ft_strdel(&line);
        i++;
    }
    // ft_strdel(&line);
    get_edges(filler);
    return (i == filler->board.height);
}

_Bool get_new_board(t_filler *filler)
{
    if (!allocat_board(filler))
        return (0);
    return (update_board(filler));
}

void free_board(t_filler *filler)
{
    int i;

    i = 0;
    while (i < filler->board.height)
    {
        free(filler->board.board[i]);
        i++;
    }
    filler->board.height = 0;
    filler->board.width = 0;
    free(filler->board.board);
}