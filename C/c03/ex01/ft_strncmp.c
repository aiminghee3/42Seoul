/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:33:29 by junhjo            #+#    #+#             */
/*   Updated: 2023/07/29 16:52:26 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	s1_temp;
	unsigned char	s2_temp;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		s1_temp = s1[i];
		s2_temp = s2[i];
		if (s1_temp > s2_temp || s1_temp < s2_temp)
		{
			return (s1_temp - s2_temp);
		}
		i++;
	}
	s1_temp = s1[i];
	s2_temp = s2[i];
	if (i < n)
	{
		if (s1_temp == '\0' && s2_temp != '\0')
			return (s1_temp - s2_temp);
		else if (s1_temp != '\0' && s2_temp == '\0')
			return (s1_temp - s2_temp);
	}
	return (0);
}
