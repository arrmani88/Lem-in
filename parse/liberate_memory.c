/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:50:09 by anel-bou          #+#    #+#             */
/*   Updated: 2020/11/17 14:19:37 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	liberate_memory()
{
	/*  memory to liberate  */
	exit(0);
}

void	delete_heads_rest(t_ptheads *ptr)
{
	t_ptheads *tmp;

	if (!ptr)
		return ;
	ptr = ptr->next;
	while (ptr)
	{
		tmp = ptr->next;
		ft_memdel((void **)ptr);
		ptr = tmp;
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