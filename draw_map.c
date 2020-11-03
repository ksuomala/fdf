/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:51:28 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/03 02:18:32 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_rotate_z(float *x, float *y, float angle)
{
	float hyp;
	hyp = cos(angle) * *y;
	angle = 1.3962634016;
	*x = hyp * sin(angle);
	*y = hyp * cos(angle);
}

void	ft_putimage(t_map *fdf, t_bitmap *img)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, img->ptr, 0, 0);
}

void	ft_putpixel(int x, int y, t_bitmap *map, int color)
{
	int i;
	int mid_y;
	int mid_x;

	mid_y = map->mid_y + map->move_y * map->scale + y;
	mid_x = map->mid_x + map->move_x * map->scale + x;
	if (mid_y < 0 || mid_y >= WIN_Y || mid_x < 0 || mid_x >= WIN_X)
		return ;
	i = map->size_l * mid_y + mid_x;
	map->b_map[i] = color;
}

void	ft_drawline(t_pt start, t_pt end, t_bitmap *map)
{
	int		i;
	int		color;
	float	dx;
	float	dy;
	float	step;

	ft_multiply_scale(&start, &end, map->scale);
	dx = (end.x - start.x);
	dy = (end.y - start.y);
	if (fabsf(dx) >= fabsf(dy))
		step = fabsf(dx);
	else
		step = fabsf(dy);
	dx = dx / step;
	dy = dy / step;
	i = 1;
	color = start.color;
	while (i <= step)
	{
		ft_putpixel(start.x, start.y, map, color);
		start.x = start.x + dx;
		start.y = start.y + dy;
		i = i + 1;
	}
	ft_putpixel(start.x, start.y, map, color);
}

t_pt	ft_convert_xy(t_pt *p, float amplitude, double rad)
{
	t_pt temp;

	temp.color = ft_color(p->z);
	if (p->z)
		temp.z = (p->z * (1.0 + amplitude)) / 2;
	else
		temp.z = p->z;
	temp.x = (p->x - p->y) * cos(rad); //correct
	temp.y = (p->x + p->y) * sin(rad) - temp.z;
	return (temp);
}






void	ft_draw_map_pro(t_map *fdf)
{
	int			y;
	int			x;
	int			i;
	double		rad[2];

	i = fdf->img->pro - 1;
	rad[0] = RAD_ISO;
	rad[1] = RAD_MIL;
	y = 0;
	x = 0;
	while (y < fdf->end_y)
	{
		while (x < fdf->end_x)
		{
			if (x + 1 < fdf->row_len)
				ft_drawline(ft_convert_xy(&fdf->map[y][x], fdf->img->amp, rad[i]), ft_convert_xy(&fdf->map[y][x + 1], fdf->img->amp, rad[i]), fdf->img);
			if (y + 1 < fdf->rows)
				ft_drawline(ft_convert_xy(&fdf->map[y][x], fdf->img->amp, rad[i]), ft_convert_xy(&fdf->map[y + 1][x], fdf->img->amp, rad[i]), fdf->img);
			x++;
		}
		y++;
		x = 0;
	}
	ft_putimage(fdf, fdf->img);
}

void ft_draw_map(t_map *fdf)
{
	int			y;
	int			x;

	y = 0;
	x = 0;
	ft_set_height(fdf);
	ft_mid(fdf);
	if (fdf->img->pro)
	{
		ft_draw_map_pro(fdf);
		return ;
	}
	while (y < fdf->end_y)
	{
		while (x < fdf->end_x)
		{
			if (x + 1 < fdf->row_len)
				ft_drawline(fdf->map[y][x], fdf->map[y][x + 1], fdf->img);
			if (y + 1 < fdf->rows)
				ft_drawline(fdf->map[y][x], fdf->map[y + 1][x], fdf->img);
			x++;
		}
		y++;
		x = 0;
	}
	ft_putimage(fdf, fdf->img);
}

void	ft_draw_image(t_map *fdf)
{
	ft_bzero(fdf->img->b_map, sizeof(int) * WIN_Y * WIN_X);
	ft_draw_map(fdf);
}
