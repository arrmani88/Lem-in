/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:01:37 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/03 15:35:44 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_room	*get_room(t_env *env, char *room)

{
	env->ptr = env->room[get_index(env->nbrooms, room)];
	while (env->ptr->next && !ft_strequ(env->ptr->name, room))
		env->ptr = env->ptr->next;
	return (env->ptr);
}

void	save_parent(t_env *env, t_room *room)
{
	t_link	*lnk;

	lnk = room->link;
	while(lnk)
	{
		if (lnk->room->iterated != env->iteration_nb)
			lnk->room->parent = room;
		lnk = lnk->next;
	}
}

int		bfs(t_env *env, int follow, t_room *start)
{
	t_queue *last;
	t_queue	*first;
	t_queue	*tmp;
	int		rpt;
	int		altern;
	rpt = 0;
	altern = 0;
	++env->iteration_nb;
	start->iterated = env->iteration_nb;
	last = (t_queue*)malloc(sizeof(t_queue));
	last->room = start;
	last->next = NULL;
	first = last;
	while (first && first->room != env->end)
	{
		first->room->set_last = 0;
		env->lnk = first->room->link;
		while (env->lnk)
		{
			if  (((rpt == 0 && env->lnk->room->iterated != env->iteration_nb) || (rpt == 1 && env->lnk->room->set_last))
			&& env->lnk->flow == follow && env->lnk->room->full != 2)
			{
				env->lnk->room->set_last ? env->lnk->room->set_last = 0 : 0;
				if ((env->lnk->room->full == 1 && rpt) || (env->lnk->room->full == 0 && !rpt))
				{
					save_parent(env, first->room);
					env->lnk->room->iterated = env->iteration_nb;
					last->next = (t_queue *)malloc(sizeof(t_queue));
					last = last->next;
					last->room = env->lnk->room;
					last->next = NULL;
				}
			}
			if (env->lnk->room == env->end && env->lnk->flow == follow)
				return(path_generator(env, start));
			env->lnk = env->lnk->next;
		}
		rpt = 0;
		altern = 0;
		tmp = first->next;
		ft_memdel((void **)&first);
		first = tmp;
	}
	if (!env->lnk)
		return (0);
	return (path_generator(env, start));
}
