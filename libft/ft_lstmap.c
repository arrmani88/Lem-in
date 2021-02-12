/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 01:22:05 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/29 23:32:03 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *head;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!tmp)
		return (NULL);
	head = tmp;
	while (lst->next)
	{
		if (!(tmp->next = f(lst->next)))
		{
			ft_lstdel(&head, &ft_del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (head);
}
