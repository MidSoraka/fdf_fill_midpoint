/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:34:00 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/24 10:10:34 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*new_list(t_fdf *head)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf));
	if (new == NULL)
	{
		free_fdf(head);
		exit (0);
	}
	new->next = NULL;
	return (new);
}

static void		malloc_coordinates(t_params *params, t_fdf *head)
{
	t_fdf	*elem;
	int		index;
	int		x;
	int		y;

	elem = head;
	y = 0;
	while (elem)
	{
        index = 0;
        x = 0;
        while (elem->line[index])
        {
            if (index > 0)
                if ((elem->line[index - 1] != ' ' && elem->line[index] == ' ') || elem->line[index + 1] == '\0')
                    x++;
            index++;
        }
        params->coord[y] = (int **)malloc((x + 1) * sizeof(int *));
        params->coord[y][x] = NULL;
        y++;
        elem = elem->next;
	}
}

t_fdf	*read_file(t_params *params, int fd)
{
	t_fdf	*head;
	t_fdf	*elem;
	char	*line;
	int		gnl;
	int		index;

	index = 0;
	head = new_list(NULL);
	elem = head;
	gnl = 1;
	params->erdian = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		if (gnl > 0)
		{
			if (params->erdian != 1)
			{
				elem->next = new_list(head);
				elem = elem->next;
			}
			elem->line = ft_strnew(ft_strlen(line));
			ft_strcpy(elem->line, line);
			//memcpy(elem->line, line, ft_strlen(line));
			params->erdian = 0;
			free(line);
		}
		printf("index is %d\n", index);
		index++;
	}
	params->coord = (int ***)malloc((index + 1) * sizeof(int **));
	params->coord[index] = NULL;
	malloc_coordinates(params, head);
	return(head);
}

/*
index = 0;
	head = new_list(NULL);
	elem = head;
	gnl = get_next_line(fd, &elem->line);
	params->loc_x = ft_strlen(elem->line);
	while (gnl > 0)
	{
		elem->next = new_list(elem);
		elem = elem->next;
		gnl = get_next_line(fd, &elem->line);
		printf("index is %d\n", index++);
		//if (elem->line && params->loc_x != ft_strlen(elem->line))
		{
		//	ft_putendl("error lines dont match in length");
			//free
		//	exit(0);
		//}
	}
*/
