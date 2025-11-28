/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:38:05 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 13:02:49 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*curent;

	curent = malloc(sizeof(t_list));
	if (!curent)
		return (NULL);
	curent->content = content;
	curent->next = NULL;
	return (curent);
}
