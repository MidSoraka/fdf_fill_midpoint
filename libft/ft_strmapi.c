/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:00:23 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 22:26:24 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*new;

	index = 0;
	if (s)
	{
		new = ft_strdup(s);
		if (!new)
			return (0);
		while (new[index] != '\0')
		{
			new[index] = (*f)(index, new[index]);
			index++;
		}
		return (new);
	}
	return (0);
}
