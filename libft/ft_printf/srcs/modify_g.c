/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:47:28 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/14 17:22:15 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_roundup_g(char *s)
{
	int i;
	int nb;

	i = (int)ft_strlen(s) - 1;
	while (s[i])
	{
		if (i > 0 && s[i] == ':')
		{
			s[i] = '0';
			s[i - 1] += 1;
		}
		i--;
		if (s[i] == '/')
		{
			nb = ft_atoi(s);
			if (nb < 0)
				nb -= 1;
			else
				nb += 1;
			free(s);
			s = ft_itoa(nb);
			return (s);
		}
	}
	return (s);
}

int			ft_digit_presicion(char *s, int presicion, char hash)
{
	int i;
	int digits;

	i = 0;
	digits = 0;
	if (!ft_atoi(s) && ft_strchr(s, '.'))
		while (s[i] != '.')
			i++;
	if (s[i] == '.')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i] && digits < presicion)
	{
		if ((ft_isdigit(s[i]) && s[i] && digits) ||\
		(ft_isdigit(s[i]) && s[i] && (s[i] != '0' || hash)))
			digits++;
		i++;
	}
	if (!presicion)
	{
		while (s[i] != '.' && s[i])
			i++;
	}
	return (i);
}

void		ft_presicion_g(char *s, int presicion, int hash)
{
	int		i;
	char	c;

	i = ft_digit_presicion(s, presicion, hash);
	if (hash && s[i] == '.')
		i++;
	c = s[i];
	s[i] = '\0';
}

char		*ft_cut_f(t_struct *f)
{
	char	*new;
	int		i;

	i = 0;
	while (f->spe->convert[i] == '0' && f->spe->convert[i + 1] != '.'\
	&& f->spe->convert[i + 1])
		i++;
	if (f->spe->hash && f->spe->convert[i] == '.')
		i++;
	new = ft_strsub(f->spe->convert, i, (int)ft_strlen(f->spe->convert) - i);
	if (f->spe->p_is)
		ft_presicion_g(new, f->spe->p_len, f->spe->hash);
	else
		ft_presicion_g(new, 6, f->spe->hash);
	free(f->spe->convert);
	i = (int)ft_strlen(new) - 1;
	while (i && ft_strchr(new, '.') && new[i] == '0' && !f->spe->hash)
	{
		new[i] = '\0';
		i--;
	}
	if (new[i] == '.' && !f->spe->hash)
		new[i] = '\0';
	return (new);
}

char		*ft_cut_e(t_struct *f)
{
	char	*new;
	int		i;

	new = ft_strchr(f->spe->convert, 'e');
	i = new - f->spe->convert - 1;
	new = ft_strdup(new);
	if (!new)
		return (NULL);
	f->spe->convert[i + 1] = '\0';
	while (f->spe->convert[i] == '0' && i > 0)
	{
		f->spe->convert[i] = '\0';
		i--;
	}
	if (f->spe->convert[i] == '.')
		f->spe->convert[i] = '\0';
	new = ft_strfjoin(f->spe->convert, new);
	return (new);
}
