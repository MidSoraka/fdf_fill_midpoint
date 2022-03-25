/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:00:57 by raho              #+#    #+#             */
/*   Updated: 2022/02/17 17:17:19 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlennows(const char *s)
{
	int		i;
	int		lead;
	int		trail;

	i = 0;
	trail = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	lead = i;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			i++;
			trail = i;
		}
		else
			i++;
	}
	if (trail != 0)
		return (trail - lead);
	return (0);
}

static char	*ft_strcpynows(char const *s, char *new)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			max = i;
		i++;
	}
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0' && i <= max)
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s)
{
	char	*new;

	if (s)
	{
		new = (char *)malloc(sizeof(char) * (ft_strlennows(s) + 1));
		if (!new)
			return (0);
		return (ft_strcpynows(s, new));
	}
	return (0);
}
