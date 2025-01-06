# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emorillo <emorillo@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 12:52:21 by emorillo          #+#    #+#              #
#    Updated: 2025/01/06 20:01:01 by emorillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

OBJS = $(SRC:c=.o)

INCLUDES = get_next_line.h

all: $(NAME)

$NAME: $(OBJS)
	ar - rcs $(NAME) $(OBJS)

%o.: %.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o$@

clean:
	@rm -rf $(OBJS)

fclean: clean
@rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re
