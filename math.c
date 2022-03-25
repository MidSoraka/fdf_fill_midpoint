/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:29:21 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/23 01:37:02 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_matrices(int *vector3, t_params *params, int *ptr)
 {
	int temp_vector3[3];
	double	alpha;
	double	beta;

	alpha = (params->alpha * M_PI) / 180;
	beta = (params->beta * M_PI) / 180;

	temp_vector3[0] = vector3[0];
	temp_vector3[1] = vector3[1];
	temp_vector3[2] = vector3[2];

	ptr[0] = (temp_vector3[0] * 1) + (temp_vector3[1] * 0) + (temp_vector3[2] * 0);
	ptr[1] = (temp_vector3[0] * 0) + (temp_vector3[1] * cos(alpha)) + (temp_vector3[2] * sin(alpha));
	ptr[2] = (temp_vector3[0] * 0) + (temp_vector3[1] * -sin(alpha)) + (temp_vector3[2] * cos(alpha));

	temp_vector3[0] = ptr[0];
	temp_vector3[1] = ptr[1];
	temp_vector3[2] = ptr[2];

	ptr[0] = (temp_vector3[0] * cos(beta)) + (temp_vector3[1] * 0) + (temp_vector3[2] * -sin(beta));
	ptr[2] = (temp_vector3[0] * 0) + (temp_vector3[1] * 1) + (temp_vector3[2] * 0);
	ptr[1] = (temp_vector3[0] * sin(beta)) + (temp_vector3[1] * 0) + (temp_vector3[2] * cos(beta));
}
