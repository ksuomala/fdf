/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:51:28 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 02:04:32 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		ft_putpixel(int x, int y, t_bitmap *map, int color)
{
	int i;
	int mid_y;
	int mid_x;

	mid_y = map->mid_y + map->move_y + y;
	mid_x = map->mid_x + map->move_x + x;
	if (mid_y < 0 || mid_y >= WIN_Y || mid_x < 0 || mid_x >= WIN_X)
		return ;
	i = map->size_l * mid_y + mid_x;
	map->b_map[i] = color;
}

void		ft_drawline(t_pt start, t_pt end, t_bitmap *map)
{
	int		i;
	int		color;
	float	dx;
	float	dy;
	float	step;

	ft_multiply_zoom(&start, &end, map->zoom);
	dx = (end.x - start.x);
	dy = (end.y - start.y);
	step = ((fabsf(dx) >= fabsf(dy)) ? fabsf(dx) : fabsf(dy));
	dx = dx / step;
	dy = dy / step;
	i = 1;
	color = start.color;
	if (map->c == 2)
		color = ft_average_rgb(start.color, end.color);
	while (i <= step)
	{
		ft_putpixel(start.x, start.y, map, color);
		start.x += dx;
		start.y += dy;
		i++;
	}
	ft_putpixel(start.x, start.y, map, color);
}

void		ft_draw_map_pro(t_map *fdf, int index)
{
	int			y;
	int			x;
	double		rad;

	rad = ((index == 1) ? RAD_MIL : RAD_ISO);
	y = 0;
	x = 0;
	while (y < fdf->rows)
	{
		while (x < fdf->row_len)
		{
			if (x + 1 < fdf->row_len)
				ft_drawline(ft_convert_xy(&fdf->map[y][x], fdf->img->amp,\
				fdf->img, rad), ft_convert_xy(&fdf->map[y][x + 1],\
				fdf->img->amp, fdf->img, rad), fdf->img);
			if (y + 1 < fdf->rows)
				ft_drawline(ft_convert_xy(&fdf->map[y][x], fdf->img->amp,\
				fdf->img, rad), ft_convert_xy(&fdf->map[y + 1][x],\
				fdf->img->amp, fdf->img, rad), fdf->img);
			x++;
		}
		y++;
		x = 0;
	}
}

void		ft_draw_map(t_map *fdf)
{
	int			y;
	int			x;

	y = 0;
	x = 0;
	if (fdf->img->pro)
		ft_draw_map_pro(fdf, fdf->img->pro - 1);
	while (y < fdf->end_y && !fdf->img->pro)
	{
		while (x < fdf->end_x)
		{
			if (x + 1 < fdf->row_len)
				ft_drawline(ft_paral_rot(&fdf->map[y][x], fdf->img),\
				ft_paral_rot(&fdf->map[y][x + 1], fdf->img), fdf->img);
			if (y + 1 < fdf->rows)
				ft_drawline(ft_paral_rot(&fdf->map[y][x], fdf->img),\
				ft_paral_rot(&fdf->map[y + 1][x], fdf->img), fdf->img);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->ptr, 0, 0);
}

void		ft_draw_image(t_map *fdf)
{
	ft_bzero(fdf->img->b_map, sizeof(int) * WIN_Y * WIN_X);
	ft_set_height(fdf);
	ft_mid(fdf);
	ft_draw_map(fdf);
	mlx_string_put(fdf->mlx, fdf->win, 20, 10, 0xF0F0F0, "Keymap:");
	mlx_string_put(fdf->mlx, fdf->win, 20, 40, 0xF0F0F0,\
	"amplitude                  Q / Z");
	mlx_string_put(fdf->mlx, fdf->win, 20, 60, 0xF0F0F0,\
	"rotate                         R");
	mlx_string_put(fdf->mlx, fdf->win, 20, 80, 0xF0F0F0,\
	"toggle colors                  C");
	mlx_string_put(fdf->mlx, fdf->win, 20, 100, 0xF0F0F0,\
	"change projection              p");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, 0xF0F0F0,\
	"zoom in / out              + / -");
	mlx_string_put(fdf->mlx, fdf->win, 20, 140, 0xF0F0F0,\
	"move map with arrows");
	mlx_string_put(fdf->mlx, fdf->win, 20, 160, 0xF0F0F0,\
	"window size          1920 x 1080");
}
