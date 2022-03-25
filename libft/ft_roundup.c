/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:56:17 by raho              #+#    #+#             */
/*   Updated: 2022/02/11 11:09:17 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Rounds up the given variable float or double and returns it as int. */

int	ft_roundup(double nb)
{
	return (nb + 0.999999999999999);
}
