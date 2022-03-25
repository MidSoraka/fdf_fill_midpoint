/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:26:14 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 20:52:15 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*new;

	index = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!new)
		return (0);
	while (s1[index] != '\0')
	{
		new[index] = s1[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
