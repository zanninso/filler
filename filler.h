/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:06 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/10/11 14:56:17 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H
# include "libft/includes/libft.h"
#include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_board
{
	char	**board;
	int		width;
	int		height;
}				t_board;

#endif
