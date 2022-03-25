/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:45:29 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/25 07:07:28 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void draw_line(int x0, int y0, int x1, int y1, t_params *params)
{
    int		dx, dy, p, x, y, sx, sy, e2, error;

    dx = abs(x1 - x0);
    if (x0 < x1)
        sx = 1;
    else
        sx = -1;
    dy = -abs(y1 - y0);
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    error = dx + dy;
    while (1)
    {
	//	if (((int *)image_add)[x0 + (test1/2) * y0] == '\0')
			((int *)params->mlx->image_add)[x0 + (params->size_line/4) * y0] = params->color;
	//	else
	//		((int *)image_add)[x0 + (test1/2) * y0] = '\0';
        //mlx_pixel_put(params->mlx_ptr, params->win_ptr, x0, y0, 0xffffff);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x0 == x1)
                break;
            error = error + dy;
            x0 = x0 + sx;
        }
        if (e2 <= dx)
        {
            if (y0 == y1)
                break;
            error = error + dx;
            y0 = y0 + sy;
        }
    }
}

static void draw_image(t_params *params)
{
	int	x;
	int	y;
	int	ptr[3];
	int	ptr1[3];
	int	coord[3];
	int	coordi[3];

	y = 0;
	while (params->coord[y])
    {
        x = 0;
        while(params->coord[y][x])
        {
			//params->coord[y][x][2] = 0;
			coord[0] = params->coord[y][x][0] * 25;
			coord[1] = params->coord[y][x][1] * 25;
			coord[2] = params->coord[y][x][2] * 10;
            rotation_matrices(coord, params, ptr);
            if (x > 0)
            {
				coordi[0] = params->coord[y][x - 1][0] * 25;
				coordi[1] = params->coord[y][x - 1][1] * 25;
				coordi[2] = params->coord[y][x - 1][2] * 10;
				rotation_matrices(coordi, params, ptr1);
                draw_line(ptr1[0] + params->loc_x, ptr1[1] + params->loc_y, ptr[0] + params->loc_x, ptr[1] + params->loc_y, params);
            }
            if (y > 0)
            {
				coordi[0] = params->coord[y - 1][x][0] * 25;
				coordi[1] = params->coord[y - 1][x][1] * 25;
				coordi[2] = params->coord[y - 1][x][2] * 10;
				rotation_matrices(coordi, params, ptr1);
                draw_line(ptr1[0] + params->loc_x, ptr1[1] + params->loc_y, ptr[0] + params->loc_x, ptr[1] + params->loc_y, params);
            }
            x++;
        }
        y++;
    }
}

static void midpoint(int *coord1, int *coord2, int *ptr, t_params *params)
{
	ptr[0] = coord1[0] + ((coord2[0] - coord1[0])/2);
	ptr[1] = coord1[1] + ((coord2[1] - coord1[1])/2);
	ptr[2] = coord1[2] + ((coord2[2] - coord1[2])/2);
}

static void coordinates(int x, int y, int z, int x1, int y1, int z1, int *ptr, t_params *params)
{
	int coord1[3];
	int coord2[3];

	coord1[0] = x;
	coord1[1] = y;
	coord1[2] = z;

	coord2[0] = x1;
	coord2[1] = y1;
	coord2[2] = z1;

	midpoint(coord1, coord2, ptr, params);
}

static void copy(int *left, int *right, int x, int y, t_params *params)
{
	left[0] = params->coord[y][x - 1][0] * 25;
	left[1] = params->coord[y][x - 1][1] * 25;
	left[2] = params->coord[y][x - 1][2] * 10;

	right[0] = params->coord[y][x][0] * 25;
	right[1] = params->coord[y][x][1] * 25;
	right[2] = params->coord[y][x][2] * 10;
}

static void ft_middle(int x, int y, int *ptr, t_params *params)
{
	int coord1[3];
	int coord2[3];

	coord1[0] = params->coord[y - 1][x - 1][0] * 25;
	coord1[1] = params->coord[y - 1][x - 1][1] * 25;
	coord1[2] = params->coord[y - 1][x - 1][2] * 10;

	coord2[0] = params->coord[y][x][0] * 25;
	coord2[1] = params->coord[y][x][1] * 25;
	coord2[2] = params->coord[y][x][2] * 10;

	midpoint(coord1, coord2, ptr, params);
}

