#include <fcntl.h>
#include <stdio.h>
#include "gnl.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
	}
	return (0);
}