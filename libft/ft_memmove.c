/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:21:22 by raho              #+#    #+#             */
/*   Updated: 2021/11/29 17:30:36 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (s1 != 0 || s2 != 0)
	{
		if (s1 < s2)
		{
			while (i < n)
			{
				((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
				i++;
			}
		}
		else
		{
			while (n > 0)
			{
				n--;
				((unsigned char *)s1)[n] = ((unsigned char *)s2)[n];
			}	
		}
	}
	return (s1);
}
