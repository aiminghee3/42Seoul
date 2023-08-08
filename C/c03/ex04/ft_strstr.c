/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:54:00 by junhjo            #+#    #+#             */
/*   Updated: 2023/07/29 18:47:48 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			count = 0;
			while (to_find[j] != '\0')
			{
				if (str[i + j] != to_find[j])
					count++;
				j++;
			}
			if (count == 0)
				return (&str[i]);
		}
		i++;
	}
	if (to_find[0] == '\0')
		return (str);
	return (0);
}
