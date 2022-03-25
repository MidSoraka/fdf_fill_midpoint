/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:06:28 by raho              #+#    #+#             */
/*   Updated: 2022/01/03 15:28:33 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoafill(int n, int count, char *new)
{
	int	singlenbr;

	new[count] = '\0';
	if (n == -2147483648)
	{
		count--;
		new[count] = 8 + 48;
		n = n / 10;
	}
	if (n < 0)
	{
		new[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		new[0] = 0 + 48;
	while (count > 0 && n != 0)
	{
		count--;
		singlenbr = n;
		new[count] = singlenbr % 10 + 48;
		n = n / 10;
	}
	return (new);
}

static int	ft_nbrlen(int n)
{
	int	calclen;
	int	count;

	calclen = n;
	count = 0;
	if (n == -2147483648)
		count = 11;
	else if (n == 0)
		return (1);
	else
	{
		while (calclen != 0)
		{
			if (calclen < 0)
			{
				calclen = calclen * (-1);
				count++;
			}
			calclen = calclen / 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*new;

	len = ft_nbrlen(n);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (0);
	return (ft_itoafill(n, len, new));
}
