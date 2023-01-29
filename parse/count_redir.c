/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:04:31 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/28 18:37:56 by tyenokya         ###   ########.fr       */
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
        // petqa poxel nenc vor ft_strcuty lcni nayev node->inflie[i]-n u iran stugel voch te while "(node->infile[i])" - ov stugel
        // sranuv u mtnel kanchel
        //heredocy chi lcnum appendnel dra hamarel ft_strcut chi gnum stugeci ifov heredocy chkar
		node->readline = ft_strcut(node->readline, node->infile[i]);
        printf("1 = %s\n 1.1 = %s\n", node->readline, node->infile[i]);
        i++;
    }
    i = 0;
	while (node->outfile[i])
    {
		node->readline = ft_strcut(node->readline, node->outfile[i]);
        printf("2 = %s\n", node->readline);
        i++;
    }
    i = 0;
    if (node->heredoc[i])
        printf("~~~~~~~~~~~~\n");
	while (node->heredoc[++i])
    {
		node->readline = ft_strcut(node->readline, node->heredoc[i]);
        printf("3 = %s\n", node->readline);
        i++;
    }
    i = 0;
	while (node->append[++i])
    {
		node->readline = ft_strcut(node->readline, node->append[i]);
        printf("4 = %s\n", node->readline);
        i++;
    }
    return (node);
}
