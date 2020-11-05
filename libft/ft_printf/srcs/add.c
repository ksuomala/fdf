/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:24:16 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/13 22:46:53 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_add_prefix(t_struct *f)
{
	char	t;

	t = f->spe->type;
	if ((f->spe->hash && (f->spe->data || f->spe->ull)) || t == 'p' || t == 'o')
	{
		if (((t == 'X' || t == 'x') && (f->spe->data || f->spe->ull)) ||\
		t == 'p')
			f->spe->convert = ft_strfjoin(ft_strdup("0x"), f->spe->convert);
		if (t == 'o' && f->spe->hash && f->spe->convert[0] != '0')
			f->spe->convert = ft_strfjoin(ft_strdup("0"), f->spe->convert);
		if (!f->spe->convert)
			return (NULL);
	}
	if (t == 'X')
		f->spe->convert = ft_toupper_str(f->spe->convert);
	return (f->spe->convert);
}

char		*ft_add_zero(t_struct *f)
{
	int		l;
	char	t;
	char	*new;

	l = (int)ft_strlen(f->spe->convert);
	t = f->spe->type;
	if (t == 'p' || ((t == 'x' || t == 'X') &&\
	f->spe->hash && (f->spe->data || f->spe->ull)))
		l += 2;
	if (f->spe->width > l)
	{
		new = ft_strnew(f->spe->width - l);
		if (!new)
			return (NULL);
		ft_memset(new, '0', f->spe->width - l);
		f->spe->convert = ft_strfjoin(new, f->spe->convert);
		if (!f->spe->convert)
			return (NULL);
	}
	return (f->spe->convert);
}

char		*ft_add_presicion(t_struct *f)
{
	int		pre;
	char	*new;

	pre = f->spe->p_len - (int)ft_strlen(f->spe->convert);
	if (pre > 0)
	{
		if (!(new = ft_strnew(pre)))
			return (NULL);
		new = ft_memset((char*)new, '0', pre);
		f->spe->convert = ft_strfjoin(new, f->spe->convert);
		if (!f->spe->convert)
			return (NULL);
	}
	return (f->spe->convert);
}

char		*ft_add_itoa(t_struct *f)
{
	char t;

	t = f->spe->type;
	if (f->spe->p_is && !f->spe->p_len && !f->spe->data && !f->spe->ull)
		f->spe->convert = ft_strnew(0);
	else if (((t == 'o' || t == 'x' || t == 'X' || t == 'u') && (f->spe->ll ||\
	f->spe->l)) || t == 'p')
	{
		if (t == 'o')
			f->spe->convert = ft_u_itoa_base(f->spe->ull, 8);
		else if (t == 'u')
			f->spe->convert = ft_u_itoa_base(f->spe->ull, 10);
		else
			f->spe->convert = ft_u_itoa_base(f->spe->ull, 16);
	}
	else if (t == 'o')
		f->spe->convert = ft_itoa_base(f->spe->data, 8);
	else if (t == 'x' || t == 'X' || t == 'p')
		f->spe->convert = ft_itoa_base(f->spe->data, 16);
	else
		f->spe->convert = ft_itoa_base(f->spe->data, 10);
	return (f->spe->convert);
}

void		ft_argcast(t_struct *f)
{
	char t;

	t = f->spe->type;
	if (f->spe->l && (t == 'd' || t == 'i'))
		f->spe->data = va_arg(f->ap, long);
	else if ((f->spe->l && (t == 'x' || t == 'X' || t == 'u' || t == 'o')) ||\
	t == 'p')
		f->spe->ull = va_arg(f->ap, unsigned long);
	else if (f->spe->ll && (t == 'd' || t == 'i'))
		f->spe->data = (long long)va_arg(f->ap, long long int);
	else if ((f->spe->ll && (t == 'x' || t == 'X'\
	|| t == 'u' || t == 'o')))
		f->spe->ull = va_arg(f->ap, unsigned long long);
	else if (f->spe->h && (t == 'd' || t == 'i'))
		f->spe->data = (short)va_arg(f->ap, int);
	else if (f->spe->h && (t == 'x' || t == 'X' || t == 'u' || t == 'o'))
		f->spe->data = (unsigned short)va_arg(f->ap, int);
	else if (f->spe->hh && (t == 'd' || t == 'i'))
		f->spe->data = (char)va_arg(f->ap, int);
	else if (f->spe->hh && (t == 'x' || t == 'X' || t == 'u' || t == 'o'))
		f->spe->data = (unsigned char)va_arg(f->ap, int);
	else if (t == 'x' || t == 'X' || t == 'u' || t == 'o')
		f->spe->data = va_arg(f->ap, unsigned int);
	else if (t == 'd' || t == 'i')
		f->spe->data = va_arg(f->ap, int);
}
