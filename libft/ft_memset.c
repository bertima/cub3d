/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:38:05 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:03:24 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mot;

	i = 0;
	mot = (unsigned char *)s;
	while (i < n)
	{
		mot[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// int	main(void)
// {
// 	unsigned char s[] = "Bonjour";
// 	int	c = '*';
// 	size_t	n = 8;

// 	printf("Mine : %s\n", (unsigned char *)ft_memset(s, c, n));
// 	printf("True : %s\n", (unsigned char *)memset(s, c, n));
// 	return (0);
// }
