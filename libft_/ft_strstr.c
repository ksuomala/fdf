/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:32:23 by ksuomala          #+#    #+#             */
/*   Updated: 2020/07/02 21:13:29 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i_h;
	size_t needle_l;

	i_h = 0;
	needle_l = ft_strlen(needle);
	if (needle_l == 0)
		return ((char *)haystack);
	while (haystack[i_h] != needle[0] && haystack[i_h] != '\0')
		i_h++;
	if (ft_strncmp(&haystack[i_h], needle, needle_l) != 0 && \
	haystack[i_h] != '\0')
		return (ft_strstr(&haystack[i_h + 1], needle));
	if (ft_strncmp(&haystack[i_h], needle, needle_l) == 0)
		return ((char *)&haystack[i_h]);
	return (NULL);
}
