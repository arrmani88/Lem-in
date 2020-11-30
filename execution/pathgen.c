/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathgen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:22:01 by anel-bou          #+#    #+#             */
/*   Updated: 2020/11/29 13:54:59 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_link *get_link_from(t_room *room1, t_room *room2)
{
	t_link *link;

	link = room1->link;
	while (!ft_strequ(room2->name, link->room->name))
		link = link->next;
	return (link);
}

t_path *allocate_pheads(t_env *env)
{
	t_ptheads *head;

	if (env->ptheads == NULL)
	{
		env->ptheads = (t_ptheads *)malloc(sizeof(t_ptheads));
		head = env->ptheads;
	}
	else if (env->ptheads)
	{
		head = env->ptheads;
		while (head->next)
			head = head->next;
		head->next = (t_ptheads *)malloc(sizeof(t_ptheads));
		head = head->next;
	}
	head->next = NULL;
	head->path = (t_path *)malloc(sizeof(t_path));
	head->path->next = NULL;
	return (head->path);
}

t_path	*select_next_path(t_env *env)
{
	if (!env->pthds && env->ptheads)
		env->pthds = env->ptheads;
	else if (env->pthds)
	{
		if (!env->pthds->next)
		{
			env->pthds = (t_ptheads *)malloc(sizeof(t_ptheads));
			env->pthds->next = NULL;
			env->pthds->path = (t_path *)malloc(sizeof(t_path));
			env->pthds->path->next = NULL;
		}
		env->pthds = env->pthds->next;
	}
	return (env->pthds->path);
}

int path_generator(t_env *env)
{
	t_room *rm;
	t_link *lnk;
	t_link *rv_lnk;
	t_path *papr;

	++env->iteration_nb; /*V1*/
	rm = env->end;
	while (rm != env->start)
	{
		rm->iterated = env->iteration_nb;
		rm = rm->parent;
	}
	lnk = NULL;
	rm->iterated = ++env->iteration_nb; /*V2*/
	env->pth = (!env->second_call ? allocate_pheads(env) : select_next_path(env));
	papr = env->pth; /* asp */
	env->pth->room = rm;
	env->pth->next = NULL;
	while (rm != env->end)
	{
		lnk = rm->link;
		while (lnk->room->iterated != env->iteration_nb - 1)
			lnk = lnk->next;
		if (lnk->room->iterated == env->iteration_nb - 1 /*>3*/)
		{
			lnk->room->iterated = env->iteration_nb;
			if (env->retry == 1 && lnk->flow == 1)
				lnk->flow = 0;
			else if (!lnk->flow)
				lnk->flow = 1;
			lnk->room->full ? env->retry = 1 : 0;
			// lnk->room != env->end ? lnk->room->used = 1 : 0;
			if (lnk->room != env->end)
				env->second_call ? (lnk->room->full = 2) : (lnk->room->full = 1);
			
			if (!env->pth->next)
			{
				env->pth->next = (t_path *)malloc(sizeof(t_path));
				env->pth->next->next = NULL;
			}
			env->pth = env->pth->next;
			env->pth->room = lnk->room;
			if (rm && rm->parent)
			{
				rv_lnk = get_link_from(lnk->room, rm); /*V5*/
				if (rv_lnk->flow == 1)
				{
					rv_lnk->flow = -1;
					lnk->flow = -1;
					env->retry = 1;
				}
			}
		} /*V4*/
		rm = lnk->room;
	}
	delete_path_rest(env->pth);
	print_path(papr);
	return (1);
}
