#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*buf;
	int		fd;
	int		ret;

	buf = (char *) malloc(sizeof(char) * 20);
	fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	//for (int j = 0; j < 15; j++)
	//{
	//	ret = read(fd, buf, 5);
	//	for (int i = 0; i < 5; i++)
	//	{
	//		printf("%d : %c, ascii : (%d)\n", i + 1, buf[i], buf[i]);
	//	}
	//	printf("read : %d \n", ret);
	//}
	free(buf);
	return (0);
}
