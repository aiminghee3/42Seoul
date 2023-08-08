/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:26:28 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/06 12:20:21 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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
}

void	print(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			j = i + 1;
			while (j < argc)
			{
				if (ft_strcmp(argv[i], argv[j]) > 0)
				{
					temp = argv[j];
					argv[j] = argv[i];
					argv[i] = temp;
				}
				j++;
			}
			i++;
		}
		print(argc, argv);
	}
}
