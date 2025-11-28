/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:38:05 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:03:04 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s;
	const char	*d;

	i = 0;
	s = s1;
	d = s2;
	while (i < n)
	{
		if (s[i] != d[i])
			return ((unsigned char)s[i] - (unsigned char)d[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int	main (void)
// {
// 	unsigned char s[] = "Bonjour";
// 	unsigned char d[] = "BonJour";
// 	size_t	n = 0;

// 	printf("%d\n", ft_memcmp(s, d, n));
// 	printf("%d\n", memcmp(s, d, n));
// }
