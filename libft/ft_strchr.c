/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:33:38 by raho              #+#    #+#             */
/*   Updated: 2021/11/15 16:11:09 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*ret;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
		{
			ret = (char *)&s[index];
			return (ret);
		}
		index++;
	}
	if ((char)c == '\0')
	{
		ret = (char *)&s[index];
		return (ret);
	}
	return (0);
}
