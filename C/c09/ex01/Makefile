# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 10:41:42 by junhjo            #+#    #+#              #
#    Updated: 2023/08/08 10:42:30 by junhjo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INC = includes

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar -cr $@ $^
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
