/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:02:26 by raho              #+#    #+#             */
/*   Updated: 2022/01/03 15:29:59 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (s1 && s2)
	{
		while (index < n && s1[index] != '\0')
		{
			if (s1[index] != s2[index])
				return (0);
			index++;
		}
		if (index == n)
			return (1);
		if (s2[index] != '\0')
			return (0);
		return (1);
	}
	else
		return (0);
}
