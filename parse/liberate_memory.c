/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:50:09 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/01 14:13:31 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	liberate_memory()
{
	/*  memory to liberate  */
	exit(0);
}

void	delete_heads_rest(t_ptheads **pthds)
{
	t_ptheads	**ptr;
	t_ptheads	**tmp;
	
	t_path		**path;
	t_path		**tmp2;

	ptr = &((*pthds)->next);
	while (*ptr)
	{
	
		// printf("dakhla\n");
		path = &((*ptr)->path);
		while (*path)
		{
			// printf("address :%p::::::::::::::%s\n", *path, (*path)->room->name);
			tmp2 = &((*path)->next);
			ft_memdel((void **)path);
			// printf("address :%p\n", *path);
			path = tmp2;
		}
		// printf("lkharja\n");	
		
		tmp = &((*ptr)->next);
		ft_memdel((void **)ptr);
		ptr = tmp;
	}
}

void	delete_path_rest(t_path *ptr)
{
	t_path **tmp;
	t_path **path;

	path = &(ptr->next);
	while (*path)
	{
		tmp = &((*path)->next);
		ft_memdel((void **)path);
		path = tmp;
	}
}