/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:58:37 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/24 10:53:18 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# define BUTTON_ESC 53
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
#include <stdio.h> // remove

typedef struct  	s_params
{
	
	struct s_mlx	*mlx;
	double			alpha;
	double			beta;
	int				loc_x;
	int				loc_y;
	int				loc_z;
	int				win_x;
	int				win_y;
	int				***coord;
	int				bpp;
	int				size_line;
	int				erdian;
	int				color;
	int				mid_x[2];
	id_t			mid_y[2];
}               	t_params;

typedef struct s_mlx
{
	void		*mlx_ptr;
    void		*win_ptr;
	void		*image_ptr;
	char		*image_add;
}				t_mlx;

typedef struct  s_fdf
{
    char            *line;
    int             x;
    int             y;
    struct s_fdf    *next;
}               t_fdf;

void	rotation_matrices(int *vector3, t_params *params, int *ptr);
void	save_coordinates(t_params *params, t_fdf *elem, int fd);
void	pixel_placement(t_params *params);
t_fdf	*read_file(t_params *params, int fd);
void	free_all(t_params *params, t_fdf *head);
void	free_params(t_params *params);
void	free_fdf(t_fdf *head);
int		exit_window(int key, void *params);
int		open_fd(char *file, int argc);
int		draw_extra_line(void *params);
void	open_window(t_params *params);

#endif
