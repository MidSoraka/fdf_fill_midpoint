/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:14:46 by raho              #+#    #+#             */
/*   Updated: 2021/12/07 20:48:09 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*next;

	temp = *alst;
	next = 0;
	if (alst)
	{
		while (temp)
		{
			next = temp->next;
			(*del)(temp->content, temp->content_size);
			free(temp);
			temp = next;
		}
		*alst = 0;
	}
}
