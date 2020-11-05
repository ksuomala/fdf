/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 00:28:53 by ksuomala          #+#    #+#             */
/*   Updated: 2020/07/06 20:52:31 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_l;
	size_t	max_l;
	size_t	i;
	size_t	ret;

	if (size == 0 || size < ft_strlen(dest) + 1)
		return (size + ft_strlen(src));
	dest_l = ft_strlen(dest);
	max_l = size - dest_l - 1;
	i = 0;
	ret = ft_strlen(dest) + ft_strlen(src);
	if (max_l < 1)
		return (ret);
	while (i < max_l && src[i] != '\0')
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\0';
	return (ret);
}
