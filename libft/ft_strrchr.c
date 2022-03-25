/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:34:29 by raho              #+#    #+#             */
/*   Updated: 2021/11/15 16:59:43 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*ret;

	index = 0;
	ret = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			ret = (char *)&s[index];
		index++;
	}
	if (ret)
		return (ret);
	if ((char)c == '\0')
	{
		ret = (char *)&s[index];
		return (ret);
	}
	return (0);
}
