/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:58:54 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/05 19:38:04 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_ten_queens_puzzle(void);

int	check(int x, int *col)
{
	int	i;
	int	temp;

	i = 0;
	while (i < x)
	{
		temp = col[i] - col[x];
		if (col[i] - col[x] < 0)
			temp *= -1;
		if (col[i] == col[x])
			return (0);
		if (temp == (x - i))
			return (0);
		i++;
	}
	return (1);
}

void	nqueen(int x, int *total, int *col)
{
	int		i;
	char	temp;

	i = 0;
	if (x == 10)
	{
		while (i < 10)
		{
			temp = col[i++] + '0';
			write(1, &temp, 1);
		}
		write(1, "\n", 1);
		*total = *total + 1;
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			col[x] = i;
			if (check (x, col))
				nqueen(x + 1, total, col);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		col[10];
	int		total;

	total = 0;
	nqueen(0, &total, col);
	return (total);
}
