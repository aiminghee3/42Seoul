/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:39:29 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/02 22:10:29 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	to_find(char *base, char find, int check)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (find == base[i])
		{
			if (check == 1)
				return (1);
			else if (check == 0)
				return (i);
		}
		i++;
	}
	return (0);
}

long	ft_atoi(char *str, char *base, int length)
{
	int		i;
	int		count;
	long	number;

	i = 0;
	count = 0;
	number = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' \
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	while (to_find(base, str[i], 1) == 1)
	{
		number = number * length + to_find(base, str[i], 0);
		i++;
	}
	if (count % 2 == 1)
		return (-1 * number);
	else
		return (number);
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

int	check(char *base, char length)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	if (length <= 1)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	long	result;
	long	number;
	int		length;

	i = 0;
	number = 0;
	result = 0;
	length = get_length(base);
	if (check(base, length))
		number = ft_atoi(str, base, length);
	return (number);
}
