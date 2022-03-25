/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:45:20 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/24 09:26:34 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	string_to_number(char *str)
{
	char	*dest;
	int		index;

	index = 0;
	while(ft_isdigit(str[index]) == 1)
		index++;
	dest = ft_strnew(index);
	ft_strncpy(dest, str, index);
	index = ft_atoi(dest);
	return(index);
}

static void	set_coordinates(t_params *params, int x, int y, int z)
{
	params->coord[y][x] = (int *)malloc(sizeof(int) * 3);
	if (params->coord[y][x] == NULL)
	{
		//free all
		exit(0);
	}
	params->coord[y][x][0] = x;
    params->coord[y][x][1] = y;
	params->coord[y][x][2] = z;
}

void	save_coordinates(t_params *params, t_fdf *elem, int fd)
{
	int		x;
	int		y;
	int		index;

	y = 0;
    while (elem)
    {
        x = 0;
		index = 0;
        while (elem->line[index])
        {
			if (ft_isdigit(elem->line[index]) != 1 && elem->line[index] != ' ')
			{
				ft_putendl("error invalid file");
				free_all(params, elem); // fix this
				exit(0);
			}
			if (elem->line[index] != ' ' && (index == 0 || elem->line[index - 1] == ' '))
				set_coordinates(params, x++, y, string_to_number(&elem->line[index]));
            index++;
        }
        y++;
		elem = elem->next;
    }
	params->win_x = x;
	params->win_y = y;
	printf("\nparams x is %d\n params y is %d\n", params->win_x, params->win_y);
}
