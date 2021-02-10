/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:58:13 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 16:58:16 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_antsnb(t_inp **inp, t_env *env)
{
	env->antsnb = ft_atoi((*inp)->line);
	*inp = (*inp)->next;
}

int		save_input_c1(t_env *env, t_inp **ptr, char **line)
{
	int msg;

	env->room = (t_room **)malloc(sizeof(t_room *) * env->nbrooms);
	ft_bzero((t_room **)env->room, sizeof(t_room *) * env->nbrooms);
	(*ptr) = env->inp;
	env->section = 1;
	env->antsnb = 0;
	env->index = 0;
	if (!ft_str_is_num((*ptr)->line))
		return (0);
	set_antsnb(&(*ptr), env);
	while ((*ptr) && (msg = check_error(&(*ptr), line, &(env->section))))
	{
		if ((msg == END && env->end) || (msg == START && env->start))
			return (0);
		if (msg == ERROR && env->section == 2)
			break ;
		else if (msg == ERROR)
			return (0);
		else if (msg == ROOM || msg == END || msg == START)
			fill_room(env, *line, msg);
		(*ptr) = (*ptr)->next;
	}
	return (msg);
}

int		save_input(t_env *env)
{
	t_inp	*ptr;
	char	*line;
	int		msg;

	msg = save_input_c1(env, &ptr, &line);
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
