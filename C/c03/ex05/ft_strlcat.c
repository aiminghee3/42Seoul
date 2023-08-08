/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:41:27 by junhjo            #+#    #+#             */
/*   Updated: 2023/07/29 14:57:02 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	get_leng(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_length;
	unsigned int	src_length;

	i = 0;
	j = 0;
	dest_length = get_leng(dest);
	src_length = get_leng(src);
	if (size == 0)
		return (src_length);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i + j < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	if (dest_length < size)
	{
		return (src_length + dest_length);
	}
	else
		return (src_length + size);
}
