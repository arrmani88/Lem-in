/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dept_layers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:07:32 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 17:07:36 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	set_dept_layers_c2(t_env *env, t_norm_sdl *sdl)
{
	sdl->dept = 2;
	sdl->last = (t_queue*)malloc(sizeof(t_queue));
	sdl->last->room = env->start;
	sdl->last->next = NULL;
	sdl->first = sdl->last;
	env->start->dept_layer = 1;
}

void	set_dept_layers(t_env *env)
{
	t_norm_sdl sdl;

	set_dept_layers_c2(env, &sdl);
	while (sdl.first)
	{
		sdl.lnk = sdl.first->room->link;
		while (sdl.lnk)
		{
			if (sdl.lnk->room->dept_layer == -1)
			{
				sdl.lnk->room->dept_layer = sdl.dept;
				sdl.last->next = (t_queue *)malloc(sizeof(t_queue));
				sdl.last = sdl.last->next;
				sdl.last->room = sdl.lnk->room;
				sdl.last->next = NULL;
			}
			sdl.lnk = sdl.lnk->next;
		}
		sdl.dept++;
		sdl.tmp = sdl.first->next;
		ft_memdel((void **)&(sdl.first));
		sdl.first = sdl.tmp;
	}
}
