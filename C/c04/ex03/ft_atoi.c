/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:34:18 by junhjo            #+#    #+#             */
/*   Updated: 2023/07/30 18:01:38 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	int		i;
	int		count;
	int		number;
	long	temp;

	i = 0;
	count = 0;
	number = 0;
	temp = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' \
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		temp = temp * 10 + (str[i++] - '0');
	number = temp;
	if (count % 2 == 1)
		return (-1 * number);
	else
		return (number);
}
