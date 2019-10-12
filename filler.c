/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:10 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/10/11 15:57:58 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

 void init()
 {
	char *line;

	line = NULL;
	if(get_next_line(0, &line))
	{
		if(ft_strstr(line, "p1"))
	}
 }

int main()
{
	char *line = "$$$ exec p1 : [../aait-ihi]";
	/*int fd;

	line = NULL;
	fd = open("output", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	fd = fd == -1 ? 2 : fd;
	while(get_next_line(0, &line))
	{
		//ft_putstr("mzn\n");
		ft_putendl_fd(line, fd);
	}*/
	//get_next_line(0, &line);
	ft_putendl(ft_strstr(line, "p"));
}
