/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:08:58 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/31 21:34:57 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsplit_tab_alloc(const char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] && str[j] == c)
		j++;
	while (str[j])
	{
		if (str[j] && str[j] == c)
		{
			while (str[j])
				if (str[j] == c)
					j++;
				else
				{
					break ;
				}
			if (str[j])
				i++;
		}
		j++;
	}
	return (i);
}

static char	*ft_strsplit_word_alloc(const char *str, int *start, int end)
{
	char	*tab;
	int		i;

	i = 0;
	tab = (char *)malloc(sizeof(char) * ((end - *start) + 1));
	while (*start < end)
	{
		tab[i] = str[*start];
		i++;
		(*start)++;
	}
	tab[i] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	tab = (char**)malloc(sizeof(char *) * (ft_strsplit_tab_alloc(s, c) + 2));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (j > i)
			tab[k++] = ft_strsplit_word_alloc(s, &i, j);
		else
			i++;
	}
	tab[k] = 0;
	return (tab);
}
