/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:34:10 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/28 17:44:57 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	initial_nodes(t_node *node)
{
	int	i;
	int r;

	r = 0;
	i = 0;
	// r += put_cmd(node, r);
	while (node->readline && node->readline[i])
	{
		// if (node->readline[i] == '\"')
		// 	while (node->readline[++i] != '\"')
		// 		;
		if (node->readline[i] == '>' && node->readline[i + 1] == '>')
			put_hd_app(node, ">>");
		else if (node->readline[i] == '<' && node->readline[i + 1] == '<')
			put_hd_app(node, "<<");
		else if (node->readline[i] == '>' && node->readline[i + 1] != '>')
			put_in_out(node, '>');
		else if (node->readline[i] == '<' && node->readline[i + 1] != '<')
			put_in_out(node, '<');
		++i;
	}
	node = cut_redir(node);
	if (node->readline)
		printf("--=++%s\n", node->readline);
	r += put_cmd(node, r);
	
}
