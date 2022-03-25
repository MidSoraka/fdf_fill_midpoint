/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:18:43 by raho              #+#    #+#             */
/*   Updated: 2022/02/17 17:25:13 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (n > index)
	{
		if (((unsigned char *)s2)[index] == (unsigned char)c)
		{
			((unsigned char *)s1)[index] = ((unsigned char *)s2)[index];
			return ((unsigned char *)(s1 + index + 1));
		}
		else
			((unsigned char *)s1)[index] = ((unsigned char *)s2)[index];
		index++;
	}
	return (0);
}
