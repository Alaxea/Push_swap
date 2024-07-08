# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astefans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 14:31:45 by astefans          #+#    #+#              #
#    Updated: 2024/06/27 16:32:47 by astefans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -f
NAME = push_swap
SRC = src/operations/*.c \
      src/sorting/*.c \
      src/utils/*.c \
      src/main.c
OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): 
	$(CC) $(CFLAGS) $(SRC) -Iincludes -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re

