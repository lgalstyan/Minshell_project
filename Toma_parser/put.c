/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:06:25 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/24 17:48:54 by lgalstya         ###   ########.fr       */
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

int	put_in_out(t_node *node, int s, char c)
{
	int	i;
	int	l;

	i = 0;
	while (node->readline[s])
	{
		l = size_infile(node->readline, s, c) - s;
		if (node->readline[s] == c)
		{
			node->infile[i] = malloc(l);
			node->infile[i] = ft_substr(node->readline, s, l);
			s += l;
			i++;
		}
		s++;
	}
	i = 0; 
	while (node->infile[i])
	{
		printf("\n\nn->inf %d = %s\n", i, node->infile[i]);
		i++;
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

int	put_hd_app(t_node *node, int s, char *c)
{
	int	i;
	int	l;

	i = 0;
	while (node->readline[s])
	{
		l = size_heredoc(node->readline, s, c) - s;
		if (node->readline[s] == c[0] && node->readline[s + 1] == c[1])
		{
			node->heredoc[i] = malloc(l);
				node->heredoc[i] = ft_substr(node->readline, s, l);
			s += l;
			i++;
		}
		s++;
	}
	i = 0;
	while (node->heredoc[i])
	{
		printf("\n\nn->her %d = %s\n", i, node->heredoc[i]);
		i++;
	}
	// int	i;
	// int	l;

	// i = 0;
	// l = pars_ft_strlen(node->readline);
	// node->heredoc = malloc(sizeof(char *));
	// while (node->readline[s] && s < l)
	// {
	// 	if (node->readline[s] && node->readline[s] != ' ')	
	// 	{
	// 		node->heredoc[i] = ft_strdup(node->readline + s);
	// 		s += pars_ft_strlen(node->heredoc[i]);
	// 	}
	// 	if (node->readline[s] != ' ' && node->readline[s])
	// 	{
	// 		ft_strcpy(node->heredoc[i], node->readline + s);
	// 		s += pars_ft_strlen(node->heredoc[i]);
	// 	}
	// 	else
	// 		return(s);
	// 	++i;
	// 	++s;
	// }
	return (s);
}


int	put_ap(t_node *node, int s)
{
	int	i;
	int	l;

	i = 0;
	l = pars_ft_strlen(node->readline);
	node->append = malloc(sizeof(char *));
	while (node->readline[s] && s < l)
	{
		if (node->readline[s] && node->readline[s] != ' ')	
		{
			node->append[i] = ft_strdup(node->readline + s);
			s += pars_ft_strlen(node->append[i]);
		}
		if (node->readline[s] != ' ' && node->readline[s])
		{
			ft_strcpy(node->append[i], node->readline + s);
			s += pars_ft_strlen(node->append[i]);
		}
		else
			return(s);
		++i;
		++s;
		}
	return (s);
}
