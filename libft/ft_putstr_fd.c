/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:09:38 by raho              #+#    #+#             */
/*   Updated: 2021/11/24 22:25:09 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
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
	}
}
