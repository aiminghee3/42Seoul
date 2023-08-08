/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojunhui <jojunhui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:28:33 by junhjo            #+#    #+#             */
/*   Updated: 2023/08/08 02:01:17 by jojunhui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
