/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:40:42 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/03 04:55:20 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_rotate_z(float *x, float *y, float angle)
// {
// 	float i;
// 	i = sqrt(-1.0);
// 	*x = *x * cos(angle) - sin(angle);
// 	*y = *y * cos(angle) + sin(angle);
// }

void	ft_switch(int *switch_projection)
{
	if (*switch_projection == 2)
		*switch_projection = 0;
	else
		*switch_projection += 1;
}

void	ft_zoom(t_map *fdf, int dir)
{
	if (dir)
	{
		if (fdf->img->scale < 282)
			fdf->img->scale += 3;
	}
	else
	{
		fdf->img->scale -= 3;
	}
	if (fdf->img->scale <= 3)
		fdf->img->scale = 1;
}

void	ft_more_keys(int key, t_map *fdf)
{
	if (key == Q)
		fdf->img->amp += 0.01;
	if (key == Z)
		fdf->img->amp -= 0.01;
	if (key == P)
		ft_switch(&fdf->img->pro);
	if (key == Y)
		fdf->img->rot_y += 0.03;
	if (key == R)
		fdf->img->rot_z += 0.03;
	if (key == T)
		fdf->img->rot_x += 0.03;
	//	ft_change_rotation(fdf);
	//	ft_printf("scale = %d, height = %d, width = %d", fdf->img->scale, fdf->img->height, fdf->img->width);
}

int		ft_keys(int key, t_map *fdf)
{
	int movement;

	if (fdf->img->scale > 10)
		movement = 1;
	else
		movement = 2;
	if (key == ESC)
	{
		ft_printf("you pressed ESC\n");
		exit (0);
	}
	else if (key == A_LEFT)
		fdf->img->move_x -= movement;
	else if (key == A_RIGHT)
		fdf->img->move_x += movement;
	else if (key == A_UP)
		fdf->img->move_y -= movement;
	else if (key == A_DOWN)
		fdf->img->move_y += movement;
	else if (key == PLUS)
		ft_zoom(fdf, 1);
	else if (key == MINUS)
		ft_zoom(fdf, 0);
	else
		ft_more_keys(key, fdf);
	ft_draw_image(fdf);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}

void	ft_keypress(t_map *fdf)
{
	mlx_hook(fdf->win, 2, 0, &ft_keys, fdf);
	mlx_hook(fdf->win, 17, 0, &ft_exit, fdf);
}

void	ft_init_window(t_map *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, "mlx_window");
	if (!fdf->img)
		fdf->img = ft_memalloc(sizeof(t_bitmap));
	ft_set_scale(fdf, fdf->img);
	if (!fdf->img->ptr)
		fdf->img->ptr = mlx_new_image(fdf->mlx, WIN_X, WIN_Y);
	if (!fdf->img->b_map)
		fdf->img->b_map = (int*)mlx_get_data_addr(fdf->img->ptr, &fdf->img->bpp, &fdf->img->size_l, &fdf->img->endian);
	fdf->img->size_l /= 4;
}

// void	ft_change_rotation(t_map *fdf)
// {
// 	int x = 0;
// 	int y = 0;

// 	while (y < fdf->end_y)
// 	{
// 		while (x < fdf->end_x)
// 		{
// 			ft_rotate_z(&fdf->map[y][x].x, &fdf->map[y][x].y, fdf->img->rot);
// 			x++;
// 		}
// 		y++;
// 		x = 0;
// 	}
// }