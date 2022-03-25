# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 18:25:17 by raho              #+#    #+#              #
#    Updated: 2022/03/24 14:20:14 by vlaine           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
LIB = libft/libft.a
INCLUDES = libft/
#INCLUDE = /usr/X11/include
#LIBRARIES = /usr/X11/lib
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c math.c pixel_placement.c save_coordinates.c free_all.c copy_file.c \
inputs.c handle_file.c open_window.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) $(LIB) $(INCLUDES)
	$(CC) -I $(INCLUDES) $(LIB) libmlx.dylib $(SRCS) -o $(NAME) -O2 -g

#$(NAME): $(SRCS) $(LIB) $(INCLUDES)
#	$(CC) -I $(INCLUDES) -I $(INCLUDE) $(LIB) -g -L $(LIBRARIES) -lX11 -lmlx -lXext $(SRCS) -o $(NAME)
$(LIB):
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
