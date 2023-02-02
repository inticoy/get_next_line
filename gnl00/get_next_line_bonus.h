/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:54 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/28 18:15:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer	t_buffer;

typedef struct s_buffer
{
	int			fd;
	char		buf[BUFFER_SIZE];
	int			idx;
	int			len;
	t_buffer	*next;
}	t_buffer;

typedef struct s_string
{
	char	*str;
	int		len;
	int		size;
}	t_string;

int			update_line(t_string *l, t_buffer b);
int			update_buffer(t_buffer *b);
t_string	optimize_string(t_string s);

char		*get_next_line(int fd);

#endif