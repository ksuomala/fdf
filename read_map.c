/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 23:17:55 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 19:47:14 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pt		*ft_arr_atoi(char **split, t_map *fdf, int y)
{
	t_pt	*ret;
	int		i;

	i = 0;
	ret = (t_pt*)ft_memalloc(sizeof(t_pt) * fdf->row_len_max);
	if (!ret)
		ft_errors(0);
	while (split[i])
	{
		ret[i].z = ft_atoi(split[i]);
		if (ret[i].z > fdf->max_z)
			fdf->max_z = ret[i].z;
		if (ret[i].z < fdf->min_z)
			fdf->min_z = ret[i].z;
		ret[i].x = i;
		ret[i].y = y;
		i++;
	}
	return (ret);
}

static void		ft_realloc_map(t_map *fdf)
{
	t_pt	**temp_map;
	int		*temp_rowlen;

	if (!(temp_map = ft_memdup(fdf->map, sizeof(t_pt*) * fdf->size)))
		ft_errors(0);
	if (!(temp_rowlen = ft_memdup(fdf->row_len, sizeof(int) * fdf->size)))
		ft_errors(0);
	free(fdf->map);
	free(fdf->row_len);
	fdf->size *= 2;
	if (!(fdf->map = ft_memalloc(sizeof(t_pt*) * fdf->size)))
		ft_errors(0);
	if (!(fdf->row_len = ft_memalloc(sizeof(int) * fdf->size)))
		ft_errors(0);
	fdf->map = ft_memcpy(fdf->map, temp_map, sizeof(t_pt*) * (fdf->size / 2));
	fdf->row_len = ft_memcpy(fdf->row_len, temp_rowlen, sizeof(int) *\
	(fdf->size / 2));
	free(temp_map);
	free(temp_rowlen);
	ft_printf("realloc\n");
}

void			ft_zero_to_middle(t_map *fdf)
{
	int y;
	int x;

	y = 0;
	x = 0;
	fdf->max_z *= fdf->img->scale;
	fdf->min_z *= fdf->img->scale;
	while (y < fdf->row_count)
	{
		while (x < fdf->row_len_max)
		{
			fdf->map[y][x].color = 0xFF;
			fdf->map[y][x].x *= fdf->img->scale;
			fdf->map[y][x].y *= fdf->img->scale;
			fdf->map[y][x].z *= fdf->img->scale;
			fdf->map[y][x].x -= (fdf->row_len_max - 1) * fdf->img->scale / 2;
			fdf->map[y][x].y -= (fdf->row_count - 1) * fdf->img->scale / 2;
			x++;
		}
		y++;
		x = 0;
	}
}

static void		ft_create_row(t_map *fdf, char *line)
{
	char	**split;

	if (!fdf->size)
		fdf->size = 100;
	split = ft_strsplit(line, ' ');
	if (fdf->row_count == fdf->size)
		ft_realloc_map(fdf);
	if (!fdf->row_len_max)
	{
		if (!(fdf->map = ft_memalloc(sizeof(t_pt*) * fdf->size)))
			ft_errors(0);
		if (!(fdf->row_len = ft_memalloc(sizeof(int) * fdf->size)))
			ft_errors(0);
	}
	while (split[fdf->row_len[fdf->row_count]])
		fdf->row_len[fdf->row_count]++;
	if (fdf->row_len[fdf->row_count] > fdf->row_len_max)
		fdf->row_len_max = fdf->row_len[fdf->row_count];
	fdf->map[fdf->row_count] = ft_arr_atoi(split, fdf, fdf->row_count);
	fdf->row_count++;
	ft_free2d((void**)split);
}

void			ft_read_map(char **av, t_map *fdf)
{
	int		fd;
	int		ll;
	char	*line;

	line = NULL;
	ll = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_errors(2);
	while ((ll = get_next_line(fd, &line)))
	{
		if (ll == -1)
			ft_errors(3);
		ft_create_row(fdf, line);
		free(line);
	}
}
