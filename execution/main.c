/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:17:02 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/31 11:48:46 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	search4paths(t_env *env, int follow)
{
	// printf("------------------------------------------\n");
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

int		main()
{
	t_env	*env;
	t_ant_opt opt;
	t_inp 	*tmp;
int i = 0;

	env = (t_env *)malloc(sizeof(t_env));
	initialize_var(env);
	input_to_list(env);
	if (!save_input(env))
		ft_putendl_fd("ERROR", 2);
	else
	{
		if (!env->startEndLinked)
		{
			setDeptLayers(env);
			search4paths(env, 0);
		}
		else if (env->startEndLinked)
			setOnePath(env);
printf("###\n");print_all_paths(env); exit(0);
		tmp = env->inp;
		while (tmp)
		{
			ft_putendl(tmp->line);
			tmp = tmp->next;
		}
		if (env->ptheads && env->antsnb)
		{

			ft_select_paths(env, env->ptheads, 0);
			ft_calc_ants(env);

			opt.id = 0;
			opt.ret = 0;
			opt.flag = 0;
			opt.antsnb = env->antsnb;
			opt.antsnb_org = env->antsnb;
			opt.nbrpaths = env->nbrpaths;
			ft_move_ants_trip(env->ptheads, env->ptheads, opt, 1, &i);
		}
	}
	printf("Number of instructions=[%d]\n", i); /*delete variable "i" men func move ants trip*/
	return (0);
}
