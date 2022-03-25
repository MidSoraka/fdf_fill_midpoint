/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:16:32 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 19:21:31 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (s1 != 0 || s2 != 0)
	{
		while (n > index)
		{
			((char *)s1)[index] = ((char *)s2)[index];
			index++;
		}
	}
	return (s1);
}
