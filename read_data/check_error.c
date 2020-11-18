/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:19:55 by anel-bou          #+#    #+#             */
/*   Updated: 2020/11/11 18:37:21 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int		detect_room_link(char *str)
{
	int i;

	i = -1;
	while (str[++i] && ft_isalnum(str[i]))
		;
	if (str[i] == ' ')
		return (ROOM);
	if (str[i] == '-')
		return (LINK);
	if (!str[i])
		return (-1);
	return (-1); /*dertha 3la 9bel-->control may reach end of non-void function*/
}

int		check_error(t_inp **inp, char **line)
{
	int msg;
	int tmp;
	if (!((*inp)->line))
		return (INP_END);
	if (ft_strequ((*inp)->line, "##start"))
	{
		*inp = (*inp)->next;
		*line = (*inp)->line;
		msg = START;
	}
	else if (ft_strequ((*inp)->line, "##end"))
	{
		*inp = (*inp)->next;
		*line = (*inp)->line;
		msg = END;
	}
	else
	{
		*line = (*inp)->line;
		msg = detect_room_link((*inp)->line);
	}
	return (msg);
}
