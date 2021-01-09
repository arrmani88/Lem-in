/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathgen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:07:23 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 17:07:27 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_link	*get_link_from(t_room *room1, t_room *room2)
{
	t_link *link;

	link = room1->link;
	while (!ft_strequ(room2->name, link->room->name))
		link = link->next;
	return (link);
}

void	verify_reverse_link(t_env *env, t_link *lnk, t_room *rm)
{
	t_link *rv_lnk;

	if (rm && rm->parent)
	{
		rv_lnk = get_link_from(lnk->room, rm);
		if (rv_lnk->flow == 1)
		{
			rv_lnk->flow = -1;
			lnk->flow = -1;
			env->retry = 1;
		}
	}
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

t_path	*allocate_pheads(t_env *env)
{
	t_ptheads *head;

	if (env->ptheads == NULL)
	{
		env->ptheads = (t_ptheads *)ft_memalloc(sizeof(t_ptheads));
		head = env->ptheads;
	}
	else
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

t_room	*enumerate_from_end_to_start(t_env *env, t_room *start)
{
	t_room	*rm;
	int		i;

	i = 0;
	rm = env->end;
	while (rm && rm != start && ++i)
	{
		rm->iterated = env->iteration_nb;
		rm = rm->parent;
	}
	return (rm);
}
