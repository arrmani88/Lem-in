/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinereptor <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:24:00 by yassinere         #+#    #+#             */
/*   Updated: 2019/04/29 11:17:14 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*get_list(t_list **lst, const int fd)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->content_size == (unsigned int)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_memdel(&(tmp->content));
	ft_lstadd(lst, tmp);
	return (tmp);
}

void		node_remove(t_list **lst, const int fd)
{
	t_list *cur_lst;
	t_list *prev_lst;

	prev_lst = NULL;
	cur_lst = *lst;
	while (cur_lst != NULL)
	{
		if (cur_lst->content_size == (size_t)fd)
		{
			if (prev_lst == NULL)
				*lst = cur_lst->next;
			else
				prev_lst->next = cur_lst->next;
			free(cur_lst->content);
			free(cur_lst);
			cur_lst = NULL;
			return ;
		}
		prev_lst = cur_lst;
		cur_lst = cur_lst->next;
	}
}

int			get_new_line(t_list **lst, char **line, const int fd, char **buf)
{
	char *tmp;

	if ((tmp = ft_strchr(*buf, '\n')))
	{
		*tmp = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, *buf);
		ft_memdel((void **)&tmp);
		free((*lst)->content);
		(*lst)->content = ft_strdup(ft_strchr(*buf, '\0') + 1);
		ft_memdel((void **)buf);
		return (-1);
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(tmp, *buf);
		ft_memdel((void **)&tmp);
		ft_strclr(*buf);
	}
	return (read(fd, *buf, BUFF_SIZE));
}

int			ft_free_leak(char **buf, t_list **head)
{
	t_list *prev;
	t_list *tmp;

	ft_strdel(buf);
	tmp = *head;
	while (tmp)
	{
		prev = tmp->next;
		free(tmp);
		tmp = prev;
	}
	return (0);
}

int			get_next_line(const int fd, char **line, int flag)
{
	t_list			*lst;
	char			*buf;
	static t_list	*head;
	int				ret;

	buf = ft_strnew(BUFF_SIZE);
	if (!buf || fd < 0 || !line || (ret = read(fd, buf, 0)) < 0)
		return (-1);
	if (flag)
		return (ft_free_leak(&buf, &head));
	lst = get_list(&head, fd);
	ret = 1;
	if (lst->content != NULL)
		ft_strcpy(buf, lst->content);
	*line = ft_strnew(BUFF_SIZE);
	while (ret > 0)
		if ((ret = get_new_line(&lst, line, fd, &buf)) == -1)
			return (1);
	ft_memdel((void **)&buf);
	node_remove(&head, fd);
	if (!ret && ft_strlen(*line) > 0)
		return (1);
	return (ret > 0);
}