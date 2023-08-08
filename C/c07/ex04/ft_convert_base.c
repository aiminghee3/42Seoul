/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:34:11 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/07 21:49:57 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		base2_find(char *base, char find, int check);
long	base2_atoi(char *str, char *base, int length);
long	get_base2_length(char *base);
int		base2_check(char *base, char length);
int		ft_convert_base2(char *str, char *base);

void	print_number(char *base, long divisor, long number, char *hex_string)
{
	int		i;

	i = 0;
	if (number < 0)
		number *= -1;
	while (number >= divisor)
	{
		hex_string[i] = base[number % divisor];
		number /= divisor;
		i++;
	}
	hex_string[i++] = base[number % divisor];
	hex_string[i] = '\0';
}

void	insert_minus(char *hex_string, long number)
{
	int		i;
	int		start;
	int		end;
	char	temp;

	i = 0;
	while (hex_string[i] != '\0')
		i++;
	if (number < 0)
	{
		hex_string[i++] = '-';
		hex_string[i] = '\0';
	}
	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = hex_string[start];
		hex_string[start++] = hex_string[end];
		hex_string[end--] = temp;
	}
}

long	get_length(char *base)
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
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] < 32 || base[i] > 126 || base[i] == ' ')
			return (0);
		i++;
	}
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	hex_string[33];
	char	*return_string;
	long	length;
	int		number;

	number = ft_convert_base2(nbr, base_from);
	length = get_length(base_to);
	if (length <= 1 || number == -1)
		return (0);
	print_number(base_to, length, (long)number, hex_string);
	insert_minus(hex_string, (long)number);
	return_string = (char *)malloc(sizeof(char) * (get_length(hex_string) + 1));
	if (!return_string)
		return (0);
	ft_strcpy(return_string, hex_string);
	return (return_string);
}
