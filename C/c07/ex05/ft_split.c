/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:41:40 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/08 18:06:28 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	**ft_split(char *str, char *charset);

int	check_word(char *charset, char word)
{
	int	is_pass;
	int	j;

	j = -1;
	is_pass = 1;
	while (charset[++j] != '\0')
	{
		if (word == charset[j])
			is_pass = 0;
	}
	return (is_pass);
}

int	get_dimension(int dimension, char *str, char *charset)
{
	int	i;
	int	is_pass;
	int	pre;

	i = -1;
	pre = 0;
	while (str[++i] != '\0')
	{
		is_pass = check_word(charset, str[i]);
		if (is_pass)
		{
			while (check_word(charset, str[i + pre])
				&& str[i + pre] != '\0')
				pre++;
			i = i + pre;
			dimension++;
			is_pass = 0;
			pre = 0;
		}
	}
	return (dimension);
}

void	make_string(char *str, char *charset,
					char **string_height)
{
	int	i;
	int	is_pass;
	int	pre;
	int	k;

	i = -1;
	k = 0;
	while (str[++i] != '\0')
	{
		is_pass = check_word(charset, str[i]);
		if (is_pass)
		{
			while (check_word(charset, str[i + pre]) && str[i + pre] != '\0')
				pre++;
			string_height[k++] = (char *)malloc(sizeof(char) * (pre + 1));
			i = i + pre;
			is_pass = 0;
			pre = 0;
		}
	}
	string_height[k] = (char *)malloc(sizeof(char) * (pre + 1));
}

void	insert_string(char *str, char *charset, char **string_height)
{
	int	i;
	int	height;
	int	pre;
	int	is_pass;

	i = -1;
	pre = 0;
	height = 0;
	while (str[++i] != '\0')
	{
		is_pass = check_word(charset, str[i]);
		if (is_pass)
		{
			while (check_word(charset, str[i + pre]) && str[i + pre] != '\0')
			{
				string_height[height][pre] = str[pre + i];
				pre++;
			}
			string_height[height++][pre] = '\0';
			i = i + pre;
			is_pass = 0;
			pre = 0;
		}
	}
	string_height[height] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**string_height;
	int		dimension;

	dimension = get_dimension(1, str, charset);
	string_height = (char **)malloc(sizeof(char *) * (dimension + 1));
	make_string(str, charset, string_height);
	insert_string(str, charset, string_height);
	string_height[dimension] = 0;
	return (string_height);
}
