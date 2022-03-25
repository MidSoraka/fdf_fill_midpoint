/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:54:28 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 21:17:28 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	index;
	char	*new;

	index = 0;
	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (0);
	else
	{
		while (index < size)
		{
			new[index] = 0;
			index++;
		}
		new[index] = '\0';
	}
	return (new);
}
