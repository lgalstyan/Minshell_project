/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:38:27 by tyenokya          #+#    #+#             */
/*   Updated: 2023/02/18 16:27:08 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wcount(char *s, char c)
{
	int	i;
	int	l;
	int	count;

	i = 0;
	count = 1;
	l = ft_strlen(s);
	while (s[i++] && s[i] == ' ')
		;
	while (s[--l] && s[l] == ' ' && i < l)
		;
	// if (i == ft_strlen(s))
	// 	return (0);
	while (s[i] && i < l)
	{
		if (s[i] == '\"')
			while (s[++i] != '\"')
				;
		if (s[i] == '\'')
			while (s[++i] != '\'')
				;
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
	if (!str)
		return (NULL);
	while (++i < l)
		str[i] = s[h + i];
	str[i] = 0;
	return (str);
}

char	**pars_ft_split(char *s, char c)
{
	int		i;
	int		t;
	int		h;
	int		count;
	char	**sp;

	i = -1;
	h = 0;
	count = ft_wcount(s, c);
	sp = malloc(sizeof(char *) * (count + 1));
	if (!s || !sp)
		return (NULL);
	while (++i < count)
	{
		while (s[h] && s[h] == ' ')
			++h;
		t = h;
		while (s[t] && s[t] != c)
		{
			if (s[t] == '\"')
				while (s[++t] != '\"')
					;
			++t;
		}
		sp[i] = fill(s, h, t - h);
		h = t + 1;
	}
	sp[i] = 0;
	return (sp);
}
