/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:17:02 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/02 16:42:40 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	search4paths(t_env *env, int follow)
{
	while (bfs(env, follow, env->start))
		;
	if (env->retry && !follow)
	{
		env->second_call = 1;
		search4paths(env, 1);
		delete_heads_rest((env->pthds));
		return ;
	}
}

void	print_input(t_inp **input)
{
	t_inp 	*tmp;
	t_inp 	*prev;

	tmp = *input;
	while (tmp)
	{
		ft_putendl(tmp->line);
		prev = tmp->next;
		free(tmp->line);
		free(tmp);
		tmp = prev;
	}
}

int		main()
{
	t_env	env;
	t_ant_opt opt;

	initialize_var(&env);
	input_to_list(&env);
	if (!save_input(&env))
		ft_putendl_fd("ERROR", 2);
	else
	{
		if (!env.startEndLinked)
		{
			setDeptLayers(&env);
			search4paths(&env, 0);
		}
		else if (env.startEndLinked)
			setOnePath(&env);
		print_input(&(env.inp));
		if (env.bestGroup && env.bestGroup->head && env.antsnb)
		{
			ft_select_paths(&env, env.bestGroup->head, 0);
			ft_calc_ants(&env);

			opt.id = 0;
			opt.ret = 0;
			opt.flag = 0;
			opt.antsnb = env.antsnb;
			opt.antsnb_org = env.antsnb;
			opt.nbrpaths = env.nbrpaths;
			ft_move_ants_trip(env.bestGroup->head, env.bestGroup->head, opt, 1);
		}
	}
	liberate_memory(&env);
	return (0);
}
