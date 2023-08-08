/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:29:31 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/08 20:52:18 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include<unistd.h>

void	ft_show_tab(struct s_stock_str *par);

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_int(int size)
{
	if (size > 10)
		print_int(size / 10);
	write(1, &"0123456789"[size % 10], 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		write(1, par[i].str, get_length(par[i].str));
		write(1, "\n", 1);
		print_int(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, get_length(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}
