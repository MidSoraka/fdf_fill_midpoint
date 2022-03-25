/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:01:32 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 21:26:29 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	index;

	index = 0;
	if (s1 && s2)
	{
		while (s1[index] != '\0')
		{
			if (s1[index] != s2[index])
				return (0);
			index++;
		}
		if (s2[index] != '\0')
			return (0);
		return (1);
	}
	else
		return (0);
}
