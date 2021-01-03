/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dept_layers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:18:10 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/27 15:35:53 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void    setDeptLayers(t_env *env)
{
	t_queue *last;
	t_queue	*first;
	t_queue	*tmp;
	t_link  *lnk;
	int		dept;

	dept = 2;
	last = (t_queue*)malloc(sizeof(t_queue));
	last->room = env->start;
	last->next = NULL;
	first = last;
	env->start->dept_layer = 1;
	while (first)
	{
		lnk = first->room->link;
		while (lnk)
		{
			if (lnk->room->dept_layer == -1)
			{
				lnk->room->dept_layer = dept;
				last->next = (t_queue *)malloc(sizeof(t_queue));
				last = last->next;
				last->room = lnk->room;
				last->next = NULL;
			}
			lnk = lnk->next;
		}
		dept++;
		tmp = first->next;
		ft_memdel((void **)&first);
		first = tmp;
	}
}