/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:02:38 by raho              #+#    #+#             */
/*   Updated: 2022/01/19 13:36:43 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	save_line(char **str, char **line)
{
	int		index;
	char	*temp;

	index = 0;
	while ((*str)[index] != '\0' && (*str)[index] != '\n')
		index++;
	if ((*str)[index] == '\n')
	{
		*line = ft_strsub(*str, 0, index);
		temp = ft_strdup(&((*str)[index + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
		{
			free(*str);
			*str = NULL;
		}
	}
	else
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (1);
}

static int	result(int ret, char **str, char **line)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && *str == NULL)
		return (0);
	return (save_line(str, line));
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*str[4096];
	char		*temp;

	if (fd < 0 || !(line))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		ret = read(fd, buff, BUFF_SIZE);
	}
	return (result(ret, &str[fd], line));
}
