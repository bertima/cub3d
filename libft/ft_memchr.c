/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:38:05 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:02:57 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mot;
	unsigned char	cc;

	i = 0;
	cc = c;
	mot = (unsigned char *)s;
	while (i < n)
	{
		if (mot[i] == cc)
			return ((void *)mot + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	mot1[] = "Grenouille je zonjour";

// 	printf("my function     : %p\n", ft_memchr(mot1,'j', 18));
// 	printf("real function   : %p\n", memchr(mot1, 'j', 18));
// 	return (0);
// }
