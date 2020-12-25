/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:11:06 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/25 15:15:48 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

// void	allocate_memory(t_env *env)
// {
// }

void	set_first_ch(t_env *env)
{
	t_link	*lnk;

	lnk = env->start->link;
	while (lnk)
	{
		lnk->room->childnb = FIRST_CH;
		lnk = lnk->next;
	}
}

void    initialize_var(t_env *env)
{
	env->antsnb = 0;
	env->pthds = NULL;
	env->ptheads = NULL;
	env->iteration_nb = 1;
	env->retry = 0;
	env->second_call = 0;
	env->ptheads = NULL; /* V1 */
	env->nbrpaths = 0;
	env->totallen = 0;
	env->start = NULL;
	env->end = NULL;
	env->startEndLinked = 0;
}



    // set_first_ch(env); V1