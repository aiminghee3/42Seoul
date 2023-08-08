# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 17:16:46 by junhjo            #+#    #+#              #
#    Updated: 2023/08/06 17:16:46 by junhjo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Werror -Wall -Wextra -c ft_putchar.c ft_swap.c ft_putstr.c ft_strcmp.c ft_strlen.c
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strcmp.o ft_strlen.o