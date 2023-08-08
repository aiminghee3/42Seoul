/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:25:11 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/08 20:52:03 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "ft_stock_str.h"

int	ft_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		count;
	char	*dest;

	i = 0;
	count = 0;
	while (str[count] != '\0')
		count++;
	dest = (char *)malloc(sizeof(char) * (count + 1));
	if (!dest)
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*answer;

	i = 0;
	answer = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!answer)
		return (0);
	while (i < ac)
	{
		answer[i].size = ft_length(av[i]);
		answer[i].str = av[i];
		answer[i].copy = ft_strdup(answer[i].str);
		i++;
	}
	answer[i].size = 0;
	answer[i].str = 0;
	answer[i].copy = 0;
	return (answer);
}
