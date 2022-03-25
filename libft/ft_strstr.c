/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:35:24 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 22:22:45 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_find(int h, int i, const char *s1, const char *s2)
{
	int		j;
	char	*ret;

	j = 0;
	while (s1[h] != '\0')
	{
		if (s1[h + j] == s2[i])
		{
			if (i == 0)
				ret = (char *)&s1[h];
			i++;
			j++;
			if (s2[i] == '\0')
				return (ret);
		}
		else
		{
			i = 0;
			j = 0;
			h++;
		}
	}
	return (0);
}

char	*ft_strstr(const char *s1, const char *s2)
{
	if (*s2 == '\0')
		return ((char *)s1);
	return (ft_find(0, 0, s1, s2));
}