static void copyints(int *dest1, int *dest2, int *src1, int *src2)
{
	dest1[0] = src1[0];
	dest1[1] = src1[1];
	dest1[2] = src1[2];

	dest2[0] = src2[0];
	dest2[1] = src2[1];
	dest2[2] = src2[2];
}

int * intdup(int const * src, size_t len)
{
   int * p = malloc(len * sizeof(int));
   memcpy(p, src, len * sizeof(int));
   return p;
}

static int recursive_check(int *left, int *right, int *middle, t_params *params)
{
	int midp[3];
	int ptr1[3];
	int *leftptr;
	int *rightptr;
	int *midptr;

	//copyints(left, right, left, right);
	midpoint(left, right, midp, params);
	rotation_matrices(midp, params, ptr1);

	//copyints(midp, 0, midp, 0);

	draw_line(ptr1[0] + params->loc_x, ptr1[1] + params->loc_y, middle[0] + params->loc_x, middle[1] + params->loc_y, params);

	if (midp[0] > left[0] || midp[1] > left[1])
	{
		printf("\n\nleft\n");
		leftptr = intdup(left, 3);
		midptr = intdup(midp, 3);
		recursive_check(leftptr, midptr, middle, params);
		free(midptr);
		free(leftptr);
		//return(recursive_check(intdup(left, 5), intdup(midp, 5), middle, params));
	}
	else
	{
		return (0);
	}
	if (midp[0] < right[0] || midp[1] < right[1])
	{
		rightptr = intdup(right, 3);
		midptr = intdup(midp, 3);
		recursive_check(midptr, rightptr, middle, params);
		free(midptr);
		free(rightptr);
		printf("\n\nright\n");
		//return(recursive_check(intdup(midp, 5), intdup(right, 5), middle, params));
	}
	else
	{
		return (0);
	}
	return (0);
}

static void left_right(int x, int y, t_params *params)
{
	int index;
	int left[3];
	int right[3];
	int mid_l[3];
	int mid_r[3];
	int middle[3];
	int ptr1[3];
	int left2[3];
	int topleft2[3];
	int topright2[3];
	int right2[3];
	index = 25;

	ft_middle(x, y, middle, params);
	copy(left, right, x, y, params);
	rotation_matrices(middle, params, ptr1);
	recursive_check(left, right, ptr1, params);

	left2[0] = params->coord[y][x - 1][0] * 25;
	left2[1] = params->coord[y][x - 1][1] * 25;
	left2[2] = params->coord[y][x - 1][2] * 10;

	topleft2[0] = params->coord[y - 1][x - 1][0] * 25;
	topleft2[1] = params->coord[y - 1][x - 1][1] * 25;
	topleft2[2] = params->coord[y - 1][x - 1][2] * 10;
	recursive_check(topleft2, left2, ptr1, params);

	topright2[0] = params->coord[y - 1][x][0] * 25;
	topright2[1] = params->coord[y - 1][x][1] * 25;
	topright2[2] = params->coord[y - 1][x][2] * 10;

	topleft2[0] = params->coord[y - 1][x - 1][0] * 25;
	topleft2[1] = params->coord[y - 1][x - 1][1] * 25;
	topleft2[2] = params->coord[y - 1][x - 1][2] * 10;
	recursive_check(topleft2, topright2, ptr1, params);

	topright2[0] = params->coord[y - 1][x][0] * 25;
	topright2[1] = params->coord[y - 1][x][1] * 25;
	topright2[2] = params->coord[y - 1][x][2] * 10;

	right2[0] = params->coord[y][x][0] * 25;
	right2[1] = params->coord[y][x][1] * 25;
	right2[2] = params->coord[y][x][2] * 10;
	recursive_check(topright2, right2, ptr1, params);
}
static void fill_image(t_params *params)
{
	int	x;
	int	y;
	int	ptr1[6];
	int	ptr2[6];
	int	ptr3[6];
	int	ptr4[6];
	int	coord1[3];
	int	coord2[3];
	int index = 0;
	int current_x[2];
	int current_y[2];
	while (index < 1)
	{
		y = 0;
		while (params->coord[y])
		{
			x = 0;
			while(params->coord[y][x])
			{
				if (y > 0 && x > 0)
				{
					left_right(x, y, params);
				}
				x++;
			}
			y++;
		}
		index++;
	}
}

