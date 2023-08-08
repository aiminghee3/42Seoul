/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:31:33 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/01 18:26:01 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putbnr(int nb);
int		count_string(int number);
void	ft_putnbr(int nb);	

int	count_string(int number)
{
	int	count;

	count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

void	print_number(int number)
{
	char	result;
	int		length;
	int		temp;

	length = count_string(number);
	temp = 1;
	while (length > 1)
	{
		temp *= 10;
		length--;
	}
	while (temp != 0)
	{
		result = (number / temp) + '0';
		write(1, &result, 1);
		number %= temp;
		temp /= 10;
	}
}

void	ft_putnbr(int nb)
{	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb > 0)
	{
		print_number(nb);
	}
	else if (nb == 0)
	{
		write(1, &"0", 1);
	}
	else
	{
		write(1, &"-", 1);
		print_number(nb * -1);
	}
}	
