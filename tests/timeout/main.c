/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inticoy <inticoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:27:32 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/03 01:13:15 by inticoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	
	fd = open("test.txt", O_RDONLY);
	do {
		line = get_next_line(fd);
		printf("%s", line);
	} while (line);
	close(fd);
	free(line);
	return (0);
}
