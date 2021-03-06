/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:19:17 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/02 12:11:56 by anel-bou         ###   ########.fr       */
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

// void print_all_paths(t_env *env)
// {
// 	t_ptheads *pthead;
// 	t_path *pth;

// 	pthead = env->ptheads;
// 	while (pthead)
// 	{
// 		pth = pthead->path;
// 		printf("[%d] ", pthead->ants);

		// while (pth)
		// {
		// 	printf("%s->", pth->room->name);
		// 	pth = pth->next;
		// }
// 		pthead = pthead->next;
// 		printf("\n");
// 	}
// }

void print_all_paths(t_env *env)
{
	t_pathGroup *grp;
	t_ptheads	*head;
	t_path		*path;
	int headNb;

	grp = env->pathGroup;
	while (grp)
	{
		printf("\033[0;32m");
		printf("\n\tGroupNumber=[%d] <> Score=[%d] <> TotalHeads=[%d] <> RoomsInGrp=[%d]\n", grp->groupNumber, grp->score, grp->totalHeads, grp->totalRoomsInGroup);
		head = grp->head;
		headNb = 0;
		while (head)
		{
			printf("\033[0;36m");
			printf("   PATHnumber=%d ", ++headNb);
			printf("\033[0;37m");
			path = head->path;
			while (path)
			{
				printf("%s->", path->room->name);
				path = path->next;
			}
			printf("\n");
			head = head->next;
		}
		grp = grp->next;
	}
	printf("\nAnts=[%d]\n", env->antsnb);
	printf("BestGroup=[%d]\n", env->bestGroup->groupNumber);
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
	
	t_path		**path;
	t_path		**tmp2;

	ptr = &((*pthds)->next);
	while (*ptr)
	{
	
		printf("pointer %p\n", *ptr);
		path = &((*ptr)->path);
		while (*path)
		{
			tmp2 = &((*path)->next);
			printf("\t%p{%p}\n", path, *path);
			ft_memdel((void **)path);
			path = tmp2;
		}
		tmp = &((*ptr)->next);
		ft_memdel((void **)ptr);
		ptr = tmp;
	}
}
*/