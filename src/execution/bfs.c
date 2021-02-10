/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:07:02 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 17:07:07 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
	while (lnk)
	{
		if (lnk->room->iterated != env->iteration_nb)
			lnk->room->parent = room;
		lnk = lnk->next;
	}
}

void	bfs_c3(t_env *env, int follow, t_norm_bfs *bfs)
{
	if (((bfs->rpt == 0 && env->lnk->room->iterated != env->iteration_nb)
	|| (bfs->rpt == 1 && env->lnk->room->set_last))
	&& env->lnk->flow == follow && env->lnk->room->full != 2)
	{
		env->lnk->room->set_last ? env->lnk->room->set_last = 0 : 0;
		if ((env->lnk->room->full == 1 && bfs->rpt)
		|| (env->lnk->room->full == 0 && !bfs->rpt))
		{
			save_parent(env, bfs->first->room);
			env->lnk->room->iterated = env->iteration_nb;
			bfs->last->next = (t_queue *)malloc(sizeof(t_queue));
			bfs->last = bfs->last->next;
			bfs->last->room = env->lnk->room;
			bfs->last->next = NULL;
		}
	}
}

void	bfs_c2(t_env *env, t_room *start, t_norm_bfs *bfs)
{
	bfs->rpt = 0;
	bfs->altern = 0;
	++env->iteration_nb;
	start->iterated = env->iteration_nb;
	bfs->last = (t_queue*)malloc(sizeof(t_queue));
	bfs->last->room = start;
	bfs->last->next = NULL;
	bfs->first = bfs->last;
}

int		bfs(t_env *env, int follow, t_room *start)
{
	t_norm_bfs bfs;

	bfs_c2(env, start, &bfs);
	while (bfs.first && bfs.first->room != env->end)
	{
		bfs.first->room->set_last = 0;
		env->lnk = bfs.first->room->link;
		while (env->lnk)
		{
			bfs_c3(env, follow, &bfs);
			if (env->lnk->room == env->end && env->lnk->flow == follow)
				return (path_generator(env, start));
			env->lnk = env->lnk->next;
		}
		bfs.rpt = 0;
		bfs.altern = 0;
		bfs.tmp = bfs.first->next;
		ft_memdel((void **)&(bfs.first));
		bfs.first = bfs.tmp;
	}
	if (!env->lnk)
		return (0);
	return (path_generator(env, start));
}