void pixel_placement(t_params *params)
{
	params->color = 0;
	fill_image(params);
	params->color = 2147483647;
	draw_image(params);
}

/*
static void midpoint(int *coord1, int *coord2, int *ptr, t_params *params)
{
	int	ptr1[3];
	int	ptr2[3];
	int	coord[3];

	coord[0] = params->coord[y0][x0][0] * 25;
	coord[1] = params->coord[y0][x0][1] * 25;
	coord[2] = params->coord[y0][x0][2] * 10;

	rotation_matrices(coord, params, ptr1);
	
	coord[0] = params->coord[y1][x1][0] * 25;
	coord[1] = params->coord[y1][x1][1] * 25;
	coord[2] = params->coord[y1][x1][2] * 10;

	rotation_matrices(coord, params, ptr2);

	ptr[0] = ptr1[0] + ((ptr2[0] - ptr1[0])/2);
	ptr[1] = ptr1[1] + ((ptr2[1] - ptr1[1])/2);
}
static void midpoint(int *coord1, int *coord2, int *ptr, t_params *params)
{
	int	ptr1[3];
	int	ptr2[3];

	//ptr[3] = coord1[0] + ((coord2[0] - coord1[0])/2);
	//ptr[4] = coord1[1] + ((coord2[1] - coord1[1])/2);
	//ptr[5] = coord1[2] + ((coord2[2] - coord1[2])/2);

	rotation_matrices(coord1, params, ptr1);
	rotation_matrices(coord2, params, ptr2);

	ptr[0] = ptr1[0] + ((ptr2[0] - ptr1[0])/2);
	ptr[1] = ptr1[1] + ((ptr2[1] - ptr1[1])/2);
	ptr[2] = ptr1[2] + ((ptr2[2] - ptr1[2])/2);
}
					coordinates(params->coord[y - 1][x - 1][0] * 25, params->coord[y - 1][x - 1][1] * 25, params->coord[y - 1][x - 1][2] * 10, params->coord[y - 1][x][0] * 25, params->coord[y - 1][x][1] * 25, params->coord[y - 1][x][2] * 10, ptr1, params);
					coordinates(params->coord[y][x - 1][0] * 25, params->coord[y][x - 1][1] * 25, params->coord[y][x - 1][2] * 10, params->coord[y][x][0] * 25, params->coord[y][x][1] * 25, params->coord[y][x][2] * 10, ptr2, params);

					draw_line(ptr1[0] + params->loc_x, ptr1[1] + params->loc_y, ptr2[0] + params->loc_x, ptr2[1] + params->loc_y, params);
					
					coordinates(params->coord[y][x - 1][0] * 25, params->coord[y][x - 1][1] * 25, params->coord[y][x - 1][2] * 10, ptr2[3], ptr2[4], ptr2[5], ptr3, params);
					coordinates(ptr1[3], ptr1[4], ptr1[5], params->coord[y - 1][x][0] * 25, params->coord[y - 1][x][1] * 25, params->coord[y - 1][x][2] * 10, ptr4, params);

					draw_line(ptr3[0] + params->loc_x, ptr3[1] + params->loc_y, ptr4[0] + params->loc_x, ptr4[1] + params->loc_y, params);

					ptr3[0] = ptr1[0];
					ptr3[1] = ptr1[1];
					ptr4[0] = ptr2[0];
					ptr4[1] = ptr2[1];

static void fill_image(t_params *params)
{
	int	x;
	int	y;
	int	ptr1[3];
	int	ptr2[3];
	int	ptr3[3];
	int	ptr4[3];
	int	coord[3];
	int	coordi[3];
	int index = 0;
	int current_x[2];
	int current_y[2];
	while (index < 1)
	{
		y = 0;
		while (params->coord[y])
		{
			x = 0;
			while(params->coord[y][x])
			{
				if (y > 0 && x > 0)
				{
					coord[0] = params->coord[y - 1][x - 1][0] * 25;
					coord[1] = params->coord[y - 1][x - 1][1] * 25;
					coord[2] = params->coord[y - 1][x - 1][2] * 10;

					rotation_matrices(coord, params, ptr1);
					
					coord[0] = params->coord[y - 1][x][0] * 25;
					coord[1] = params->coord[y - 1][x][1] * 25;
					coord[2] = params->coord[y - 1][x][2] * 10;

					rotation_matrices(coord, params, ptr2);

					coord[0] = params->coord[y][x - 1][0] * 25;
					coord[1] = params->coord[y][x - 1][1] * 25;
					coord[2] = params->coord[y][x - 1][2] * 10;

					rotation_matrices(coord, params, ptr3);

					coord[0] = params->coord[y][x][0] * 25;
					coord[1] = params->coord[y][x][1] * 25;
					coord[2] = params->coord[y][x][2] * 10;

					rotation_matrices(coord, params, ptr4);

					current_x[0] =  ptr1[0] + ((ptr2[0] - ptr1[0])/2);
					current_y[0] =	ptr1[1] + ((ptr2[1] - ptr1[1])/2);
	
					current_x[1] = ptr3[0] + ((ptr4[0] - ptr3[0])/2);
					current_y[1] = ptr3[1] + ((ptr4[1] - ptr3[1])/2);

					draw_line(current_x[0] + params->loc_x, current_y[0] + params->loc_y, current_x[1] + params->loc_x, current_y[1] + params->loc_y, params);
				}
				x++;
			}
			y++;
		}
		index++;
	}
}
		x = 0;
			while(params->coord[y][x])
			{
				if (y > 0 && x > 0)
				{
					coord[0] = params->coord[y][x][0] * 25;
					coord[1] = params->coord[y][x][1] * 25;
					coord[2] = params->coord[y][x][2] * 10;

					params->mid_x[0] = params->coord[y - 1][x - 1][0];
					params->mid_y[0] = params->coord[y - 1][x - 1][1];
					params->mid_x[1] = params->coord[y - 1][x][0];
					params->mid_y[1] = params->coord[y - 1][x][1];

					current_x[0] =  params->mid_x[0] + (params->mid_x[1] - params->mid_x[0]/2);
					current_y[0] = params->mid_y[0] + (params->mid_y[1] - params->mid_y[0]/2);

					coord[0] = current_x[0] * 25;
					coord[1] = current_y[0] * 25;
					coord[2] = params->coord[y][x][2] * 10;

					rotation_matrices(coord, params, ptr);

					params->mid_x[0] = params->coord[y][x - 1][0];
					params->mid_y[0] = params->coord[y][x - 1][1];
					params->mid_x[1] = params->coord[y][x][0];
					params->mid_y[1] = params->coord[y][x][1];

					current_x[1] =  params->mid_x[0] + (params->mid_x[1] - params->mid_x[0]/2);
					current_y[1] = params->mid_y[0] + (params->mid_y[1] - params->mid_y[0]/2);

					coordi[0] = current_x[1] * 25;
					coordi[1] = current_y[1] * 25;
					coordi[2] = params->coord[y - 1][x + 1][2] * 10;

					rotation_matrices(coordi, params, ptr1);

					draw_line(ptr1[0] + params->loc_x, ptr1[1] + params->loc_y, ptr[0] + params->loc_x, ptr[1] + params->loc_y, params);
				}
				x++;
					int right_midp[3];
	int left_midp[3];
	int ptr1[3];
	int left_cpy[3];
	int right_cpy[3];


	copyints(left, right, left_cpy, right_cpy);

	midpoint(left_cpy, right_cpy, left_midp, params);
	midpoint(left_cpy, right_cpy, right_midp, params);
	
	rotation_matrices(left_midp, params, ptr1);

	draw_line(ptr1[0] + params->loc_x, ptr1[1] + params->loc_y, middle[0] + params->loc_x, middle[1] + params->loc_y, params);
	
	rotation_matrices(right_midp, params, ptr1);

	draw_line(ptr1[0] + params->loc_x, ptr1[1] + params->loc_y, middle[0] + params->loc_x, middle[1] + params->loc_y, params);

	if (left_midp[0] - 1 > left[0] || left_midp[1] - 1 > left[1])
		return(recursive_check(left, left_midp, middle, params));
		
	else if (right_midp[0] - 1 > right[0] || right_midp[1] - 1 > right[1])
	{
		return(recursive_check(right_midp, right, middle, params));
	}
	else
		return (0);
			}*/