/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 23:09:23 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/13 22:36:17 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(t_struct *f)
{
	int i;

	i = 0;
	if (f->dup[f->i] == '0')
		f->spe->zero++;
	else
	{
		f->spe->width = ft_atoi(&f->dup[f->i]);
		i = f->spe->width;
		while (i > 9)
		{
			i = i / 10;
			f->i++;
		}
	}
}

void	ft_presicion(t_struct *f)
{
	int		ret;
	char	*ptr;

	ptr = &f->dup[f->i + 1];
	ret = 0;
	if (ft_isdigit(*ptr) || *ptr == '*')
		f->i++;
	if (!ft_isdigit(*ptr))
	{
		if (*ptr == '*')
		{
			f->spe->p_len = va_arg(f->ap, int);
			if (f->spe->p_len < 0)
				f->spe->p_is = 0;
		}
		else
			f->spe->p_len = 0;
		return ;
	}
	f->spe->p_len = ft_atoi(ptr);
	while (ft_isdigit(*ptr) && ft_isdigit(ptr[1]))
	{
		ptr++;
		f->i++;
	}
}

void	ft_more_flags(t_struct *f)
{
	if (f->dup[f->i] == '#')
		f->spe->hash++;
	if (f->dup[f->i] == '-')
		f->spe->minus++;
	if (f->dup[f->i] == '*')
	{
		f->spe->width = va_arg(f->ap, int);
		if (f->spe->width < 0)
		{
			f->spe->width *= -1;
			f->spe->minus++;
		}
	}
	if (f->dup[f->i] == ' ')
		f->spe->space++;
	if (f->dup[f->i] == '.')
	{
		f->spe->p_is++;
		ft_presicion(f);
	}
}

void	ft_flag(t_struct *f)
{
	if (ft_isdigit(f->dup[f->i]))
		ft_width(f);
	if (f->dup[f->i] == '+')
		f->spe->plus++;
	if (f->dup[f->i] == 'h' && f->dup[f->i + 1] != 'h')
		f->spe->h++;
	if (f->dup[f->i] == 'h' && f->dup[f->i + 1] == 'h')
	{
		f->spe->hh++;
		f->i++;
	}
	if (f->dup[f->i] == 'l' && f->dup[f->i + 1] != 'l')
		f->spe->l++;
	if (f->dup[f->i] == 'l' && f->dup[f->i + 1] == 'l')
	{
		f->spe->ll++;
		f->i++;
	}
	if (f->dup[f->i] == 'L')
		f->spe->long_d++;
	ft_more_flags(f);
	if (!ft_strchr(SPEC, f->dup[f->i]))
		f->i++;
}

int		ft_parse(t_struct *f)
{
	ft_bzero((void*)f->spe, sizeof(t_flags));
	while (f->dup[f->i] != '\0' && !ft_strchr(SPEC, f->dup[f->i]))
	{
		if (ft_strchr(FLAG, f->dup[f->i]) || f->dup[f->i] == '*')
			ft_flag(f);
		else
		{
			f->out[f->len] = f->dup[f->i];
			f->i++;
			f->len++;
		}
	}
	if (ft_strchr(SPEC, f->dup[f->i]))
	{
		if (!ft_type(f))
			return (0);
		f->i++;
	}
	if (f->spe->convert)
		free(f->spe->convert);
	ft_bzero((void*)f->spe, sizeof(t_flags));
	return (1);
}
