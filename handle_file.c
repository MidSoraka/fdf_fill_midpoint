/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:39:26 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/17 17:50:20 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_fd(char *file, int argc)
{
    int	fd;

	if (argc != 2)
    {
        ft_putendl("usage ./fdf matrix_file");
        return (0);
    }
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		exit (0);
	}
    return (fd);
}