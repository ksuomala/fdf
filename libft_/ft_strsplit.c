/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 10:45:33 by ksuomala          #+#    #+#             */
/*   Updated: 2020/09/15 20:12:47 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_free(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

static size_t	ft_splitlen(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_words(char const *s, char c)
{
	size_t i;
	size_t w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			w++;
			i = ft_splitlen(&s[i], c) + i;
		}
	}
	return (w);
}

static char		*ft_returnstring(char const *s, char c)
{
	size_t	i;
	size_t	i_new;
	size_t	l;
	char	*ptr;

	i = 0;
	i_new = 0;
	while (s[i] == c)
		i++;
	l = ft_splitlen(&s[i], c);
	ptr = ft_strnew(l);
	if (!ptr)
		return (NULL);
	ptr[l] = '\0';
	while (s[i] != c && s[i] != '\0')
	{
		ptr[i_new] = s[i];
		i++;
		i_new++;
	}
	return (ptr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	words;
	size_t	i;
	size_t	i_new;

	i = 0;
	i_new = 0;
	words = ft_words(s, c);
	split = (char **)malloc(sizeof(char*) * words + 1);
	if (!split)
		return (NULL);
	while (i < words)
	{
		split[i] = ft_returnstring(&s[i_new], c);
		if (!split[i])
			return (ft_free(split));
		i++;
		i_new = i_new + ft_splitlen(&s[i_new], c);
	}
	split[i] = 0;
	return (split);
}
