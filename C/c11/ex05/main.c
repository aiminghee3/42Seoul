/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjo <junhjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:30:25 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/08 10:35:03 by junhjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(long number)
{
	if (number > 9)
		ft_putnbr(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

int	calculate(int left, char operator, int right)
{
	if (operator == '+')
		return (left + right);
	else if (operator == '-')
		return (left - right);
	else if (operator == '*')
		return (left * right);
	else if (operator == '/')
		return (left / right);
	else if (operator == '%')
		return (left % right);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result *= sign;
	return (result);
}

int	check_zero(char operator, int right)
{
	if (operator == '/' && right == 0)
	{
		ft_putstr("Stop : division by zero");
		return (-1);
	}
	else if (operator == '%' && right == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (-1);
	}
	if (operator == '+' || operator == '-' || operator == '/' || \
		operator == '%' || operator == '*')
		return (1);
	return (0);
}

void	do_op(char *left, char *operator, char *right)
{
	int	left_number;
	int	right_number;
	int	result;
	int	is_pass;

	left_number = ft_atoi(left);
	right_number = ft_atoi(right);
	result = 0;
	is_pass = check_zero(operator[0], right_number);
	if (is_pass)
		result = calculate(left_number, operator[0], right_number);
	if (result < 0)
	{
		write(1, "-", 1);
		result *= -1;
	}
	else if (result == 0 && is_pass != -1)
		write(1, "0", 1);
	else if (is_pass != -1)
		ft_putnbr(result);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	//if (argc == 4)
		//do_op(argv[1], argv[2], argv[3]);
		do_op("1", "+", "1");
		do_op("42amis", "-", "--+-20toto12");
		do_op("1", "p", "1");
		do_op("1", "+", "toto3");
		do_op("toto3", "+", "4");
		do_op("foo", "plus", "bar");
		do_op("25", "/", "0");
		do_op("25", "%", "0");
}
