/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:09:38 by raho              #+#    #+#             */
/*   Updated: 2021/11/09 19:06:50 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	int	index;

	index = 0;
	while (n > 0)
	{
		((unsigned char *)b)[index] = (unsigned char)c;
		index++;
		n--;
	}
	return (b);
}
