/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:19:17 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/01 14:11:01 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void test_loop(t_env *env, char *name)
{
	int r;

	r = get_index(env->nbrooms, name);
	env->ptr = env->room[r];
	while (env->ptr->next && !ft_strequ(env->ptr->name, name))
		env->ptr = env->ptr->next;
	printf("name=%s\t:", env->ptr->name);
	env->lnk = env->ptr->link;
	while (env->lnk)
	{
		printf("->%s", env->lnk->room->name);
		env->lnk = env->lnk->next;
	}
	printf("\n");
	usleep(60000);
}

void print_current_queue(t_queue *qu)
{
	t_queue *p;

	p = qu;
	while (p)
	{
		printf("-->%s", p->room->name);
		p = p->next;
	}
	printf("\n");
}

void print_all_paths(t_env *env)
{
	t_ptheads *pthead;
	t_path *pth;

	pthead = env->ptheads;
	while (pthead)
	{
		pth = pthead->path;
		printf("[%d] ", pthead->ants);

		while (pth)
		{
			printf("%s->", pth->room->name);
			pth = pth->next;
		}
		pthead = pthead->next;
		printf("\n");
	}
}

void print_path(t_path *path)
{
	while (path)
	{
		printf("%s->", path->room->name);
		path = path->next;
	}
	printf("\n");
}

/*
void	delete_heads_rest(t_ptheads **pthds)
{
	t_ptheads	**ptr;
	t_ptheads	**tmp;
	t_path		*path;
	t_path		*tmp2;

	// ptr = pthds;
	// if (!(*ptr))
	// 	return ;
	ptr = &(*pthds)->next;
	while (*ptr)
	{
		// path = (*ptr)->path;
		// while (path)
		// {
		// 	tmp2 = path->next;
		// 	ft_memdel((void **)&path);
		// 	path = tmp2;
		// }
		tmp = &(*ptr)->next;
		ft_memdel((void **)ptr);
		ptr = tmp;
	}
}
*/
