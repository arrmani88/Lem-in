/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:17:02 by anel-bou          #+#    #+#             */
/*   Updated: 2020/11/18 11:34:38 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	search4paths(t_env *env, int follow)
{
	while (bfs(env, follow))
		;
	printf("**********\n");
	if (env->retry && !follow)
	{
		env->second_call = 1;
		search4paths(env, 1);
		delete_heads_rest(env->pthds);
		return ;
	}
}

int		main()
{
	t_env	*env;
	dup2(open("maps/stgkika", O_RDONLY), 0);
	printf("___________________________________\n");
	env = (t_env *)malloc(sizeof(t_env));
	initialize_var(env);
	input_to_list(env);
	save_input(env);
	search4paths(env, 0);

	print_all_paths(env); 	
	printf("___________________________________\n");
	return (0);
}







































/***********************************/
// {
	// test_loop(env, "1");
	// test_loop(env, "2");
	// test_loop(env, "3");
	// test_loop(env, "4");
	// test_loop(env, "5");
	// test_loop(env, "6");
	// test_loop(env, "7");
	// test_loop(env, "8");
	// test_loop(env, "9");
	// test_loop(env, "10");
	// test_loop(env, "11");
	// test_loop(env, "12");
	// test_loop(env, "13");
	// test_loop(env, "14");
	// test_loop(env, "15");
	// test_loop(env, "16");
	// test_loop(env, "17");
	// test_loop(env, "18");
	// test_loop(env, "19");
	// test_loop(env, "20");
	// test_loop(env, "21");
	// printf("\n");
// }