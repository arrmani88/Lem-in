/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:01:37 by anel-bou          #+#    #+#             */
/*   Updated: 2020/11/18 11:36:47 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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
		if (lnk->room->iterated != env->iteration_nb)// && lnk->flow != -1)
			lnk->room->parent = room;
		lnk = lnk->next;
	}
}

int		bfs(t_env *env, int follow)
{
	t_room	*prn;
	t_queue *last;
	t_queue	*first;
	t_queue	*tmp;
	int		rpt;
	int		altern;

	prn = NULL;
	rpt = 0;
	altern = 0;
	++env->iteration_nb;
	env->start->iterated = env->iteration_nb; /*V1*/
	last = (t_queue*)malloc(sizeof(t_queue));
	last->room = env->start;
	last->next = NULL;
	first = last;
	// print_current_queue(first);
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
				if (env->lnk->room->full == 1 && !rpt)
				{
					env->lnk->room->set_last = 1;
					altern = 1;
				}
				else if ((env->lnk->room->full == 1 && rpt) || (env->lnk->room->full == 0 && !rpt))
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
				return(path_generator(env)); /* freei dak 7zaq lte7t */
			env->lnk = env->lnk->next;
			if (env->lnk == NULL && !rpt && altern)
			{
				rpt = 1;
				env->lnk = first->room->link;
			}
		}
		rpt = 0;
		altern = 0;
		tmp = first->next;
		ft_memdel((void **)&first);
		first = tmp; // print_current_queue(first);
	}
	if (!env->lnk)
		return (0);
	return (path_generator(env));
}














	// env->end->iterated = 0; V1