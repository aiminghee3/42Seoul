/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:24:18 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/08 17:26:29 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

void	get_hexadecimal(unsigned long long word)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (word >= 16)
	{
		get_hexadecimal(word / 16);
	}
	write(1, &hexa[word % 16], 1);
}

void	print_string(unsigned char *word, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (word[i] >= 32 && word[i] <= 126)
			write(1, &word[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_data(unsigned char *word, int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i == 0)
			write(1, ": ", 2);
		else if (i % 2 == 0)
		{
			write(1, " ", 1);
		}
		if (i < size)
		{
			if (word[i] < 16)
				write(1, "0", 1);
			get_hexadecimal((unsigned long long)(word[i]));
		}
		else
			write(1, "  ", 2);
		i++;
	}
	write(1, " ", 1);
	print_string(word, size);
}

void	print_memory(unsigned long long memory)
{
	int					i;
	unsigned long long	temp;

	i = 0;
	temp = memory;
	while (i < 16)
	{
		if (memory < 16)
			write(1, "0", 1);
		memory /= 16;
		i++;
	}
	get_hexadecimal(temp);
}

void	*ft_print_memory(void *addr, unsigned int size)//92
{
	unsigned char	*temp;
	unsigned int	division_size;
	unsigned int	i;

	i = 0;
	temp = addr;
	while (i * 16 < size)
	{
		if (i < size / 16)
			division_size = 16;
		else
			division_size = size % 16;
		print_memory((unsigned long long)temp + (i * 16));
		print_data(temp + (i * 16), division_size);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}

#include "ex12/ft_print_memory.c"
​
int main() {
	// Exercise 12
	char arr[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	if (ft_print_memory(arr, 92) != arr)
		return -1;
	char brr[] = "Chuncheon is better than Seoul! :) ;)";
	ft_print_memory(brr, 38);
	ft_print_memory(brr, 10);
	ft_print_memory(brr, 0);
	for (int i = 13; i < 24; ++i)
		brr[i] = '\0';
	ft_print_memory(brr, 37);
	return 0;
}
