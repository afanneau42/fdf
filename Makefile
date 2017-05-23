# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afanneau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 15:10:35 by afanneau          #+#    #+#              #
#    Updated: 2017/01/11 15:40:51 by afanneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCES = fdf.c \
		  init.c \
		  trace_line.c \
		  lines.c

OBJECTS = fdf.o \
		  init.o \
		  trace_line.o \
		  lines.o

all : $(NAME)

$(NAME) :
	make -C libft/ && make -C libft/ clean
	gcc -Wall -Wextra -Werror -I libft/includes -c $(SOURCES)
	gcc -o fdf $(OBJECTS) -I libft/includes -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean :
	rm -f  $(OBJECTS)
	make -C libft/ clean

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
