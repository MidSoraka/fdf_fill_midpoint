/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:16:06 by raho              #+#    #+#             */
/*   Updated: 2021/12/07 20:50:42 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*next;

	temp = lst;
	next = 0;
	if (lst)
	{
		while (temp)
		{
			next = temp->next;
			(*f)(temp);
			temp = next;
		}
	}
}
