/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:45:38 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/25 06:53:54 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

void	open_window(t_params *params)
{
	double pyth;
	t_mlx *mlx;

	mlx = params->mlx;
	//pyth = pow(params->win_x, 2) + pow(params->win_y, 2);
	//pyth = sqrt(pyth);
	//params->win_x = pyth * 50;
	//params->win_y = pyth * 50;
	//params->loc_x = params->win_x/4;
	//params->loc_y = params->win_y/4 + params->win_y/2;
	//params->alpha = -69.736;
	//params->beta = -45;
	params->win_x = 1920;
	params->win_y = 1080;
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, params->win_x, params->win_y, "test");
	mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, params->win_x, params->win_y);
	mlx->image_add = mlx_get_data_addr(mlx->image_ptr, &params->bpp, &params->size_line, &params->erdian);
	//mlx_loop_hook(mlx->mlx_ptr, draw_extra_line, params);
	mlx_key_hook(mlx->win_ptr, exit_window, params);
    mlx_loop(mlx->mlx_ptr);
}
