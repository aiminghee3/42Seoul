/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:41:40 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/08 12:54:23 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

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

int	get_dimension(int dimension, int cnt, char *str, char *charset)
{
	int	i;
	int	is_pass;

	i = -1;
	while (str[++i] != '\0')
	{
		is_pass = check_word(charset, str[i]);
		if (!is_pass && i == 0)
			dimension -= 1;
		if (is_pass)
			cnt++;
		else if (cnt != 0)
		{
			cnt = 0;
			dimension++;
		}
	}
	if (cnt != 0)
		dimension++;
	return (dimension);
}

int	set_dimension(int dimension, char *str, char *charset)
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

void	make(char *str, char *charset,
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
			string_height[k++] = (char *)malloc(sizeof(char) * (pre));
			i = i + pre;
			is_pass = 0;
			pre = 0;
		}
	}
	string_height[k] = (char *)malloc(sizeof(char) * (pre));
}

void	insert(char *str, char *charset, char **string_height)
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

void	make_string(char *str, char *charset,
					char **string_height)
{
	int	i;
	int	is_pass;
	int	cnt;
	int	k;

	i = -1;
	k = 0;
	cnt = 0;
	while (str[++i] != '\0')
	{
		is_pass = check_word(charset, str[i]);
		if (is_pass)
			cnt++;
		else if (cnt != 0)
		{
			string_height[k++] = (char *)malloc(sizeof(char) * (cnt + 1));
			cnt = 0;
		}
	}
	string_height[k] = (char *)malloc(sizeof(char) * (cnt + 1));
}

void	insert_string(char *str, char *charset, char **string_height, int cnt)
{
	int	i;
	int	height;
	int	width;
	int	is_pass;

	i = -1;
	width = 0;
	height = 0;
	while (str[++i] != '\0')
	{
		is_pass = check_word(charset, str[i]);
		if (is_pass)
		{
			string_height[height][width++] = str[i];
			cnt++;
		}
		else if (cnt != 0)
		{
			string_height[height++][width] = '\0';
			width = 0;
			cnt = 0;
		}
	}
	string_height[height] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**string_height;
	int		dimension;

	dimension = set_dimension(1, str, charset);
	//printf("dimension : %d\n", dimension);
	string_height = (char **)malloc(sizeof(char *) * (dimension + 1));
	make(str, charset, string_height);
	insert(str, charset, string_height);
	string_height[dimension] = 0;
	return (string_height);
}

int	main(void)
{
	printf("-ex05_test_case-\n\n");
    char *str6 = "How are you";
    char *charset1 = " ";
    char **aaa;
    aaa = ft_split(str6, charset1);
	printf("input str : 'How are you' | charset : ' '\n\n");
	for(int j = 0;aaa[j];j++)
		printf("%d : %s\n", (j + 1), aaa[j]);

	printf("\n");

	char *str7 = "@#sk lakw mwa#lsm ma@la";
	char *charset2 = "@#";

	char **r;
	r = ft_split(str7, charset2);
	printf("input str : '@#sk lakw mwa#lsm ma@la' | charset : '@#'\n\n");
	for(int j = 0;r[j];j++)
		printf("%d : %s\n", (j + 1), r[j]);

	printf("\n");
	char *str8 = "@sk lakw mwa#lsm ma@la#";
	char *charset3 = "#";
	char **pp;
	pp = ft_split(str8, charset3);
	printf("input str : '@sk lakw mwa#lsm ma@la#' | charset : '#'\n\n");
	for(int j = 0;pp[j];j++)
		printf("%d : %s\n", (j + 1), pp[j]);

	printf("\n");

	printf("\n\n------------------------------\n\n");

	char **p;

	p = ft_split("The Quick Brown Fox Jumps Over The Lazy Dog", "");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split("The Quick Brown Fox Jumps Over The Lazy Dog", " ");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split(" The Quick Brown Fox Jumps Over The Lazy Dog ", " ");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split("   The   Quick   Brown   Fox   Jumps   Over   The   Lazy   Dog   ", " ");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split("$*$The$Quick*Brown$*Fox$$Jumps**Over*$The***Lazy$$$Dog*$$$*", "$*");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	p = ft_split("0123456789The0123456789Quick0123456789Brown0123456789Fox0123456789Jumps0123456789Over0123456789The0123456789Lazy0123456789Dog0123456789", "0123456789");
	for (int i = 0; p[i]; ++i)
		printf("\"%s\", ", p[i]);
	printf("\n");

	printf("\n\n------------------------------\n\n");



	return 0;
}

/*
ex05_test_case-
input str : 'How are you' | charset : ' '
1 : How
2 : are
3 : you
input str : '@#sk lakw mwa#lsm ma@la' | charset : '@#'
1 : sk lakw mwa
2 : lsm ma
3 : la
input str : '@sk lakw mwa#lsm ma@la#' | charset : '#'
1 : @sk lakw mwa
2 : lsm ma@la
*/
