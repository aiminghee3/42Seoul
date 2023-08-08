/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:19:57 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/07 17:19:58 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	s1_temp;
	unsigned char	s2_temp;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		s1_temp = s1[i];
		s2_temp = s2[i];
		if (s1_temp > s2_temp || s1_temp < s2_temp)
			return (s1_temp - s2_temp);
		i++;
	}
	s1_temp = s1[i];
	s2_temp = s2[i];
	if (s1_temp == '\0' && s2_temp == '\0')
		return (0);
	else if (s1_temp == '\0')
		return (-1);
	else
		return (1);
	return (0);
}
