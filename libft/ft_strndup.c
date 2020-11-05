/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:52:00 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/11 17:52:03 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	l;
	size_t	i;
	char	*dup;

	if (!str)
		return (NULL);
	i = 0;
	l = ft_strlen(str);
	if (n < l)
		l = n;
	dup = (char *)malloc(sizeof(char) * l + 1);
	if (!dup)
		return (NULL);
	dup[l] = '\0';
	while (str[i] != '\0' && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
