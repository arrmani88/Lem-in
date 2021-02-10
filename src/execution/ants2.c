/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:08:00 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 17:08:01 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_move_ants_lip(t_ptheads *path, t_ant_opt *opt)
{
	if (!path)
		return ;
	ft_move_ants(path->path->next, &(opt->antsnb));
	if (opt->id <= opt->antsnb_org && path->ants > 0)
	{
		path->path->next->ant_id = ++(opt->id);
		path->ants--;
	}
	ft_move_ants_lip(path->next, opt);
}

void	ft_move_ants_trip(t_ptheads *paths, t_ptheads *pivot, t_ant_opt opt)
{
	opt.ret = ft_print_ants(pivot->path->next, &(opt.flag));
	if (!(pivot->next) && !(opt.flag))
	{
		ft_move_ants_lip(paths, &opt);
		ft_putendl("");
	}
	if (!(pivot->next) && opt.flag)
		opt.flag = 0;
	if (opt.antsnb == 0)
		return ;
	ft_move_ants_trip(paths, (pivot->next) ? pivot->next : paths, opt);
}

int		ft_select_path(t_env *env, int next_len, int avg_len)
{
	t_norm_sp sp;

	sp.totallen = avg_len + next_len;
	sp.meanlen = sp.totallen / (env->nbrpaths + 1);
	sp.mod = sp.totallen % (env->nbrpaths + 1);
	sp.ret = env->antsnb;
	if (env->nbrpaths && avg_len / env->nbrpaths < sp.meanlen)
		return (0);
	sp.i = -1;
	sp.tmp = env->ptheads;
	while (++sp.i < env->nbrpaths && sp.tmp)
	{
		sp.ret -= sp.meanlen - sp.tmp->len + (sp.mod > 0);
		sp.mod--;
		sp.tmp = sp.tmp->next;
	}
	return (sp.ret > 0);
}

void	ft_select_paths(t_env *env, t_ptheads *current, int avg_len)
{
	if (!current)
		return ;
	current->len = current->total_rooms - 2;
	if (!ft_select_path(env, current->len, avg_len))
		return ;
	if (avg_len == 0)
		avg_len += env->antsnb;
	env->totallen += current->len;
	avg_len += current->len;
	env->nbrpaths++;
	ft_select_paths(env, current->next, avg_len);
}
