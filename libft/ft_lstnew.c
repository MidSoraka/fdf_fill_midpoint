/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:57:58 by raho              #+#    #+#             */
/*   Updated: 2022/01/03 15:27:40 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cpycontent(t_list *new, void const *content, size_t content_size)
{
	size_t	i;

	i = 0;
	new->content = malloc(content_size);
	if (new->content == 0)
		return (0);
	while (i < content_size)
	{
		*(char *)(new->content + i) = *(char *)(content + i);
		i++;
	}
	new->content_size = content_size;
	return (1);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;
	int			ret;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	if (content)
	{
		ret = ft_cpycontent(new, content, content_size);
		if (!ret)
		{
			free(new);
			return (0);
		}
	}
	else
	{
		new->content = 0;
		new->content_size = 0;
	}
	new->next = 0;
	return (new);
}
