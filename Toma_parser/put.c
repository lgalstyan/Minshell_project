/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:06:25 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/24 12:37:45 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	put_in(t_node *node, int s)
{
	int	i;
	int	l;

	i = 0;
	l = pars_ft_strlen(node->readline);
	while (node->readline[s] && s < l)
	{
		if (node->readline[s] && node->readline[s] != ' ')
		{
			node->infile[i] = ft_strdup(node->readline + s);
			s += pars_ft_strlen(node->infile[i]);
		}
		if (node->readline[s] != ' ' && node->readline[s])
		{
			ft_strcpy(node->infile[i], node->readline + s);
			s += pars_ft_strlen(node->infile[i]);
		}
		else
			return(s);;
		++i;
		++s;
	}
	return (s);
}


int	put_out(t_node *node, int s)
{
	int	i;
	int	l;

	i = 0;
	l = pars_ft_strlen(node->readline);
	while (node->readline[s] && s < l)
	{
		if (node->readline[s] && node->readline[s] != ' ')
		{
			if(node->outfile[i] && node->readline + s)
			node->outfile[i] = ft_strdup(node->readline + s);
			s += pars_ft_strlen(node->outfile[i]);
		}
		if (node->readline[s] != ' ' && node->readline[s])
		{
			ft_strcpy(node->outfile[i], node->readline + s);
			s += pars_ft_strlen(node->outfile[i]);
		}
		else
			return(s);;
		++i;
		++s;
	}
	return (s);
}

int	put_hd(t_node *node, int s)
{
	int	i;
	int	l;

	i = 0;
	l = pars_ft_strlen(node->readline);
	node->heredoc = malloc(sizeof(char *));
	while (node->readline[s] && s < l)
	{
		if (node->readline[s] && node->readline[s] != ' ')	
		{
			node->heredoc[i] = ft_strdup(node->readline + s);
			s += pars_ft_strlen(node->heredoc[i]);
		}
		if (node->readline[s] != ' ' && node->readline[s])
		{
			ft_strcpy(node->heredoc[i], node->readline + s);
			s += pars_ft_strlen(node->heredoc[i]);
		}
		else
			return(s);;
		++i;
		++s;
	}
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
