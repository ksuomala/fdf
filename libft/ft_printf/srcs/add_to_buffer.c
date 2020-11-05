/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:37:52 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/14 18:08:05 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_chrnstr_post(char **s, char c, int chrcount)
{
	int		len;
	int		i;
	char	*new;

	len = (int)ft_strlen(*s);
	new = ft_strnew(chrcount + len);
	if (!new)
		return (NULL);
	new = ft_strcpy(new, *s);
	i = len;
	while (i < chrcount + len)
	{
		new[i] = c;
		i++;
	}
	free(*s);
	*s = new;
	return (new);
}

char		*ft_chrnstr_pre(char **s, char c, int chrcount)
{
	int		len;
	int		i;
	char	*new;

	len = (int)ft_strlen(*s);
	new = ft_strnew(chrcount + len);
	if (!new)
		return (NULL);
	i = 0;
	while (i < chrcount)
	{
		new[i] = c;
		i++;
	}
	new = ft_strcat(new, *s);
	free(*s);
	*s = new;
	return (new);
}

char		*ft_realloc_double(char **old, size_t len, size_t size)
{
	char		*new;
	size_t		i;

	i = 0;
	new = ft_strnew(size * 2);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = old[0][i];
		i++;
	}
	new[i] = '\0';
	free(*old);
	return (new);
}

char		*ft_strtobuf(t_struct *f)
{
	int i;
	int l;

	l = ft_strlen(f->spe->convert);
	i = 0;
	while (f->len + l >= f->buf_size - 1)
	{
		f->out = ft_realloc_double(&f->out, f->len, f->buf_size);
		if (!f->out)
			return (NULL);
		f->buf_size *= 2;
	}
	while (i < l)
	{
		f->out[f->len + i] = f->spe->convert[i];
		i++;
	}
	f->len += i;
	return (f->out);
}

char		*ft_chrtobuf(t_struct *f, char c, int n)
{
	int i;

	i = 0;
	if (f->len == f->buf_size - 1)
		f->out = ft_realloc_double(&f->out, f->len, f->buf_size);
	if (!f->out)
		return (NULL);
	while (i < n)
	{
		f->out[f->len] = c;
		f->len++;
		i++;
	}
	return (f->out);
}
