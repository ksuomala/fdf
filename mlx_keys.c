/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:40:42 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 19:54:36 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_switch(int *switch_projection)
{
	if (*switch_projection == 2)
		*switch_projection = 0;
	else
		*switch_projection += 1;
}

void	ft_zoom(t_map *fdf, int dir)
{
	if (dir && fdf->img->scale * fdf->img->zoom < 282)
		fdf->img->zoom += 0.1;
	else if (fdf->img->zoom * fdf->img->scale >= 3)
		fdf->img->zoom -= 0.1;
}

void	ft_more_keys(int key, t_map *fdf)
{
	if (key == Q)
		fdf->img->amp += 0.01;
	if (key == Z)
		fdf->img->amp -= 0.01;
	if (key == P)
		ft_switch(&fdf->img->pro);
	if (key == R)
		fdf->img->rot_z += 0.03;
	if (key == C)
	{
		if (fdf->img->color_mode == 3)
			fdf->img->color_mode = 0;
		fdf->img->color_mode++;
		ft_toggle_colors(fdf);
	}
}

int		ft_keys(int key, t_map *fdf)
{
	int movement;

	if (fdf->img->scale * fdf->img->zoom > 10)
		movement = 6;
	else
		movement = 12;
	if (key == ESC)
		exit(0);
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

void	ft_keypress(t_map *fdf)
{
	mlx_hook(fdf->win, 2, 0, &ft_keys, fdf);
	mlx_hook(fdf->win, 17, 0, &ft_exit, fdf);
}
