/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:40:32 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/25 06:54:12 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw_extra_line(void *params)
{
	int test1, test2, test3;
	t_params *local;
	t_mlx *mlx;

	local = ((t_params *)params);
	mlx = local->mlx;
	//local->loc_x = 250;
	//f///local->loc_y = 250;
	bzero(mlx->image_add, local->win_x * local->win_y * sizeof(int));
	pixel_placement(local);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image_ptr, 0, 0);
	return (0);
}

int exit_window(int key, void *params)
{
	t_params *local;
	t_mlx *mlx;

	local = ((t_params *)params);
	mlx = local->mlx;
	if (key == 31)
		local->alpha += 5;
	if (key == 34)
		local->alpha -= 5;
	if (key == 38)
		local->beta -= 5;
	if (key == 40)
		local->beta += 5;
	if (key == 7)
		local->loc_x += 50;
	if (key == 8)
		local->loc_x -= 50;
	if (key == 16)
		local->loc_y += 50;
	if (key == 32)
		local->loc_y -= 50;
	if (key == 15)
	{
		local->loc_x = 0;
		local->loc_y = 0;
		local->alpha = 0;
		local->beta = 0;
	}
	if (key == 53)
		exit(0);
	bzero(mlx->image_add, local->win_x * local->win_y * sizeof(int));
	pixel_placement(local);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image_ptr, 0, 0);
	//printf("\nalpha is %f\nbeta is %f\n", local->alpha, local->beta);
	return (0);
}