/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:24:17 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/11 19:42:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 42

void	ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
		*dest++ = *src++;
}
int	get_len_line(char *buf, int size, int start, int len_read)
{
	int	idx;

	idx = start;
	while (idx < size && idx < len_read)
		if (buf[idx] == '\n')
			break ;
	return (idx - start);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE];
	static int		idx;
	static int		len_read;
	char			*line;
	int				len_line;

	// if sth is left 
	// first make string with read before 
	/*            B  B  B  B  B  B  B  B  B  B
		case 1.   x  x \n idx x  x  x \n  x  x (len_read = 8)
		case 2.   x  x \n idx x  x  x  x  x  x (len_read = 8)
		case 3.   x  x \n idx x  x  1  1  1  1 (len_read = 5)

	*/
	if (idx) // means sth is left
	{
		len_line = get_len_line(buf, BUFFER_SIZE, idx, len_read); // get len line
		line = (char *) malloc(sizeof(char) * (len_line + 1)); // malloc string
		for (int i = 0; i < len_line; i++) // copy line
			line[i] = buf[idx + i];
		idx = (idx + len_line) % BUFFER_SIZE; // update idx
	}
	while (1)
	{
		len_read = read(fd, buf, BUFFER_SIZE);
		// len_read == BUFFER_SIZE -> there is more to read.

		// len_read < BUFFER_SIZE -> there is nothing more to read, break while.
		if (len_read < BUFFER_SIZE)
		{

		}
		// len_read > BUFFER_SIZE -> there is something wrong.
	}

	len_read = read(fd, buf, BUFFER_SIZE);
	line = (char *) malloc(sizeof(char) * (len_read + 1));
	ft_strcpy(line, buf);
	return (line);
}

int	main(void)
{
	char	*buf;
	int		fd;
	int		ret;

	fd = open("test.txt", O_RDONLY);
	// for (int i = 0; i < 7; i++)
	//	printf("%d : %s\n", i, get_next_line(fd));
	printf("%d : %s\n", 0, get_next_line(fd));
	free(buf);
	return (0);
}
