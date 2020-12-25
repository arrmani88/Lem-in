/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 18:34:56 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/25 15:16:38 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		get_index(int max, char *str)
{
	int res;
	int	i;

	res = 0;
	i = -1;
	while (str[++i])
		res += str[i];
	return (res %= max);
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
}

void	link_two_rooms(t_env *env, char *rm1, char *rm2)
{
	env->ptr = env->room[get_index(env->nbrooms, rm1)];
	while (env->ptr->next && !ft_strequ(env->ptr->name, rm1))
		env->ptr = env->ptr->next;
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
	if (env->ptr == env->start || env->ptr == env->end ||
		env->lnk->room == env->start || env->lnk->room == env->end)
		env->startEndLinked = 1;
	env->lnk->next = NULL;
	env->lnk->flow = 0;
}

void	fill_link(t_env *env, char *line)
{
	char *rm1;
	char *rm2;
	int i;

	i = -1;
	while (line[++i] && line[i] != '-')
		;
	rm1 = ft_strsub(line, 0, i);
	rm2 = &line[++i];
	link_two_rooms(env, rm1, rm2);
	link_two_rooms(env, rm2, rm1);
	ft_strdel(&rm1);
}

void	set_antsnb(t_inp **inp, t_env *env)
{
	env->antsnb = ft_atoi((*inp)->line);
	*inp = (*inp)->next;
}

// int		save_input(t_env *env)
// {
// 	t_inp	*ptr;
// 	char	*line;
// 	int		msg;

// 	env->room = (t_room **)malloc(sizeof(t_room *) * env->nbrooms);
// 	ft_bzero((t_room **)env->room, sizeof(t_room *) * env->nbrooms);
// 	ptr = env->inp;
// 	set_antsnb(&ptr, env);
// 	while (ptr && (msg = check_error(&ptr, &line)) > 0)
// 	{
// 		if (msg == ERROR)
// 			liberate_memory();
// 		else if (msg == ROOM || msg == START || msg == END)
// 			fill_room(env, line, msg);
// 		else if (msg == LINK)
// 			fill_link(env, line);
// 		ptr = ptr->next;
// 	}
// 	return (0);
// }

int		save_input(t_env *env)
{
	t_inp	*ptr;
	char	*line;
	int		msg;

	env->room = (t_room **)malloc(sizeof(t_room *) * env->nbrooms);
	ft_bzero((t_room **)env->room, sizeof(t_room *) * env->nbrooms);
	ptr = env->inp;
	env->section = 1;
	env->antsnb = 0;
	env->index = 0;
	if (!ft_str_is_num(ptr->line))
		return (0);
	set_antsnb(&ptr, env);
	while (ptr && (msg = check_error(&ptr, &line, &(env->section))))
	{
		if ((msg == END && env->end) || (msg == START && env->start))
			return (0);
		if (msg == ERROR && env->section == 2)
			break;
		else if (msg == ERROR)
			return (0);
		else if (msg == ROOM || msg == END || msg == START)
			fill_room(env, line, msg);
		ptr = ptr->next;
	}
	if (!env->end || !env->start)
		return (0);
	while (ptr && (msg = check_error(&ptr, &line, &(env->section))))
	{
		if (msg == ERROR)
			return (0);
		else if (msg == LINK)
			fill_link(env, line);
		ptr = ptr->next;
	}
	return (1);
}
