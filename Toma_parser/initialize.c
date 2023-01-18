/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:34:10 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 16:29:20 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*initialize(char *str, t_node *node)
{
	int		i;

	i = 0;
	
	str = rm_space(str);
	i += put_cmd(node, str, i);
	while (str && str[i])
	{
		if (str[i] == '\"')
			while (str[++i] != '\"')
				;
		if (str[i] == '>' && str[i + 1] == '>')
			i += put_hd(node, str, i);
		else if (str[i] == '<' && str[i + 1] == '<')
			i += put_ap(node, str, i);
		else if (str[i] == '>' && str[i + 1] != '>')
			i += put_in(node, str, i);
		else if (str[i] == '<' && str[i + 1] != '<')
			i += put_out(node, str, i);
		++i;
	}
	node->next = NULL;
	node->redir = fill_redir(str, node); 
	return (node);
}
