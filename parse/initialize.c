/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:34:10 by tyenokya          #+#    #+#             */
/*   Updated: 2023/02/18 16:31:09 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	initial_nodes(t_node *node)
{
	int	i;
	int	r;

	r = 0;
	i = 0;
	while (node->readline && node->readline[i])
	{
		if (node->readline[i] == '>' && node->readline[i + 1] == '>')
			put_hd_app(node, '>');
		else if (node->readline[i] == '<' && node->readline[i + 1] == '<')
			put_hd_app(node, '<');
		else if (node->readline[i] == '>' && node->readline[i + 1] != '>')
			put_in_out(node, '>');
		else if (node->readline[i] == '<' && node->readline[i + 1] != '<')
			put_in_out(node, '<');
		++i;
	}
	node = cut_redir(node);
	if (!node->readline)
		return (0); // petqa maqrel error tpel u durs gal erevi bayc myus funkcyayum ereviiiiiii
	node->cmd = pars_ft_split(node->readline, ' ');
	r += ft_wcount(node->readline, ' ');
	free(node->readline);
	return (1);
}
