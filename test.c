#include "filler.h"

int main()
{
	// char *line = "$$$ exec p1 : [../aait-ihi]";
	// int fd;

	// line = NULL;
	// fd = open("output", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	// fd = fd == -1 ? 2 : fd;
	// while(get_next_line(0, &line))
	// 	ft_putendl_fd(line, fd);
	char	*line;

	while (get_next_line(0, &line))
	{
		ft_putendl_fd(line, 2);
	}
	return (0);
}
