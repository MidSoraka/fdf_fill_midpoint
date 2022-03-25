/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:59:24 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 21:24:51 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			new[index] = f(new[index]);
			index++;
		}
		return (new);
	}
	else
		return (0);
}
