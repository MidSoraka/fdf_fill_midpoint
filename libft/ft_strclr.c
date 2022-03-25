/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:56:28 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 21:22:46 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	unsigned long	index;

	index = 0;
	if (s)
	{
		while (s[index])
		{
			((unsigned char *)s)[index] = 0;
			index++;
		}
	}
}
