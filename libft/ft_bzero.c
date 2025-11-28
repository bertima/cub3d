/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:37:49 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/04 13:00:42 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*mot;

	i = 0;
	mot = (unsigned char *)s;
	while (i < n)
	{
		mot[i] = 0;
		i++;
	}
}
