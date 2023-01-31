/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:08:52 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/20 16:09:56 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static int	cnt_word(char *str, char delim)
{
	int	prev_del;
	int	i;
	int	count;

	i = 0;
	count = 0;
	prev_del = 1;
	while (str[i])
	{
		if (str[i] == delim)
			prev_del = 1;
		else if (prev_del)
			count++;
		if (str[i] != delim)
			prev_del = 0;
		i++;
	}
	return (count);
}

static void	*fr(char **s, int i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (0);
}
*/
static char	*ml(char *s, int st, int len)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	while (s[st] && i < len)
	{
		tab[i] = s[st];
		st++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split_export(char *s, char c)
{
	char	**tab;
	int		start;

	start = -1;
	tab = malloc(sizeof(char **) * 3);
	if (!(tab) || !s)
		return (0);
	while (s[++start])
		if (s[start] && s[start] == c)
		{
			tab[0] = ml(s, 0, start);
			if (s[start + 1])
			{
				tab[1] = ml(s, start + 1, ft_strlen(s) - start - 1);
				tab[2] = 0;
				return (tab);
			}
			else
			{
				tab[1] = 0;
				return (tab);
			}
		}
	return (tab);
}

static	int	gtav(char *s, char c)
{
	int	count;
	int	i;
	int	l;

	i = -1;
	count = 1;
	l = ft_strlen(s);
	while (s[++i] && s[i] == c)
		;
	while (s[--l] && s[l] == c && i < l)
		;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < l)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*lcnel(char *s,	int h,	int l)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	while (++i < l)
		str[i] = s[h + i];
	str[i] = 0;
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		h;
	int		t;
	int		i;
	int		count;
	char	**str;

	h = 0;
	i = -1;
	count = gtav(s, c);
	str = malloc(sizeof(char *) * (count + 1));
	if (!s || !str)
		return (NULL);
	while (++i < count)
	{
		while (s[h] && s[h] == c)
			h++;
		t = h;
		while (s[t] && s[t] != c)
			t++;
		str[i] = lcnel(s, h, t - h);
		h = t;
	}
	str[i] = 0;
	return (str);
}
