/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:15:50 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/07 18:52:26 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int));

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	down;
	int	up;

	i = 0;
	down = 0;
	up = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			down++;
		else if (f(tab[i], tab[i + 1]) < 0)
			up++;
		i++;
	}
	if (up == length - 1 || down == length - 1)
		return (1);
	else
		return (0);
}
