/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:38:05 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:04:42 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(char *s, char *find)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = ft_strlen(find);
	while (s[++i])
	{
		j = 0;
		while (find[j] && s[i + j] == find[j])
			j++;
		if (j == len)
			return (&s[i]);
	}
	if (find[0] == '\0')
		return (&s[i]);
	return (NULL);
}
