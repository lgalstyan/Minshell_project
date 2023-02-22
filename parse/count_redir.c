/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:04:31 by tyenokya          #+#    #+#             */
/*   Updated: 2023/02/20 14:26:31 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ignore_quotes(char *str, int *i)
{
	while (str && str[*i])
	{
		if (str[*i] == '\"')
		{
			while (str[++*i] && str[*i] != '\"')
				;
			++*i;
		}
		else if (str[*i] == '\'')
		{
			while (str[++*i] && str[*i] != '\'')
				++*i;
		}
		if (!str[*i])
			break ;
		++*i;
	}
}

t_node	*cut_redir(t_node *node)
{
	int	i;

	if (!node)
		return (0);
	i = 0;
	while (node && node->infile && node->infile[i])
	{
		node->readline = ft_strcut(node->readline, node->infile[i]);
		i++;
	}
	i = 0;
	while (node && node->outfile && node->outfile[i])
	{
		node->readline = ft_strcut(node->readline, node->outfile[i]);
		i++;
	}
	i = 0;
	while (node && node->heredoc && node->heredoc[i])
	{
		node->readline = ft_strcut(node->readline, node->heredoc[i]);
		i++;
	}
	i = 0;
	while (node && node->append && node->append[i])
	{
		node->readline = ft_strcut(node->readline, node->append[i]);
		i++;
	}
	return (node);
}
