# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 18:37:33 by gyoon             #+#    #+#              #
#    Updated: 2022/10/17 18:51:46 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=1

SRCS = main.c \
	   ../source/get_next_line_utils.c \
	   ../source/get_next_line.c
OBJS = ${SRCS:.c=.o}
HEADER = ../source
NAME = GNL_TEST

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -I $(HEADER) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

