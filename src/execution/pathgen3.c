/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathgen3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:32:02 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 17:32:03 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	allocate_path_head(t_env *env)
{
	t_ptheads *head;

	head = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
	head->path = (t_path *)ft_memalloc(sizeof(t_path));
	env->pth = head->path;
	env->pthds = head;
}

int		check_if_room_duplicated_in_both(t_path *p1, t_path *p2)
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

void	save_head_in_new_grp(t_env *env, int total_rooms_in_path)
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
	++(grp->totalHeads);
	grp->total_roomsInGroup = total_rooms_in_path;
	grp->score = total_rooms_in_path + 1;
}

void	save_head_in_this_group(t_env *env, t_ptheads *prev,
t_pathGroup **grp, int total_rooms_in_path)
{
	t_ptheads *head;

	if (prev == NULL)
	{
		(*grp)->head = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
		head = (*grp)->head;
	}
	else
	{
		prev->next = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
		head = prev->next;
	}
	head->total_rooms = total_rooms_in_path;
	head->path = env->path;
	++((*grp)->totalHeads);
	(*grp)->total_roomsInGroup += total_rooms_in_path;
}

int		get_group_score(int ants, int rooms_in_grp, int heads)
{
	int n;

	n = (int)((rooms_in_grp + ants) / heads);
	return (n);
}