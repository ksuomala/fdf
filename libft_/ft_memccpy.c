/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:13:47 by ksuomala          #+#    #+#             */
/*   Updated: 2020/07/14 19:56:36 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*ret;

	i = 0;
	str = (unsigned char *)src;
	ret = (unsigned char *)dest;
	while (i < n)
	{
		ret[i] = str[i];
		if (str[i] == (unsigned char)c)
			return ((unsigned char *)&ret[i + 1]);
		i++;
	}
	return (NULL);
}
