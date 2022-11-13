/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:38:27 by tyenokya          #+#    #+#             */
/*   Updated: 2022/11/13 15:45:22 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int wcount(char *s, char c)
{
	int	i;
	int	l;
	int	count;

	i = 0;
	count = 1;
	l = ft_strlen(s);
	while (s[++i] && s[i] == ' ')
		;
	while (s[--l] && s[l] == ' ' && i < l)
		;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < l)
	{
		if (s[i] == '\"')
			while (s[++i] != '\"')
				;
		if (s[i] == '\'')
		{
				write(1, "hello\n", 6);
			while (s[++i] != '\'')
			{
				write(1, "hello\n", 6);
			}
		}
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*fill(char *s, size_t h, int l)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(char) * (l + 1));
	while (++i < l)
		str[i] = s[h + i];
	str[i] = 0;
	return (str);
}
	
char	**ft_split(char *s, char c)
{
	int		i;
	int		t;
	int		h;
	int		count;
	char	**sp;

	i = -1;
	h = 0;
	count = wcount(s, c);
	sp = malloc(sizeof(char *) * (count + 1));
	if (!s || !sp)
		return (NULL);
	while (++i < count)
	{
		while (s[h] && s[h] == c)
			++h;
		t = h;
		while (s[t] && s[t] != c)
			++t;
		sp[i] = fill(s, h, t - h);
	write(1, "hello\n", 6);
		h = t;
	}
	sp[i] = 0;
	return (sp);
}


	
/*
static size_t	gtav(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	l;

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

static char	*lcnel(const char *s, size_t h, size_t l)
{
	char	*str;
	size_t	i;

	i = -1;
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	while (++i < l)
		str[i] = s[h + i];
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	h;
	size_t	t;
	size_t	i;
	size_t	count;
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
}*/
