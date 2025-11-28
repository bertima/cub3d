/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:45:31 by gcauchy           #+#    #+#             */
/*   Updated: 2025/11/04 13:02:23 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		current = *lst;
		*lst = current->next;
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
