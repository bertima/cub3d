/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:38:05 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:04:38 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mot;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	mot = malloc(sizeof(char) * (i + 1));
	if (!mot)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mot[i] = f(i, s[i]);
		i++;
	}
	mot[i] = '\0';
	return (mot);
}
