/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:03:27 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/08 11:48:55 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	i;
	int	*str;

	i = 0;
	if (min >= max)
		return (0);
	str = (int *)malloc(sizeof(int) * (max - min));
	while (i < max - min)
	{
		str[i] = min + i;
		i++;
	}
	return (str);
}
