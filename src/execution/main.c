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

#include "../includes/lem_in.h"

void	search4paths(t_env *env, int follow)
{
	while (bfs(env, follow, env->start))
		;
	t_path *path_tmp;
	while(env->path)
	{
		path_tmp = env->path->next;
		free(env->path);
		env->path = path_tmp;
	}
	if (env->retry && !follow)
	{
		env->second_call = 1;
		search4paths(env, 1);
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

	ft_select_paths(env, env->best_group->head, 0);
	ft_calc_ants(env);
	opt.id = 0;
	opt.ret = 0;
	opt.flag = 0;
	opt.antsnb = env->antsnb;
	opt.antsnb_org = env->antsnb;
	opt.nbrpaths = env->nbrpaths;
	ft_move_ants_trip(env->best_group->head, env->best_group->head, opt);
}

int		main(void)
{
	t_env		env;

	int fd = open("flow", O_RDONLY);
	// int fd2 = open("out", O_WRONLY);
	dup2(fd, 0);
	// dup2(fd2, 1);

	initialize_var(&env);
	if (!input_to_list(&env) || !save_input(&env))
		ft_putendl_fd("ERROR", 2);
	else
	{
		if (!env.start_end_linked)
		{
			set_dept_layers(&env);
			search4paths(&env, 0);
		}
		else if (env.start_end_linked)
			set_one_path(&env);
		print_input(&(env.inp));
		if (env.best_group && env.best_group->head && env.antsnb)
		{
			main_c2(&env);
		}
	}
	liberate_memory(&env);
	return (0);
}
