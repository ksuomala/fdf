/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 12:06:59 by ksuomala          #+#    #+#             */
/*   Updated: 2020/07/10 15:56:01 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t needle_l;

	i = 0;
	needle_l = ft_strlen(needle);
	if (needle_l == 0)
		return ((char *)haystack);
	while (haystack[i] != needle[0] && i + (needle_l)\
	< n && haystack[i] != '\0')
		i++;
	if (ft_strncmp(&haystack[i], needle, needle_l) !=\
	0 && haystack[i] != '\0' && (i + needle_l + 1) < n)
	{
		i++;
		return (ft_strnstr(&haystack[i], needle, n - i));
	}
	if (ft_strncmp(&haystack[i], needle, needle_l) == 0)
		return ((char *)&haystack[i]);
	return (NULL);
}
