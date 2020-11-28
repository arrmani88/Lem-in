/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:51:04 by anel-bou          #+#    #+#             */
/*   Updated: 2020/11/11 18:51:28 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		rooms_count(char *str)
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
	if (str[i] == ' ' && ++spc)
		;
	if (str[++i] && ft_isdigit(str[i]) && ++wrd)
		while (ft_isdigit(str[++i]))
			;
	if (str[i] == ' ' && ++spc)
		;
	if (str[++i] && ft_isdigit(str[i]) && ++wrd)
		while (str[++i] && ft_isdigit(str[i]))
			;
	return ((wrd == 3 && spc == 2) ? 1 : 0);
}

void	input_to_list(t_env *env)
{
	t_inp	*ptr;
	char	*line;

	get_next_line(0, &line);
	env->inp = (t_inp *)malloc(sizeof(t_inp));
	env->inp->next = NULL;
	ptr = env->inp;
	ptr->line = line;
	env->nbrooms = rooms_count(line);
	while (get_next_line(0, &line))
	{
		ptr->next = (t_inp *)malloc(sizeof(t_inp));
		ptr = ptr->next;
		ptr->line = line;
		ptr->next = NULL;
		env->nbrooms += rooms_count(line);
	}
	// ptr = NULL;
}
