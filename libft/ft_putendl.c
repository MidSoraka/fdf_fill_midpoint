/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:55:08 by raho              #+#    #+#             */
/*   Updated: 2021/11/29 16:57:45 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int	index;

	index = 0;
	if (s)
	{
		while (s[index] != '\0')
		{
			ft_putchar(s[index]);
			index++;
		}
		ft_putchar('\n');
	}
}
