/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:57:27 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/07 21:37:44 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(char *src);

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		length;
	char	*send_src;

	i = 0;
	length = get_length(src);
	send_src = (char *)malloc(sizeof(char) * (length + 1));
	if (send_src == 0)
		return (0);
	while (src[i] != '\0')
	{
		send_src[i] = src[i];
		i++;
	}
	send_src[i] = '\0';
	return (send_src);
}
