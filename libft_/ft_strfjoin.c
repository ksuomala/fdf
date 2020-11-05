/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:49:48 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/01 16:28:22 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Make sure that s1 and s2 are both malloced. This function will free those
**	pointers after joining the strings. Instead of using a string literal, use
**	ft_strdup
*/

#include "libft.h"

char	*ft_strfjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	i2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!ptr)
		return (NULL);
	i = 0;
	i2 = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		ptr[i + i2] = s2[i2];
		i2++;
	}
	free(s1);
	free(s2);
	return (ptr);
}
