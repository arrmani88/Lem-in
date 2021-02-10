/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathgen2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:31:20 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 17:31:21 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	search_for_convenient_group_c1(t_env *env, int total_rooms_in_path,
t_ptheads *head, t_norm_sfcg *sfcg)
{
	while (head)
	{
		if (check_if_room_duplicated_in_both(head->path, env->pthds->path))
			break ;
		sfcg->prev = head;
		head = head->next;
	}
	if (head == NULL && ++sfcg->is_any_path_saved)
	{
		sfcg->current_score = get_group_score(env->antsnb,
sfcg->grp->total_rooms_in_group + total_rooms_in_path, sfcg->grp->total_heads + 1);
		if (sfcg->current_score < sfcg->grp->score || sfcg->grp->score == 0)
		{
			save_head_in_this_group(env, sfcg->prev,
			&sfcg->grp, total_rooms_in_path);
			sfcg->grp->score = sfcg->current_score;
			if (sfcg->current_score < env->best_score)
			{
				env->best_score = sfcg->current_score;
				env->best_group = sfcg->grp;
			}
		}
	}
}

void	search_for_convenient_group(t_env *env, int total_rooms_in_path)
{
	t_norm_sfcg sfcg;

	sfcg.grp = env->path_group;
	sfcg.prev = NULL;
	sfcg.current_score = 0;
	sfcg.is_any_path_saved = 0;
	while (sfcg.grp)
	{
		search_for_convenient_group_c1(env, total_rooms_in_path,
		sfcg.grp->head, &sfcg);
		sfcg.grp = sfcg.grp->next;
	}
	if (!sfcg.is_any_path_saved)
		save_head_in_new_grp(env, total_rooms_in_path);
}

void	path_generator_c2(t_env *env, t_norm_pg *pg)
{
	if (pg->lnk->room->iterated == env->iteration_nb - 1)
	{
		pg->lnk->room->iterated = env->iteration_nb;
		if (env->retry == 1 && pg->lnk->flow == 1)
			pg->lnk->flow = 0;
		else if (!pg->lnk->flow)
			pg->lnk->flow = 1;
		pg->lnk->room->full ? env->retry = 1 : 0;
		if (pg->lnk->room != env->end)
		{
			env->second_call ? (pg->lnk->room->full = 2)
			: (pg->lnk->room->full = 1);
		}
		if (!env->pth->next)
			env->pth->next = (t_path *)ft_memalloc(sizeof(t_path));
		env->pth = env->pth->next;
		env->pth->room = pg->lnk->room;
		++pg->total_rooms;
		verify_reverse_link(env, pg->lnk, pg->rm);
	}
}

int		path_generator(t_env *env, t_room *start)
{
	t_norm_pg	pg;
	int			i;

	i = 0;
	pg.total_rooms = 1;
	++env->iteration_nb;
	pg.rm = enumerate_from_end_to_start(env, start);
	pg.rm->iterated = ++env->iteration_nb;
	allocate_path_head(env);
	pg.papr = env->pth;
	env->path = env->pth;
	env->pth->room = pg.rm;
	while (pg.rm != env->end && ++i)
	{
		pg.lnk = pg.rm->link;
		while (pg.lnk->room->iterated != env->iteration_nb - 1
		|| pg.lnk->room->parent != pg.rm)
			pg.lnk = pg.lnk->next;
		path_generator_c2(env, &pg);
		pg.rm = pg.lnk->room;
	}
	search_for_convenient_group(env, pg.total_rooms);
	return (1);
}

void	set_one_path(t_env *env)
{
	env->pth = allocate_pheads(env);
	env->pth->room = env->start;
	env->pth->next = (t_path *)ft_memalloc(sizeof(t_path));
	env->pth = env->pth->next;
	env->pth->room = env->end;
}
