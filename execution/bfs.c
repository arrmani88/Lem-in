/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:01:37 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/30 15:58:38 by anel-bou         ###   ########.fr       */
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
	start->iterated = env->iteration_nb; /*V1*/
	last = (t_queue*)malloc(sizeof(t_queue));
	last->room = start;
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
				env->lnk->room->set_last ? env->lnk->room->set_last = 0 : 0; /*VA*/
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
				return(path_generator(env, start)); /* freei dak 7zaq lte7t */
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
		first = tmp; //print_current_queue(first);
	}
	if (!env->lnk)
		return (0);
	return (path_generator(env, start));
}

void	MoveBackToFirstPossibleStart(t_env *env, t_room *room)
{
	t_link	*lnk;
	t_room	*rm;
	
	env->retry = 1;
	lnk = room->link;
	while (lnk && ((lnk->room->dept_layer >= room->dept_layer && !lnk->room->full ) || lnk->room == env->start))
		{ lnk = lnk->next;}
	if (lnk == NULL)
		return ;

	rm = lnk->room;
	while (rm->full && rm != env->start)
	{
		lnk = rm->link;
		while (lnk && (lnk->room->full || lnk->room == env->start))
			lnk = lnk->next;
		if (lnk && !lnk->room->full)
		{
			room->correctionRoom = 1;
			bfs(env, 0, rm); return;
		}
		
		lnk = rm->link;
		while (lnk && ((lnk->room->dept_layer > rm->dept_layer && !lnk->room->full) || lnk->room == env->start))
			lnk = lnk->next;
		if (lnk && !lnk->room->full)
		{
			room->correctionRoom = 1;
			bfs(env, 0, rm);
			return;
		}

		if (lnk && lnk->room->full)
			rm = lnk->room;
		else 
			return ;
	}
}













	// env->end->iterated = 0; V1

// if (env->lnk->room->full == 1 && !follow && !env->lnk->room->correctionRoom)  VA
// {  VA
// 	MoveBackToFirstPossibleStart(env, env->lnk->room);  VA
// }  VA
// if (!env->lnk)  VA
// 	return (1);  VA