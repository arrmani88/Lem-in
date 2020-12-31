/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathgen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:22:01 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/31 18:54:24 by anel-bou         ###   ########.fr       */
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

void	verifyReverseLink(t_env *env, t_link *lnk, t_room *rm)
{
	t_link *rv_lnk;
	
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
}

t_room	*enumerateFromEndToStart(t_env *env, t_room *rm, t_room *start)
{
	int i = 0;
	rm = env->end;
	while (rm && rm != start && ++i)
	{
		rm->iterated = env->iteration_nb;
		rm = rm->parent;
	}
	return(rm);
}

t_path	*select_next_path(t_env *env)
{
	if (!env->pthds && env->ptheads)
		env->pthds = env->ptheads;
	else if (env->pthds)
	{
		if (env->pthds->next == NULL)
		{
			env->pthds->next = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
			env->pthds->next->path = (t_path *)ft_memalloc(sizeof(t_path));
		}
		env->pthds = env->pthds->next;
	}
	return (env->pthds->path);
}

t_path *allocate_pheads(t_env *env)
{
	t_ptheads *head;

	if (env->ptheads == NULL)
	{
		env->ptheads = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
		head = env->ptheads;
	}
	else if (env->ptheads)
	{
		head = env->ptheads;
		while (head->next != NULL)
			head = head->next;
		head->next = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
		head = head->next;
	}
	head->path = (t_path *)ft_memalloc(sizeof(t_path));
	return (head->path);
}

void	allocatePathHead(t_env *env)
{
	t_ptheads *head;

	head = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
	head->path = (t_path *)ft_memalloc(sizeof(t_path));
	env->pth = head->path;
	env->pthds = head;
}

int		checkIfRoomDuplicatedInBoth(t_path *p1, t_path *p2)
{
	t_path *ptr;

	p1 = p1->next;
	p2 = p2->next;
	while (p1->next)
	{
		ptr = p2;
		while (ptr->next)
		{
			if (p1->room == ptr->room)
				return (1);
			ptr = ptr->next;
		}
		p1 = p1->next;
	}
	return (0);
}

void	saveHeadInThisGroup(t_env *env, t_ptheads *prev, t_pathGroup **grp)
{
	t_ptheads *head;

	if (prev == NULL) /*lakan lgrp mafih ta head (mzl khawi) */
	{
		(*grp)->head = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
		head = (*grp)->head;
	}
	else /* else ser lhead lakkher w allouwi fnext dialo */
	{
		prev->next = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
		head = prev->next;
	}
	head->path = env->path;
}

void	saveHeadInNewGrp(t_env *env)
{
	t_pathGroup *grp;

	grp = env->pathGroup;
	while (grp->next)
		grp = grp->next;
	grp->next = (t_pathGroup *)ft_memalloc(sizeof(t_pathGroup));
	grp = grp->next;
	grp->head = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
	grp->head->path = env->path;
	grp->groupNumber = ++(env->groupNb);
}

void	searchForConvenientGroup(t_env *env)
{
	t_pathGroup *patGrp;
	t_ptheads	*patHed;
	t_ptheads	*prev;
	int			isAnyPathSaved;

	patGrp = env->pathGroup;
	prev = NULL;
	isAnyPathSaved = 0;
	while (patGrp)
	{
		patHed = patGrp->head;
		while (patHed)
		{
			if (checkIfRoomDuplicatedInBoth(patHed->path, env->pthds->path))
				break;
			prev = patHed;
			patHed = patHed->next;
		}
		if (patHed == NULL && ++isAnyPathSaved)
			saveHeadInThisGroup(env, prev, &patGrp);
		patGrp = patGrp->next;
	}
	if (!isAnyPathSaved)
		saveHeadInNewGrp(env);
}

int		path_generator(t_env *env, t_room *start)
{
	t_room *rm;
	t_link *lnk;
	t_path *papr; /*asp*/

	int i = 0;
	++env->iteration_nb; /*V1*/
	rm = enumerateFromEndToStart(env, rm, start);
	rm->iterated = ++env->iteration_nb; /*V2*/
	// env->pth = (!env->second_call ? allocate_pheads(env) : select_next_path(env));
	allocatePathHead(env);
	papr = env->pth; /* asp */
	env->path = env->pth;
	env->pth->room = rm;
	while (rm != env->end && ++i)
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
			lnk->room->full ? env->retry = 1 : 0; /*Va*/
			if (lnk->room != env->end)
				env->second_call ? (lnk->room->full = 2) : (lnk->room->full = 1);
			if (!env->pth->next)
				env->pth->next = (t_path *)ft_memalloc(sizeof(t_path));
			env->pth = env->pth->next;
			env->pth->room = lnk->room;
			verifyReverseLink(env, lnk, rm);
		}
		rm = lnk->room; /*A4*/
	}
	searchForConvenientGroup(env);
	// setPathInConvenientGroup(env);
	// delete_path_rest(env->pth);
	print_path(papr); /*asp*/
	return (1);
}

void	setOnePath(t_env *env)
{
	env->pth = allocate_pheads(env);
	env->pth->room = env->start;
	env->pth->next = (t_path *)ft_memalloc(sizeof(t_path));
	env->pth = env->pth->next;
	env->pth->room = env->end;
}






// lnk->room != env->end ? lnk->room->used = 1 : 0; Va


// void	setPathInConvenientGroup(t_env *env)
// {
// 	searchForConvenientGroup(env);
// 	if (env->pathGroup == NULL)
// 	{
// 		env->pathGroup = (t_pathGroup*)ft_memalloc(sizeof(t_pathGroup));
// 	}
	
// }