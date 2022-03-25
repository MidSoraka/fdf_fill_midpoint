/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:16:12 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/24 09:52:27 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    int			fd;
	t_params	*params;
	void		*ptr;

	params = malloc(sizeof(t_params));
	if (params == NULL)
		exit(0);
	ft_bzero(params, sizeof(t_params));
	params->mlx = malloc(sizeof(t_mlx));
	if (params->mlx == NULL)
	{
		free_params(params);
		exit(0);
	}
	ft_bzero(params->mlx, sizeof(t_mlx));
	ptr = params;
    fd = open_fd(argv[1], argc);
    save_coordinates(params, read_file(params, fd), fd);
	open_window(params);
	return(0);
}
