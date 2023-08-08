/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojunhui <jojunhui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:55:02 by jojunhui          #+#    #+#             */
/*   Updated: 2023/08/08 02:01:53 by jojunhui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
	if (operator == '+' || operator == '-' || operator == '/' || operator == '%' || operator == '*')
		return (1);
	return (0);
}

void	do_op(char *left, char *operator, char *right)
{
	int left_number;
	int right_number;
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
