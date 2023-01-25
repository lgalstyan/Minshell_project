/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:06:25 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/25 13:38:41 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_meta(char c)
{
	if (ft_strchr(METACHARACTERS, c) != 0)
		return (1);
	return (0);
}

static int size_infile(char *str, int i, char c)
{
	if (str[i] == c)
	{
		i++;
		while (str[i] && is_meta(str[i]))
			i++;
		while (str[i] && !is_meta(str[i]))
			i++;
	}
	return (i);
}

int	put_in_out(t_node *node, char c)
{
	int	i;
	int	l;
	int	start;
	int	s;

	i = 0;
	s = 0;
	start = 0;
	while (node->readline[start])
	{
		l = size_infile(node->readline, start, c) - start;
		if (node->readline[start] == c && node->readline[start + 1] != c
			&& ((start - 1 < 0) || ((start - 1) >= 0 && node->readline[start - 1] != c)))
		{
			if (c == '<')
				node->infile[i] = ft_substr(node->readline, start, l);
			else if (c == '>')
				node->outfile[i] = ft_substr(node->readline, start, l);
			s += l;
			i++;
		}
		start++;
	}
	return (s);
}

static int size_heredoc(char *str, int i, char *c)
{
	if (pars_ft_strlen(c) != 2)
		return (0);
	if (str[i] == c[0] && str[i + 1] == c[1])
	{
		i += 2;
		while (str[i] == c[0])
			i++;
		while (str[i] && is_meta(str[i]))
			i++;
		while (str[i] && !is_meta(str[i]))
			i++;
	}
	return (i);
}

int	put_hd_app(t_node *node, char *c)
{
	int	i;
	int	l;
	int start;
	int	s;

	i = 0;
	s = 0;
	start = 0;
	while (node->readline[start])
	{
		l = size_heredoc(node->readline, start, c) - start;
		if (node->readline[start] == c[0] && node->readline[start + 1] == c[1])
		{
			if (c[0] == '<')
				node->heredoc[i] = ft_substr(node->readline, start, l);
			else if (c[0] == '>')
				node->append[i] = ft_substr(node->readline, start, l);
			s += l;
			i++;
		}
		start++;
	}
	return (s);
}
