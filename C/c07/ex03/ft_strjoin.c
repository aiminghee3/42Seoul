/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:57:00 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/08 10:45:40 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

char	*ft_strcat(char *dest, char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	if (size == 0)
		dest[0] = '\0';
	return (dest);
}

void	control_str(char *new_str, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		ft_strcat(new_str, strs[i], size);
		ft_strcat(new_str, sep, size);
		i++;
	}
	ft_strcat(new_str, strs[i], size);
}

int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		strs_length;
	int		sep_length;
	char	*new_str;
	int		i;

	i = 0;
	strs_length = 0;
	sep_length = get_length(sep);
	while (i < size)
	{
		strs_length += get_length(strs[i]);
		strs_length += sep_length;
		i++;
	}
	strs_length -= sep_length;
	if (size == 0)
		new_str = (char *)malloc(sizeof(char) * 1);
	else
		new_str = (char *)malloc(sizeof(char) * (strs_length + 1));
	if (new_str == 0)
		return (0);
	new_str[0] = 0;
	control_str(new_str, strs, sep, size);
	return (new_str);
}
