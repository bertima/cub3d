/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:00:29 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:00:32 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_printf(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}
