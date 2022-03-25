/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:10:20 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 22:24:50 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int	index;

	index = 0;
	if (s)
	{
		while (s[index] != '\0')
		{
			ft_putchar_fd(s[index], fd);
			index++;
		}
		ft_putchar_fd('\n', fd);
	}
}
