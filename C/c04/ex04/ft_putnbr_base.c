/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:58:36 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/01 17:17:41 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr_base(int nbr, char *base);

void	print_number(char *base, long divisor, long number)
{
	if (number >= divisor)
	{
		print_number(base, divisor, number / divisor);
	}
	write(1, &base[number % divisor], 1);
}

long	get_length(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	return (i);
}

int	check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	length;
	long	temp;

	length = get_length(base);
	temp = nbr;
	if (length <= 1 || !check(base))
		return ;
	if (temp < 0)
	{
		temp *= -1;
		write(1, &"-", 1);
	}
	print_number(base, length, temp);
}
