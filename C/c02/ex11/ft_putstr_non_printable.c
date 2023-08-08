/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:03:22 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/03 20:26:59 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr_non_printable(char *str);

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	temp;
	char			*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	while (str[i] != '\0')
	{
		temp = str[i];
		if (temp >= 32 && temp <= 126)
			write(1, &temp, 1);
		else
		{
			write(1, &"\\", 1);
			write(1, &hexa[temp / 16], 1);
			write(1, &hexa[temp % 16], 1);
		}
		i++;
	}
}
