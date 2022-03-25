/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:05:46 by raho              #+#    #+#             */
/*   Updated: 2022/01/05 19:29:42 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcountdelim(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_splt(char const *s, char c, int i, int j)
{
	int	strcount;
	int	chrcount;

	strcount = 0;
	chrcount = 0;
	while (s[j] != '\0')
	{
		if (s[j] == c && (s[j + 1] != c && s[j + 1] != '\0'))
		{
			strcount++;
			j++;
		}
		if (strcount == i)
		{
			while (s[j] != c && s[j] != '\0')
			{
				chrcount++;
				j++;
			}
			return (chrcount);
		}
		j++;
	}
	return (0);
}

static char	**ft_strfill(char const *s, char c, char **new)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[k] != '\0')
	{
		if (s[k] != c)
		{
			j = 0;
			while (s[k] != c && s[k] != '\0')
			{
				new[i][j] = s[k];
				j++;
				k++;
			}
			new[i][j] = '\0';
			i++;
		}
		else
			k++;
	}
	new[i] = 0;
	return (new);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**new;
	int		strcount;

	i = 0;
	if (s)
	{
		while (*s == c)
			s++;
		if (s == (void *)0)
			return (0);
		strcount = ft_strcountdelim(s, c);
		new = (char **)malloc(sizeof(char *) * strcount + 1);
		if (!new)
			return (0);
		while (i < strcount)
		{
			new[i] = (char *)malloc(sizeof(char) * (ft_splt(s, c, i, 0) + 1));
			if (!new[i])
				return (0);
			i++;
		}
		return (ft_strfill(s, c, new));
	}	
	return (0);
}
