/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:38:05 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:04:30 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

// #include <stdio.h>

// size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// int main(void)
// {
//     char dest[10];
//     size_t ret = ft_strlcpy(dest, "HelloWorld", sizeof(dest));
//     printf("dest = '%s', ret = %zu\n", dest, ret);
//     return 0;
// }
