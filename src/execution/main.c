/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:07:13 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 17:07:18 by youarzaz         ###   ########.fr       */
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
	t_inp	*tmp;
	t_inp	*prev;

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

void	main_c2(t_env *env)
{
	t_ant_opt	opt;

	ft_select_paths(env, env->bestGroup->head, 0);
	ft_calc_ants(env);
	opt.id = 0;
	opt.ret = 0;
	opt.flag = 0;
	opt.antsnb = env->antsnb;
	opt.antsnb_org = env->antsnb;
	opt.nbrpaths = env->nbrpaths;
	ft_move_ants_trip(env->bestGroup->head, env->bestGroup->head, opt);
}

int		main(void)
{
	t_env		env;

	initialize_var(&env);
	input_to_list(&env);
	if (!save_input(&env))
		ft_putendl_fd("ERROR", 2);
	else
	{
		if (!env.startEndLinked)
		{
			set_dept_layers(&env);
			search4paths(&env, 0);
		}
		else if (env.startEndLinked)
			set_one_path(&env);
		print_input(&(env.inp));
		if (env.bestGroup && env.bestGroup->head && env.antsnb)
		{
			main_c2(&env);
		}
	}
	liberate_memory(&env);
	return (0);
}
