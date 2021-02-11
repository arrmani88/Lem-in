/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:48:40 by youarzaz          #+#    #+#             */
/*   Updated: 2021/01/09 16:48:49 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_room(char *str)
{
	int i;
	int wrd;
	int spc;

	i = -1;
	wrd = 0;
	spc = 0;
	if (str && str[0] == '#')
		return (0);
	if (str[++i] && ft_isalnum(str[i]) && ++wrd)
		while (str[++i] && ft_isalnum(str[i]))
			;
	if (str[i] == '-')
		return (0);
	if (str[i] == ' ')
		++spc;
	if (str[i] && str[++i] && ft_isdigit(str[i]) && ++wrd)
		while (ft_isdigit(str[++i]))
			;
	if (str[i] == ' ')
		++spc;
	if (str[i] && str[++i] && ft_isdigit(str[i]) && ++wrd)
		while (str[++i] && ft_isdigit(str[i]))
			;
	return ((wrd == 3 && spc == 2) ? 1 : 0);
}

int		input_to_list(t_env *env)
{
	t_inp	*ptr;
	char	*line;

	if (get_next_line(0, &line, 0) <= 0 ||
	!(env->inp = (t_inp *)malloc(sizeof(t_inp))))
		return (0);
	env->inp->next = NULL;
	ptr = env->inp;
	ptr->line = line;
	env->nbrooms = is_room(line);
	while (get_next_line(0, &line, 0) > 0)
	{
		ptr->next = (t_inp *)malloc(sizeof(t_inp));
		ptr = ptr->next;
		ptr->line = line;
		ptr->next = NULL;
		env->nbrooms += is_room(line);
	}
	ft_strdel(&line);
	return (1);
}
