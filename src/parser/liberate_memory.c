/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:48:58 by youarzaz          #+#    #+#             */
/*   Updated: 2021/02/12 18:52:57 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_rooms(t_env *env)
{
	int		i;
	t_link	*link;
	t_room	*room;
	char *tmp;

	i = -1;
	while (++i < env->nbrooms)
	{
		while(env->room[i])
		{
			room = env->room[i]->next;
			while (env->room && env->room[i] && env->room[i]->link)
			{
				link = env->room[i]->link->next;
				free(env->room[i]->link);
				env->room[i]->link = link;
			}
			if (env->room[i])
			{
				free(env->room[i]->name);
				free(env->room[i]);
			}
			env->room[i] = room;
		}
	}
	if (env->room)
		free(env->room);
	get_next_line(0, &tmp, 1);
}

void	liberate_memory(t_env *env)
{
	t_path_group	*group_tmp;
	t_ptheads	*head_tmp;
	t_path		*path_tmp;

	while (env->path_group)
	{
		group_tmp = env->path_group->next;
		while (env->path_group->head)
		{
			head_tmp = env->path_group->head->next;
			// printf("\npath >> ");
			while (env->path_group->head->path)
			{
				path_tmp = env->path_group->head->path->next;
				// printf("%s->", env->path_group->head->path->room->name);
				free(env->path_group->head->path);
				env->path_group->head->path = path_tmp;
			}
			free(env->path_group->head);
			env->path_group->head = head_tmp;
		}
		free(env->path_group);
		env->path_group = group_tmp;
	}
	free_rooms(env);
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

void	ft_free_doubld_table(char ***table)
{
	int i;

	i = -1;
	while ((*table)[++i])
		free((*table)[i]);
	free(*table);
}
