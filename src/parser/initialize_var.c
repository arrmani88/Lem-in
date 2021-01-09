/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:48:28 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 16:48:33 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

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

void	initialize_var(t_env *env)
{
	env->antsnb = 0;
	env->pthds = NULL;
	env->ptheads = NULL;
	env->iteration_nb = 1;
	env->retry = 0;
	env->second_call = 0;
	env->ptheads = NULL;
	env->nbrpaths = 0;
	env->totallen = 0;
	env->start = NULL;
	env->end = NULL;
	env->startEndLinked = 0;
	env->pathGroup = (t_pathGroup *)ft_memalloc(sizeof(t_pathGroup));
	env->pathGroup->groupNumber = 1;
	env->pthGrp = NULL;
	env->groupNb = 1;
	env->bestScore = __INT_MAX__;
}

int		ft_str_is_num(char *str)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(str);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	if (len > 19 || len == 0)
		return (0);
	return (1);
}

int		ft_str_is_name(char *str)
{
	int i;

	i = -1;
	if (str[0] == '#' || str[0] == 'L')
		return (0);
	while (str[++i])
		if (!ft_isprint(str[i]))
			return (0);
	return (1);
}

int		get_index(int max, char *str)
{
	int res;
	int	i;

	res = 0;
	i = -1;
	while (str[++i])
		res += str[i];
	return (res %= max);
}
