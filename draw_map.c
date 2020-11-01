/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:51:28 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/01 19:03:35 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_putimage(t_map *fdf, t_bitmap *img)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, img->ptr, 0, 0);
}

void	ft_putpixel(int x, int y, t_bitmap *map, int color)
{
	int i;
	int mid_y;
	int mid_x;

	mid_y = WIN_Y / 2 - map->height * map->scale / 2 + map->move_y + y;
	mid_x = WIN_X / 2 - map->width * map->scale / 2 + map->move_x + x;
//	ft_printf("putpixel x = %d y = %d\n move_y = %d", mid_x, mid_y, map->move_y);
//	ft_printf("scale = %d HEIGHTWIDTH = %d %d\n", map->scale, map->height, map->width);
	if (mid_y < 0 || mid_y >= WIN_Y || mid_x < 0 || mid_x >= WIN_X)
		return ;
	i = map->size_l * mid_y + mid_x;
//	ft_printf("i =22222231231231232312312 %d", i);
	map->b_map[i] = color;
//	ft_printf("map[%d] = %d\n", i, color);
//	ft_printf("move x = %d", map->move_x);
}

void	ft_putpixel_iso(int x, int y, t_bitmap *map, int color)
{
	int i;
//	int mid_y;
//	int mid_x;

//	mid_y = WIN_Y / 2 - map->height * map->scale / 2 + map->move_y + y;
//	mid_x = WIN_X / 2 - map->width * map->scale / 2 + map->move_x + x;
//	ft_printf("putpixel x = %d y = %d\n move_y = %d", mid_x, mid_y, map->move_y);
//	ft_printf("scale = %d HEIGHTWIDTH = %d %d\n", map->scale, map->height, map->width);
	if (y < 0 || y >= WIN_Y || x < 0 || x >= WIN_X)
		return ;
	i = map->size_l * y + x;
	ft_printf("i = %d", i);
	map->b_map[i] = color;
//	ft_printf("map[%d] = %d\n", i, color);
//	ft_printf("move x = %d", map->move_x);
}



void	ft_multiply_scale(t_pt *start, t_pt *end, int scale)
{
//	ft_printf("scale = %d", scale);
//	scale = 15;
	start->x *= scale;
	start->y *= scale;
	end->y *= scale;
	end->x *= scale;
	start->z *= scale;
	end->z *= scale;
}

// int		ft_next_pixel_color(int z_s, int z_end, int distance)
// {
// 	int change;
// 	int dx;

// 	dx = z_end - z_s;

// }

void	ft_drawline(t_pt start, t_pt end, t_bitmap *map)
{
//	float x;
//	float y;
	int		i;
	int		color;
//	int		change;
	float	dx;
	float	dy;
	float	step;
//	ft_n(2);
//	ft_putnbr(start.x);
//	ft_printf("\ndrawline start xy = |%f|%f|, end = |%f|%f|\n", start.x, start.y, end.x, end.y);
//	printf("PF__\ndrawline start xy = |%hhf|%hhf|, end = |%hhf|%hhf|\n", start.x, start.y, end.x, end.y);
	ft_multiply_scale(&start, &end, map->scale);
	//map->scale = 10;
//	ft_printf("drawline |%d|%d| -- |%d|%d|", start.y, start.x, end.y, end.x);
	dx = (end.x - start.x);
	dy = (end.y - start.y);
//	ft_printf("dx = %d, dy = %d\n", dx, dy);
	if (fabsf(dx) >= fabsf(dy))
		step = fabsf(dx);
	else
		step = fabsf(dy);
	dx = dx / step;
	dy = dy / step;
//	x = start.x;
//	y = start.y;
	i = 1;
	color = start.color;
//	change = ft_next_pixel_color(start.z, end.z, step);
	while (i <= step)
	{
		if (start.color != end.color)
			color = ft_average_rgb(start.color, end.color);
		else
			color = start.color;
		ft_putpixel(start.x, start.y, map, color);
//		ft_putpixel_iso(start.x, start.y, map, color);
//		ft_printf("putpxl |%d||%d|", start.x, start.y);
//		x = x + dx;
		start.x = start.x + dx;
//		y = y + dy;
		start.y = start.y + dy;
		i = i + 1;
	//	ft_printf("11111122222333");
	}
}

void	ft_set_scale(t_map *fdf, t_bitmap *map)
{
	map->height = fdf->rows;
	map->width = fdf->row_len;
	map->scale = 3;
	while (map->height * map->scale * 2 <= WIN_Y && map->width * map->scale * 2 <= WIN_X)
		map->scale += 3;
//	map->height *= map->scale;
//	map->width *= map->scale;
}

