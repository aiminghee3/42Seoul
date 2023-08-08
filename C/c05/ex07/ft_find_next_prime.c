/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:46:15 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/07 22:05:26 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_find_next_prime(int nb);

int	is_prime(int nb)
{
	unsigned int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (nb);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	if (nb < 3)
		return (2);
	while (1)
	{
		if (is_prime(nb))
			return (nb);
		nb++;
	}
}

int	main()
{
	printf("answer : %d", ft_find_next_prime(96704));
}
