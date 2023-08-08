/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:31:00 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/02 11:19:26 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	temp;

	temp = nb;
	i = 0;
	if (power == 0 || nb == 1)
		return (1);
	else if (power < 0 || nb == 0)
		return (0);
	while (power > 1)
	{
		nb = nb * temp;
		power--;
	}
	return (nb);
}
