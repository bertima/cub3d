/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:59:53 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 12:59:53 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_hexa(int i, char c)
{
	char	letter;

	if (i < 10)
	{
		letter = i + '0';
		write(1, &letter, 1);
	}
	else
	{
		if (c == 'x')
			letter = (i + 'a') - 10;
		else if (c == 'X')
			letter = (i + 'A') - 10;
		write(1, &letter, 1);
	}
}

int	ft_print_hexa(int i, char c)
{
	unsigned int	temp[16];
	unsigned int	count;
	unsigned int	n;
	int				result;

	n = (unsigned int)i;
	count = 0;
	if (n == 0)
		return (ft_print_char('0'));
	while (n > 0)
	{
		temp[count] = n % 16;
		n /= 16;
		count++;
	}
	result = count;
	while (count-- > 0)
		ft_write_hexa(temp[count], c);
	return (result);
}

// int		main(void)
// {
// 	ft_print_hexa(0, 'x');
// 	write(1, "\n", 1);
// 	ft_print_hexa(255, 'X');
// 	write(1, "\n", 1);
// 	ft_print_hexa(42, 'x');
// 	return (0);
// }
