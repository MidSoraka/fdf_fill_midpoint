/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:00:55 by raho              #+#    #+#             */
/*   Updated: 2022/02/11 11:12:10 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the square root of the given value as float. */

float	ft_sqrtf(float nb)
{
	float	sqrt;
	float	temp;

	sqrt = nb / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = ((nb / temp) + temp) / 2;
	}
	return (sqrt);
}
