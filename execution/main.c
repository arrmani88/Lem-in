/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:17:02 by anel-bou          #+#    #+#             */
/*   Updated: 2020/11/21 12:53:17 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

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
	dup2(open("maps/holygraph", O_RDONLY), 0);
	printf("___________________________________\n");
	env = (t_env *)malloc(sizeof(t_env));
	initialize_var(env);
	input_to_list(env);
	save_input(env);

	test_loop(env, "42_Commandements");
	test_loop(env, "Filit");
	test_loop(env, "ft_printf");
	test_loop(env, "Get_Next_line");
	test_loop(env, "libft");
	test_loop(env, "Piscine_Reloaded");
	test_loop(env, "KFS_4");
	test_loop(env, "KFS_3");
	test_loop(env, "KFS_2");
	test_loop(env, "roger_skyline_2");
	test_loop(env, "Piscine_Swift_iOS");
	test_loop(env, "Piscine_CPP");
	test_loop(env, "Nm_otool");
	test_loop(env, "Philosophers");
	test_loop(env, "ft_script");
	test_loop(env, "RT");
	test_loop(env, "42sh");
	test_loop(env, "21sh");
	test_loop(env, "Matcha");
	test_loop(env, "Piscine_OCaml");
	
	search4paths(env, 0);

	// print_all_paths(env); 	
	printf("___________________________________\n");
	return (0);
}







































/***********************************/
// {
	// printf("\n");
// }