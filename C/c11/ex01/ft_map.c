/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:08:32 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/07 14:31:21 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int));

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*answer;
	int	i;

	i = 0;
	answer = (int *)malloc(sizeof(int) * (length));
	while (i < length)
	{
		answer[i] = (*f)(tab[i]);
		i++;
	}
	return (answer);
}
