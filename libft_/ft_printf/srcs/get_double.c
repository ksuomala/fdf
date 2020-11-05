/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:50:16 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/14 17:39:25 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_add_postfix(t_struct *f, char *s)
{
	char	*division;

	division = ft_strnew(4);
	if (!division)
		return (NULL);
	if ((f->spe->p_is && !f->spe->p_len && f->spe->hash) ||\
	(f->spe->type == 'g' && f->spe->hash && f->spe->p_is && f->spe->p_len == 1))
		division[0] = '.';
	if (f->spe->exponent > 9)
		division = ft_strcat(division, "e+");
	else if (f->spe->exponent >= 0)
		division = ft_strcat(division, "e+0");
	if (f->spe->exponent < -9)
		division = ft_strcat(division, "e-");
	else if (f->spe->exponent < 0)
		division = ft_strcat(division, "e-0");
	if (f->spe->exponent >= 0)
		division = ft_strfjoin(division, ft_itoa(f->spe->exponent));
	else
		division = ft_strfjoin(division, ft_itoa(f->spe->exponent * -1));
	if (!division)
		return (NULL);
	division = ft_strfjoin(s, division);
	return (division);
}

int				ft_special_numbers(t_struct *f, long double dec)
{
	char *s;

	s = NULL;
	if (dec == 1.0 / 0.0)
		s = ft_strdup("inf");
	else if (dec == 1.0 / -0.0)
		s = ft_strdup("-inf");
	else if (dec != dec)
		s = ft_strdup("nan");
	else
		return (0);
	f->spe->convert = s;
	ft_nan_inf(f);
	return (1);
}

char			*ft_convert_float(t_struct *f)
{
	long double	nb;

	if (f->spe->long_d)
		nb = va_arg(f->ap, long double);
	else
		nb = va_arg(f->ap, double);
	if (ft_special_numbers(f, nb) > 0)
		return (f->spe->convert);
	if (1 / nb < 0)
	{
		f->spe->sign = '-';
		nb *= -1;
	}
	else if (f->spe->plus)
		f->spe->sign = '+';
	else if (f->spe->space)
		f->spe->sign = ' ';
	if (f->spe->type == 'e' || f->spe->type == 'g')
		if (!(ft_e(f, &nb)))
			return (NULL);
	if (f->spe->p_is)
		f->spe->convert = ft_f_presicion(nb, f->spe->p_len, f);
	else
		f->spe->convert = ft_f_presicion(nb, 6, f);
	return (f->spe->convert);
}

char			*ft_float_width(t_struct *f)
{
	int l;

	l = (int)ft_strlen(f->spe->convert);
	if (f->spe->width > l)
		l = f->spe->width - l;
	else
		l = 0;
	if (f->spe->sign)
		l--;
	if (f->spe->p_is && !f->spe->p_len && f->spe->hash && !f->spe->g)
		l--;
	f->spe->convert = ft_fl_to_buf(f, l);
	return (f->spe->convert);
}
