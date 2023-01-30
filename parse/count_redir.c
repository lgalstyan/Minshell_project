/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:04:31 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/30 12:52:51 by tyenokya         ###   ########.fr       */
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
	if (node->readline)
		printf("readline is:%s\n", node->readline);
		node->readline = ft_strcut(node->readline, node->infile[i]);
		i++;
	}
	if (node->readline)
		printf("readline is:%s\n", node->readline);
	i = 0;
	while (node->outfile[i])
	{
		node->readline = ft_strcut(node->readline, node->outfile[i]);
		i++;
	}
	if (node->readline)
		printf("readline is:%s\n", node->readline);
	i = 0;
	while (node->heredoc[i])
	{
		node->readline = ft_strcut(node->readline, node->heredoc[i]);
        i++;
	}
	if (node->readline)
		printf("readline is:%s\n", node->readline);
	i = 0;
	while (node->append[i])
	{
		node->readline = ft_strcut(node->readline, node->append[i]);
		i++;
	}
	if (node->readline)
		printf("readline is:%s\n", node->readline);
	return (node);
}
