/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bertrmar <bertrmar@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:09:03 by bertrmar          #+#    #+#             */
/*   Updated: 2025/11/25 15:07:41 by bertrmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif_neg(const char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i > 9)
			return (1);
		if (i == 9)
		{
			if (str[9] == '9')
				return (1);
		}
		i++;
	}
	return (0);
}

static int	verif_pos(const char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i > 18)
			return (1);
		if (i == 18)
		{
			if (str[9] == '8' || str[9] == '9')
				return (1);
		}
		i++;
	}
	return (0);
}

static int	verif_possible(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	if (j < 0)
	{
		if (verif_neg(&str[i]))
			return (1);
	}
	if (j > 0)
	{
		if (verif_pos(&str[i]))
			return (1);
	}
	return (0);
}

static int	verif_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str, int *result)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (verif_possible(&str[i]) || verif_num(&str[i]))
		return (1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + (str[i] - '0');
		i++;
	}
	*result *= j;
	return (0);
}
