/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:20:20 by ksuomala          #+#    #+#             */
/*   Updated: 2020/09/15 20:33:49 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*fresh;

	start = f(lst);
	if (!start)
		return (NULL);
	fresh = start;
	while (lst->next)
	{
		lst = lst->next;
		fresh->next = f(lst);
		fresh = fresh->next;
		if (!fresh)
		{
			ft_lstfree(&start);
			return (NULL);
		}
	}
	fresh->next = NULL;
	return (start);
}
