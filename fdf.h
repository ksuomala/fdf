/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:08:45 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 20:05:43 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_Y 1080
# define WIN_X 1920

# define RAD_ISO 0.5235987756
# define RAD_MIL 0.7853981634

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
# define R 15
# define T 17
# define U 32
# define C 8

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
	float		rot_z;
	float		rot_y;
	float		rot_x;
	int			bpp;
	int			size_l;
	int			endian;
	int			scale;
	float		zoom;
	int			width;
	int			height;
	int			move_y;
	int			move_x;
	int			mid_y;
	int			mid_x;
	float		amp;
	int			pro;
	int			color_mode;
}				t_bitmap;

typedef struct	s_map
{
	t_bitmap	*img;
	t_pt		**map;
	void		*mlx;
	void		*win;
	int			*row_len;
	int			size;
	int			row_count;
	int			row_len_max;
	float		max_z;
	float		min_z;
}				t_map;

void			ft_read_map(char **av, t_map *fdf);
void			ft_init_window(t_map *fdf);
void			ft_errors(int val);
void			ft_draw_image(t_map *fdf);
void			ft_keypress(t_map *fdf);
int				ft_key_mod(int key, t_bitmap *img);
int				ft_scale(t_map *fdf, t_bitmap *map);

int				ft_color_simple(int z, int max);
int				ft_color(int z, int max, int min);
int				ft_average_rgb(int start, int end);
void			ft_toggle_colors(t_map *fdf);

void			ft_set_height(t_map *fdf);
void			ft_set_scale(t_map *fdf, t_bitmap *map);
void			ft_multiply_scale(t_pt *start, t_pt *end, int scale);
void			ft_mid(t_map *fdf);

t_pt			ft_rotate_z(float x, float y, float angle);
t_pt			ft_convert_xy(t_pt *p, float amplitude,\
t_bitmap *img, double rad);
void			ft_zero_to_middle(t_map *fdf);
t_pt			ft_paral_rot(t_pt *p, t_bitmap *img);
void			ft_multiply_zoom(t_pt *s, t_pt *e, float zoom);

void			ft_change_rotation(t_map *fdf);

int				ft_exit(void);

#endif
