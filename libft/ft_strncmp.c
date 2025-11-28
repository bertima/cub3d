/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:38:05 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:04:45 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n && ((s1[i] == 0 && s2[i]) || (s1[i] && s2[i] == 0)))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_strncmp("abcdef", "abcxx", 4));
// 	printf("%d\n", strncmp("abcdef", "abcxx", 4));
// }
