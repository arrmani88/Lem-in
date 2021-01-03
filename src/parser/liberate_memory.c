/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:50:09 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/24 11:57:16 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	free_rooms(t_env *env)
{
	int i;
	t_link *link;

	i = -1;
	while (++i < env->nbrooms)
	{
		while(env->room[i]->link)
		{
			link = env->room[i]->link->next;
			free(env->room[i]->link);
			env->room[i]->link = link;
		}
		free(env->room[i]->name);
		free(env->room[i]);
	}
	free(env->room);

}

void	liberate_memory(t_env *env)
{
	t_pathGroup *group_tmp;
	t_ptheads *head_tmp;
	t_path *path_tmp;

	while(env->pathGroup)
	{
		group_tmp = env->pathGroup->next;
		while(env->pathGroup->head)
		{
			head_tmp = env->pathGroup->head->next;
			while(env->pathGroup->head->path)
			{
				path_tmp = env->pathGroup->head->path->next;
				free(env->pathGroup->head->path);
				env->pathGroup->head->path = path_tmp;
			}
			free(env->pathGroup->head);
			env->pathGroup->head = head_tmp;
		}
		free(env->pathGroup);
		env->pathGroup = group_tmp;
	}
	free_rooms(env);
}

void	delete_heads_rest(t_ptheads *pthds)
{
	t_ptheads	*ptr;
	t_ptheads	*tmp;
	
	t_path		*path;
	t_path		*tmp2;

	ptr = (pthds)->next;
	(pthds)->next = NULL;
	while (ptr)
	{	
		path = (ptr)->path;
		while (path)
		{
			tmp2 = path->next;
			free(path);
			path = tmp2;
		}
		tmp = (ptr)->next;
		free(ptr);
		ptr = tmp;
	}
}

void	delete_path_rest(t_path *ptr)
{
	t_path *tmp;
	t_path *path;

	path = ptr->next;
	ptr->next = NULL;
	while (path)
	{
		tmp = path->next;
		free(path);
		path = tmp;
	}
}