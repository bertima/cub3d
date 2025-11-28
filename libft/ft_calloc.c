/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:53:29 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/04 13:00:51 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mot;
	size_t	total;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX / size) && size != 0)
		return (NULL);
	total = (nmemb * size);
	mot = (char *)malloc(total);
	if (!mot)
		return (NULL);
	ft_memset(mot, 0, total);
	return (mot);
}
