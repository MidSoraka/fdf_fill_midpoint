/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:16:58 by raho              #+#    #+#             */
/*   Updated: 2021/12/07 21:28:07 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
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
	return (lst);
}