void	ft_drawline_test(int x0, int y0, int x1, int y1, t_bitmap *map)
{
	t_pt start;
	t_pt end;

	start.z = -4;
	end.z = 4;
	start.x = x0;
	start.y = y0;
	end.x = x1;
	end.y = y1;
	ft_drawline(start, end, map);
}

void	ft_not_in_window(t_bitmap *img)
{
	img->outside_x = 0;
	img->outside_y = 0;
}

t_pt	ft_iso_xy(t_pt *p, float amplitude)
{
	t_pt temp;

	temp.color = ft_color(p->z);
	if (p->z)
		temp.z = (p->z * (1.0 + amplitude)) / 2;
	else
		temp.z = p->z;
	temp.x = (p->x - p->y) * cos(0.5235987756); //correct
	temp.y = (p->x + p->y) * sin(0.5235987756) - temp.z;
	return (temp);
}

t_pt	ft_mil_xy(t_pt *p, float amplitude)
{
	t_pt temp;

//	ft_printf("\npre conversion %d, %d, cos = %f\n", p->x, p->y, cos(0.523599));
	temp.color = ft_color(p->z);
	if (p->z)
		temp.z = (p->z * (1.0 + amplitude)) / 2;
	else
		temp.z = p->z;
	temp.x = (p->x - p->y) * cos(0.7853981634); //correct
	temp.y = (p->x + p->y) * sin(0.7853981634) - temp.z;
//	temp.y *= -1;
//	ft_printf("x = %d, y = %d", temp.x, temp.y);
//	temp.x = temp.x;
//	temp.y = temp.y;
	return (temp);
}

t_pt	ft_goofy_xy(t_pt *p, float amplitude)
{
	t_pt temp;

//	ft_printf("\npre conversion %d, %d, cos = %f\n", p->x, p->y, cos(0.523599));
	temp.color = ft_color(p->z);
	if (p->z)
		temp.z = (p->z * (1.0 + amplitude)) / 2;
	else
		temp.z = p->z;
	temp.x = (p->x - p->y) * cos(0.3490658504); //correct
	temp.y = (p->x + p->y) * sin(0.3490658504) - temp.z;
//	temp.y *= -1;
//	ft_printf("x = %d, y = %d", temp.x, temp.y);
//	temp.x = temp.x;
//	temp.y = temp.y;
	return (temp);
}

t_pt	ft_goofy2_xy(t_pt *p, float amplitude)
{
	t_pt temp;

//	ft_printf("\npre conversion %d, %d, cos = %f\n", p->x, p->y, cos(0.523599));
	if (p->z)
		temp.z = (p->z * (1.0 + amplitude)) / 2;
	else
		temp.z = p->z;
	temp.x = (p->x - p->y) * cos(0.6981317008); //correct
	temp.y = (p->x + p->y) * sin(0.6981317008) - temp.z;
//	temp.y *= -1;
//	ft_printf("x = %d, y = %d", temp.x, temp.y);
//	temp.x = temp.x;
//	temp.y = temp.y;
	return (temp);
}

t_pt cr(float x0, float y0)
{
	t_pt ret;

	ret.x = x0;
	ret.y = y0;

	return (ret);
}

void ft_draw_map_goofy(t_map *fdf)
{
	int y;
	int x;

	ft_not_in_window(fdf->img);
	x = fdf->img->outside_x;
	y = fdf->img->outside_y;
//	ft_printf("y = %d, x = %d", y, x);
//	ft_drawline(cr(82, 20), cr(90, 12), fdf->img);
	while (y < fdf->rows - fdf->img->outside_y)
	{
		while (x < fdf->row_len - fdf->img->outside_x)
		{
//			ft_printf("row_len = %d, x + 1 = %d, outside_x = %d", fdf->row_len, x + 1, fdf->img->outside_x);
			if (x + 1 < fdf->row_len - fdf->img->outside_x)
				ft_drawline(ft_goofy_xy(&fdf->map[y][x], fdf->img->amp), ft_goofy2_xy(&fdf->map[y][x + 1], fdf->img->amp), fdf->img);
			if (y + 1 < fdf->rows - fdf->img->outside_y)
				ft_drawline(ft_goofy_xy(&fdf->map[y][x], fdf->img->amp), ft_goofy2_xy(&fdf->map[y + 1][x], fdf->img->amp), fdf->img);
			x++;
		}
		y++;
		x = fdf->img->outside_x;
	}
//	ft_printf("q in bitmap\n");
	ft_putimage(fdf, fdf->img);
}

