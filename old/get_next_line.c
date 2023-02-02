/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/19 16:15:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	buf;
	t_string		line;

	line.str = 0;
	line.len = 0;
	if (buf.idx)
	{
		if (!update_line(&line, &buf))
			return (0);
		update_buffer(&buf);
	}
	while (!buf.idx)
	{
		if (read_buffer(fd, &buf) <= 0)
			break ;
		if (!update_line(&line, &buf))
		{
			free(line.str);
			return (0);
		}
		update_buffer(&buf);
		if (line.str[line.len - 1] == '\n')
			break ;
	}
	return (line.str);
}
