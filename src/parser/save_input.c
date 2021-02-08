/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:49:10 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 16:49:14 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	fill_room_c1(t_env *env, char *str, int msg, int i)
{
	env->ptr->next = NULL;
	msg == START ? env->start = env->ptr : 0;
	msg == END ? env->end = env->ptr : 0;
	env->ptr->name = env->tmp;
	env->ptr->x = ft_atoi(&str[i]);
	while (str[++i] && str[i] != ' ')
		;
	env->ptr->y = ft_atoi(&str[i]);
	env->ptr->iterated = 0;
	env->ptr->used = 0;
	env->ptr->full = 0;
	env->ptr->link = NULL;
	env->ptr->parent = NULL;
	env->ptr->set_last = 0;
	env->ptr->dept_layer = -1;
	env->ptr->correction_room = 0;
}

void	fill_room(t_env *env, char *str, int msg)
{
	int		i;
	int		r;

	i = -1;
	while (str[++i] && str[i] != ' ')
		;
	env->tmp = ft_strsub(str, 0, i);
	r = get_index(env->nbrooms, env->tmp);
	if (!(env->room[r]))
	{
		env->room[r] = (t_room *)malloc(sizeof(t_room));
		env->ptr = env->room[r];
	}
	else
	{
		env->ptr = env->room[r];
		while (env->ptr->next)
			env->ptr = env->ptr->next;
		env->ptr->next = (t_room *)malloc(sizeof(t_room));
		env->ptr = env->ptr->next;
	}
	fill_room_c1(env, str, msg, i);
}

void	link_two_rooms(t_env *env, char *rm1, char *rm2)
{
	t_room *room1;

	env->ptr = env->room[get_index(env->nbrooms, rm1)];
	while (env->ptr->next && !ft_strequ(env->ptr->name, rm1))
		env->ptr = env->ptr->next;
	room1 = env->ptr;
	if (!(env->ptr->link))
	{
		env->ptr->link = (t_link *)malloc(sizeof(t_link));
		env->lnk = env->ptr->link;
	}
	else
	{
		env->lnk = env->ptr->link;
		while (env->lnk->next)
			env->lnk = env->lnk->next;
		env->lnk->next = (t_link *)malloc(sizeof(t_link));
		env->lnk = env->lnk->next;
	}
	env->lnk->room = get_room(env, rm2);
	if ((room1 == env->start && env->lnk->room == env->end) ||
		(room1 == env->end && env->lnk->room == env->start))
		env->start_end_linked = 1;
	env->lnk->next = NULL;
	env->lnk->flow = 0;
}

void	fill_link(t_env *env, char *line)
{
	char	*rm1;
	char	*rm2;
	int		i;

	i = -1;
	while (line[++i] && line[i] != '-')
		;
	rm1 = ft_strsub(line, 0, i);
	rm2 = &line[++i];
	link_two_rooms(env, rm1, rm2);
	link_two_rooms(env, rm2, rm1);
	ft_strdel(&rm1);
}