void ft_draw_map_military(t_map *fdf)
{
	int y;
	int x;

	ft_not_in_window(fdf->img);
	x = fdf->img->outside_x;
	y = fdf->img->outside_y;
//	ft_printf("y = %d, x = %d", y, x);
//	ft_drawline(cr(82, 20), cr(90, 12), fdf->img);
	while (y < fdf->rows - fdf->img->outside_y)
	{
		while (x < fdf->row_len - fdf->img->outside_x)
		{
//			ft_printf("row_len = %d, x + 1 = %d, outside_x = %d", fdf->row_len, x + 1, fdf->img->outside_x);
			if (x + 1 < fdf->row_len - fdf->img->outside_x)
				ft_drawline(ft_mil_xy(&fdf->map[y][x], fdf->img->amp), ft_mil_xy(&fdf->map[y][x + 1], fdf->img->amp), fdf->img);
			if (y + 1 < fdf->rows - fdf->img->outside_y)
				ft_drawline(ft_mil_xy(&fdf->map[y][x], fdf->img->amp), ft_mil_xy(&fdf->map[y + 1][x], fdf->img->amp), fdf->img);
			x++;
		}
		y++;
		x = fdf->img->outside_x;
	}
//	ft_printf("q in bitmap\n");
	ft_putimage(fdf, fdf->img);
}

void ft_draw_map_isometric(t_map *fdf)
{
	int y;
	int x;

	ft_not_in_window(fdf->img);
	x = fdf->img->outside_x;
	y = fdf->img->outside_y;
//	ft_printf("y = %d, x = %d", y, x);
//	ft_drawline(cr(82, 20), cr(90, 12), fdf->img);
	while (y < fdf->rows - fdf->img->outside_y)
	{
		while (x < fdf->row_len - fdf->img->outside_x)
		{
//			ft_printf("row_len = %d, x + 1 = %d, outside_x = %d", fdf->row_len, x + 1, fdf->img->outside_x);
			if (x + 1 < fdf->row_len - fdf->img->outside_x)
				ft_drawline(ft_iso_xy(&fdf->map[y][x], fdf->img->amp), ft_iso_xy(&fdf->map[y][x + 1], fdf->img->amp), fdf->img);
			if (y + 1 < fdf->rows - fdf->img->outside_y)
				ft_drawline(ft_iso_xy(&fdf->map[y][x], fdf->img->amp), ft_iso_xy(&fdf->map[y + 1][x], fdf->img->amp), fdf->img);
			x++;
		}
		y++;
		x = fdf->img->outside_x;
	}
//	ft_printf("q in bitmap\n");
	ft_putimage(fdf, fdf->img);
}

void ft_draw_map(t_map *fdf)
{
	int			y;
	int			x;

	y = 0;
	x = 0;
	while (y < fdf->rows)
	{
		while (x < fdf->row_len)
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

//	ft_printf("draw_image");
	if (!fdf->img)
		fdf->img = ft_memalloc(sizeof(t_bitmap));
	if (!fdf->img->height)
		ft_set_scale(fdf, fdf->img);
	fdf->img->ptr = mlx_new_image(fdf->mlx, WIN_X, WIN_Y);
	fdf->img->b_map = (int*)mlx_get_data_addr(fdf->img->ptr, &fdf->img->bpp, &fdf->img->size_l, &fdf->img->endian);
	fdf->img->size_l /= 4;
	ft_keypress(fdf);
	// while (y < fdf->rows)
	// {
	// 	while (x < fdf->row_len)
	// 	{
	// 		if (x + 1 < fdf->row_len)
	// 			ft_drawline(fdf->map[y][x], fdf->map[y][x + 1], fdf->img);
	// 		if (y + 1 < fdf->rows)
	// 			ft_drawline(fdf->map[y][x], fdf->map[y + 1][x], fdf->img);
	// 		x++;
	// 	}
	// 	y++;
	// 	x = 0;
	// }
	// ft_putimage(fdf, fdf->img);
	if (fdf->img->pro == 0)
		ft_draw_map_isometric(fdf);
	else if (fdf->img->pro == 1)
		ft_draw_map_military(fdf);
	else if (fdf->img->pro == 2)
		ft_draw_map(fdf);
	else
		ft_draw_map_goofy(fdf);
}
