/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:39:32 by raho              #+#    #+#             */
/*   Updated: 2021/11/26 15:57:48 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	neg;

	i = 0;
	ret = 0;
	neg = 1;
	while ((str[i] < 33 && str[i] > 0) && str[i] != 27)
		i++;
	if (str[i] == '-' && (str[i + 1] > 47 && str[i + 1] < 58))
	{
		neg = neg * -1;
		i++;
	}
	else if (str[i] == '+' && (str[i + 1] > 47 && str[i + 1] < 58))
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	if (ret)
		return (ret * neg);
	else
		return (0);
}
