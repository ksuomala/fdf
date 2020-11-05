/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 23:14:23 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/14 17:41:51 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** I always have to check len < 1000
*/

#include "ft_printf.h"

char		*ft_floats(t_struct *f)
{
	if (f->spe->type == 'g')
		f->spe->g = 'e';
	if (!ft_convert_float(f))
		return (NULL);
	if (f->spe->g == 'f')
		if (!(f->spe->convert = ft_cut_f(f)))
			return (NULL);
	if (f->spe->g == 'e')
		if (!(f->spe->convert = ft_cut_e(f)))
			return (NULL);
	if (f->spe->capital)
		f->spe->convert = ft_toupper_str(f->spe->convert);
	if (!ft_float_width(f))
		return (NULL);
	if (!ft_strtobuf(f))
		return (NULL);
	return (f->spe->convert);
}

static char	*ft_s(t_struct *f)
{
	f->spe->convert = va_arg(f->ap, char*);
	if (!f->spe->convert)
		f->spe->convert = ft_strdup("(null)");
	else
		f->spe->convert = ft_strdup(f->spe->convert);
	if (!f->spe->convert)
		return (NULL);
	f->spe->slen = (int)ft_strlen(f->spe->convert);
	if (f->spe->p_len < f->spe->slen\
	&& f->spe->p_is && f->spe->p_len >= 0)
		f->spe->slen = f->spe->p_len;
	f->spe->convert = ft_s_to_buf(f);
	return (f->spe->convert);
}

int			ft_c(t_struct *f)
{
	if (f->spe->width > 1 && f->spe->zero && !f->spe->minus)
		if (!ft_chrtobuf(f, '0', (f->spe->width - 1)))
			return (0);
	if (f->spe->width > 1 && !f->spe->zero && !f->spe->minus)
		if (!ft_chrtobuf(f, ' ', (f->spe->width - 1)))
			return (0);
	if (f->dup[f->i] == '%')
	{
		if (!ft_chrtobuf(f, '%', 1))
			return (0);
	}
	else if (!ft_chrtobuf(f, (char)va_arg(f->ap, int), 1))
		return (0);
	if (f->spe->width > 1 && f->spe->minus)
		if (!ft_chrtobuf(f, ' ', (f->spe->width - 1)))
			return (0);
	return (1);
}

char		*ft_nb(t_struct *f)
{
	int l;

	l = 0;
	ft_argcast(f);
	if (!ft_add_itoa(f))
		return (NULL);
	if (f->spe->p_is)
		if (!(ft_add_presicion(f)))
			return (NULL);
	if (f->spe->zero && !f->spe->minus && !f->spe->p_is)
		if (!(ft_add_zero(f)))
			return (NULL);
	if (!(ft_add_prefix(f)))
		return (NULL);
	if (f->spe->width > (int)ft_strlen(f->spe->convert))
		l = f->spe->width - (int)ft_strlen(f->spe->convert);
	f->spe->convert = ft_nb_to_buf(f, l);
	return (f->spe->convert);
}

int			ft_type(t_struct *f)
{
	char	t;

	f->spe->type = f->dup[f->i];
	t = f->spe->type;
	if (t == 's')
		if (!ft_s(f))
			return (0);
	if (t == 'c' || t == '%')
		if (!ft_c(f))
			return (0);
	if (t == 'd' || t == 'i')
		if (!ft_d(f))
			return (0);
	if (t == 'p' || t == 'x' || t == 'X' || t == 'u' || t == 'o')
		if (!ft_nb(f))
			return (0);
	if (t == 'F' || t == 'E' || t == 'G')
	{
		f->spe->type = ft_tolower(f->spe->type);
		f->spe->capital++;
	}
	if (f->spe->type == 'f' || f->spe->type == 'e' || f->spe->type == 'g')
		if (!ft_floats(f))
			return (0);
	return (1);
}
