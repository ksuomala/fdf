/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:08:45 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/01 18:43:58 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_
# define WIN_Y 1080
# define WIN_X 1920

# define ESC 53
# define A_LEFT 123
# define A_RIGHT 124
# define A_DOWN 125
# define A_UP 126
# define PLUS 24
# define MINUS 27
# define Q 12
# define Z 6
# define P 35
# define Y 16

# include <fcntl.h>
# include "mlx.h"
# include "math.h"
# include "libft.h"


typedef struct	s_pt
{
	int			color;
	float		z;
	float		x;
	float		y;
}				t_pt;

typedef struct	s_bitmap
{
	void		*ptr;
	int			*b_map;
	int			bpp;
	int			size_l;
	int			endian;
	int			scale;
	int			width;
	int			height;
	int			move_y;
	int			move_x;
	int			outside_x;
	int			outside_y;
	float		amp;
	int			pro;
}				t_bitmap;

typedef struct	s_map
{
//	char		**in;
	t_bitmap	*img;
	t_pt		**map;
	void		*mlx;
	void		*win;
//	void		*img;
	int			size;
	int			rows;
	int			row_len;
} 				t_map;

void	ft_read_map(char **av, t_map *fdf);
void	ft_init_window(t_map *fdf);
void	ft_errors(int val);
void	ft_draw_image(t_map *fdf);
void	ft_keypress(t_map *fdf);
int		ft_key_mod(int key, t_bitmap *img);
int		ft_scale(t_map *fdf, t_bitmap *map);
int		ft_color(int height);
int		ft_average_rgb(int start, int end);

#endif