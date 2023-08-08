/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:12:40 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/02 21:48:27 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

int	change_first(char *str)
{
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] = str[0] - 32;
		return (1);
	}
	return (0);
}

void	change_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	change_alpha(str);
	if (change_first(str))
		count = 1;
	while (str[i++] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i - 1] >= '0' && str[i - 1] <= '9')
				count++;
			if (count == 0)
				str[i] = str[i] - 32;
			count++;
		}
		else
			count = 0;
	}
	return (str);
}
