/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:08:09 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/14 17:43:59 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPEC "cspfdiouxX%egEFG"
# define FLAG "hlL#-+0123456789* ."

# include "libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	unsigned long long	ull;
	unsigned char		capital;
	long long			data;
	char				*convert;
	char				sign;
	char				type;
	int					slen;
	int					hash;
	int					star;
	int					minus;
	int					plus;
	int					l;
	int					ll;
	int					long_d;
	int					h;
	int					hh;
	int					zero;
	int					width;
	int					space;
	int					p_is;
	int					p_len;
	int					exponent;
	char				g;
}				t_flags;

typedef struct	s_struct
{
	va_list			ap;
	char			*out;
	char			*dup;
	int				buf_size;
	int				i;
	int				len;
	t_flags			*spe;

}				t_struct;

int				ft_printf(const char *format, ...);
int				ft_snprintf(char *s, size_t n, const char *format, ...);

/*
** Functions in parse.c read the data between '%' and the SPEC.
*/
int				ft_parse(t_struct *f);
void			ft_flag(t_struct *f);
void			ft_presicion(t_struct *f);
void			ft_width(t_struct *f);

int				ft_type(t_struct *format);

/*
** These functions in add_to_buffer.c add the right characters to the f->out
** after the conversions.
*/

char			*ft_chrtobuf(t_struct *f, char c, int n);
char			*ft_strtobuf(t_struct *f);
char			*ft_chrnstr_pre(char **s, char c, int chrcount);
char			*ft_chrnstr_post(char **s, char c, int chrcount);

char			*ft_realloc_double(char **old, size_t len, size_t size);

/*
** add.c contains these functions. They read the flags from the struct and
** use va_arg and the proper type of itoa according to the flags and specifier.
** Prefix and presicion are added to the string.
*/

char			*ft_add_prefix(t_struct *f);
char			*ft_add_zero(t_struct *f);
char			*ft_add_presicion(t_struct *f);
char			*ft_add_itoa(t_struct *f);
void			ft_argcast(t_struct *f);

/*
** Handles the %d specifier.
*/

int				ft_d(t_struct *f);

/*
** Functions that handle data associated with doubles and long doubles.
** %f, %g, %e specifiers are handled with these functions.
*/

int				ft_e(t_struct *f, long double *nb);
char			*ft_f_presicion(long double dec, int prelen, t_struct *f);
char			*ft_floats(t_struct *f);
char			*ft_add_postfix(t_struct *f, char *s);
void			ft_round_e(t_struct *f, char *s, long long *whole);
char			*ft_convert_float(t_struct *f);
char			*ft_float_width(t_struct *f);
void			ft_nan_inf(t_struct *f);
char			*ft_cut_e(t_struct *f);
char			*ft_cut_f(t_struct *f);

/*
** Found in conv_to_out.c . These functions add the conversion string to f->out.
*/

char			*ft_s_to_buf(t_struct *f);
char			*ft_nb_to_buf(t_struct *f, int l);
char			*ft_fl_to_buf(t_struct *f, int l);

/*
** ft_fail frees malloced pointers and ends the program in
** a case of malloc failure.
*/

int				ft_fail(t_struct *f);

#endif
