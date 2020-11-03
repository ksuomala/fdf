/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 23:17:55 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/03 03:46:32 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pt		*ft_arr_atoi(char **split, t_map *fdf, int y)
{
	t_pt	*ret;
	int		i;

	i = 0;
	ret = (t_pt*)ft_memalloc(sizeof(t_pt) * fdf->row_len);
	if (!ret)
		ft_errors(0);
	while (split[i])
	{
		ret[i].z = ft_atoi(split[i]);
		ret[i].x = i;
		ret[i].y = y;
		ret[i].color = ft_color(ret[i].z);
//		ft_rotate_z(&ret[i].x, &ret[i].y, 0.3);
		i++;
	}
	return (ret);
}

static void		ft_realloc_map(t_map *fdf)
{
		t_pt	**tmp;

		if (!(tmp = ft_memdup(fdf->map, sizeof(t_pt*) * fdf->size)))
			ft_errors(0);
		free(fdf->map);
		fdf->size *= 2;
		if (!(fdf->map = ft_memalloc(sizeof(t_pt*) * fdf->size)))
			ft_errors(0);
		fdf->map = ft_memcpy(fdf->map, tmp, sizeof(t_pt*) * (fdf->size / 2));
		free(tmp);
		ft_printf("realloc\n");
}

static void		ft_create_map(t_map *fdf, char *line)
{
	char	**split;

	if (!fdf->size)
		fdf->size = 100;
	split = ft_strsplit(line, ' ');
	if (fdf->rows == fdf->size)
		ft_realloc_map(fdf);
	if (!fdf->row_len)
	{
		if (!(fdf->map = ft_memalloc(sizeof(t_pt*) * fdf->size)))
			ft_errors(0);
		while (split[fdf->row_len])
			fdf->row_len++;
	}
	fdf->map[fdf->rows] = ft_arr_atoi(split, fdf, fdf->rows);
	fdf->rows++;
	ft_free2d(split);
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
		ft_create_map(fdf, line);
	}
}
