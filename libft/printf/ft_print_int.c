/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:00:00 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:00:00 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int i)
{
	int	result;

	result = 0;
	if (i == -2147483648)
		return (ft_print_string("-2147483648"));
	if (i < 0)
	{
		result += ft_print_char('-');
		i *= -1;
	}
	if (i > 9)
	{
		result += ft_print_int(i / 10);
		result += ft_print_int(i % 10);
	}
	else
	{
		i += 48;
		result += ft_print_char(i);
	}
	return (result);
}

int	ft_print_u_int(unsigned int i)
{
	int	result;

	result = 0;
	if (i > 9)
	{
		result += ft_print_int(i / 10);
		result += ft_print_int(i % 10);
	}
	else
	{
		i += 48;
		result += ft_print_char(i);
	}
	return (result);
}
