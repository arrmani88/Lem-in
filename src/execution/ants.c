/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:06:51 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 17:06:56 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	ft_calc_ants(t_env *env)
{
	t_ptheads		*tmp;
	unsigned int	i;
	int				meanlen;
	int				mod;
	t_ptheads		*prev;

	meanlen = (env->antsnb + env->totallen) / env->nbrpaths;
	mod = (env->antsnb + env->totallen) % env->nbrpaths;
	tmp = env->best_group->head;
	prev = tmp;
	i = -1;
	while (++i < env->nbrpaths && tmp)
	{
		tmp->ants = meanlen - tmp->len + (mod > 0);
		mod--;
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp)
		prev->next = NULL;
}

void	ft_move_ants(t_path *path, int *antsnb)
{
	if (*antsnb < 0 || !path)
		return ;
	ft_move_ants(path->next, antsnb);
	path->status = NONE;
	if (!(path->next) && path->ant_id > 0)
	{
		path->ant_id = 0;
		(*antsnb)--;
	}
	else if (path->next && path->ant_id > 0)
	{
		path->next->ant_id = path->ant_id;
		path->ant_id = 0;
	}
}

int		ft_print_ants(t_path *path, int *flag)
{
	int ret;

	if (!path || (path && path->status == PRINTED))
		return (0);
	if (path && path->ant_id == -1)
		return (1);
	ret = ft_print_ants(path->next, flag);
	if (ret != 2 && path->ant_id > 0)
	{
		path->status = PRINTED;
		ft_putstr("L");
		ft_putnbr(path->ant_id);
		ft_putstr("-");
		ft_putstr(path->room->name);
		ft_putstr(" ");
		return (2);
	}
	else if (path->ant_id > 0 && path->status != PRINTED)
		*flag = 1;
	path->status = PASSED;
	return (ret);
}
