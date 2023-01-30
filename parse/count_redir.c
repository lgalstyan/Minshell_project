/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:04:31 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/30 13:21:05 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*cut_redir(t_node *node)
{
	int	i;

	if (!node)
		return (0);
    i = 0;
	while (node->infile[i])
    {
		node->readline = ft_strcut(node->readline, node->infile[i]);
		i++;
	}
	i = 0;
	while (node->outfile[i])
	{
		node->readline = ft_strcut(node->readline, node->outfile[i]);
		i++;
	}
	i = 0;
	while (node->heredoc[i])
	{
		node->readline = ft_strcut(node->readline, node->heredoc[i]);
        i++;
	}
	i = 0;
	while (node->append[i])
	{
		node->readline = ft_strcut(node->readline, node->append[i]);
		i++;
	}
	return (node);
}
