/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:03:21 by raho              #+#    #+#             */
/*   Updated: 2021/11/25 01:23:43 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*new;

	index = 0;
	if (s)
	{
		new = (char *)malloc(sizeof(char) * len + 1);
		if (!new)
			return (0);
		while (index < len)
		{
			new[index] = s[start];
			index++;
			start++;
		}
		new[index] = '\0';
		return (new);
	}
	return (0);
}
