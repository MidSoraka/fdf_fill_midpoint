/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:48:41 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 22:24:00 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	index;
	void	*ptr;

	index = 0;
	ptr = malloc(size);
	if (!ptr)
		return (0);
	else
	{
		while (index < size)
		{
			((char *)ptr)[index] = 0;
			index++;
		}
	}
	return (ptr);
}
