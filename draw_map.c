/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:51:28 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/29 00:20:21 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	map->b_map[i] = color;
//	ft_printf("map[%d] = %d\n", i, color);
//	ft_printf("move x = %d", map->move_x);
}



void	ft_multiply_scale(t_pt *start, t_pt *end, int scale)
{
//	ft_printf("scale = %d", scale);
	start->x *= scale;
	start->y *= scale;
	end->y *= scale;
	end->x *= scale;
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
	int		dx;
	int		dy;
	float	step;

	ft_multiply_scale(&start, &end, map->scale);
	dx = (end.x - start.x);
	dy = (end.y - start.y);
//	ft_printf("dx = %d, dy = %d\n", dx, dy);
	if (abs(dx) >= abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	dx = dx / step;
	dy = dy / step;
//	x = start.x;
//	y = start.y;
	i = 1;
//	color = ft_color(start.z);
//	change = ft_next_pixel_color(start.z, end.z, step);
	while (i <= step)
	{
		if (start.color != end.color)
			color = ft_average_rgb(start.color, end.color);
		else
			color = start.color;
		ft_putpixel(start.x, start.y, map, color);
//		x = x + dx;
		start.x = start.x + dx;
//		y = y + dy;
		start.y = start.y + dy;
		i = i + 1;
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
	ft_draw_map(fdf);
}
