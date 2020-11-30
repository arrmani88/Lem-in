/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:50:09 by anel-bou          #+#    #+#             */
/*   Updated: 2020/11/30 14:41:47 by anel-bou         ###   ########.fr       */
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
	t_ptheads	*tmp;
	t_path		*path;
	t_path		*tmp2;

	ptr = pthds;
	if (!(*ptr))
		return ;
	*ptr = (*ptr)->next;
	while (*ptr)
	{
		path = (*ptr)->path;
		while (path)
		{
			tmp2 = path->next;
			ft_memdel((void **)path);
			path = tmp2;
		}
		tmp = (*ptr)->next;
		ft_memdel((void **)ptr);
		*ptr = tmp;
	}
}

void	delete_path_rest(t_path *ptr)
{
	t_path *tmp;

	ptr = ptr->next;
	while (ptr)
	{
		tmp = ptr->next;
		ft_memdel((void **)ptr);
		ptr = tmp;
	}
}