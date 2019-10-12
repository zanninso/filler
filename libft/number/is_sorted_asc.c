/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_asc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:22:40 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/19 22:18:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_sorted_asc(int *t, size_t size)
{
	int		i;
	bool	o;

	o = 1;
	i = -1;
	while ((size_t)++i < size - 1 && o)
		o = t[i] <= t[i + 1];
	return (o);
}