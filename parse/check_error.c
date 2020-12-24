/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:19:55 by anel-bou          #+#    #+#             */
/*   Updated: 2020/12/24 08:33:32 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

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

void ft_free_doubld_table(char ***table)
{
	int i;

	i = -1;
	while((*table)[++i])
		free((*table)[i]);
	free(*table);
}

int		ft_str_is_num(char *str)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(str);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	if (len > 19 || len == 0)
		return (0);
	return (1);
}

int		ft_str_is_name(char *str)
{
	int i;

	i = -1;
	if (str[0] == '#' || str[0] == 'L')
		return (0);
	while (str[++i])
		if (!ft_isprint(str[i]))
			return (0);
	return (1);
}

int		ft_check_link(char *line, char **out)
{
	char **table;
	int i;
	int ret;

	ret = 0;
	table = ft_strsplit(line, '-');
	if (table[0] && table[1] && !(table[2]) &&
	ft_str_is_name(table[0]) && ft_str_is_name(table[1]))
		ret = 1;
	ft_free_doubld_table(&table);
	if (ret)
		*out = line;
	return (ret);
}

int		ft_check_room(char *line, char **out, int *section)
{
	char **table;
	int i;
	int ret;

	ret = 0;
	table = ft_strsplit(line, ' ');
	if (table[0] && table[1] && table[2] && !(table[3]) &&
	ft_str_is_name(table[0]) &&
	ft_str_is_num(table[1]) && ft_str_is_num(table[2]) &&
	(ft_atoi(table[1]) >= 0 ) && (ft_atoi(table[2]) >= 0))
		ret = 1;
	ft_free_doubld_table(&table);
	if (ret)
		*out = line;
	if (section && !ret && ft_strchr(line, '-') && ft_check_link(line, out))
		*section = 2;
	return (ret);
}

int		check_error(t_inp **inp, char **line, int *section)
{
	int msg;
	int tmp;
	
	if (!((*inp)->line))
		return (INP_END);
	if (*section == 1)
	{
		if (ft_strequ((*inp)->line, "##start") && (*inp = (*inp)->next))
			return (ft_check_room((*inp)->line, line, NULL)? START : ERROR);
		else if (ft_strequ((*inp)->line, "##end") && (*inp = (*inp)->next))
			return (ft_check_room((*inp)->line, line, NULL)? END : ERROR);
		else if ((*inp)->line[0] == '#')
			return (COMMENT);
		else if (*section == 1 && ft_check_room((*inp)->line, line, section))
			return (ROOM);
	}
	else if (*section == 2)
	{
		if (ft_strequ((*inp)->line, "##end") || ft_strequ((*inp)->line, "##start"))
			return (ERROR);
		else if ((*inp)->line[0] == '#')
			return (COMMENT);
		else if (*section == 2 && ft_check_link((*inp)->line, line))
			return (LINK);
	}
	return (ERROR);
}
