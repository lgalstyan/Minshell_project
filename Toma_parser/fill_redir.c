/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:13:20 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 15:12:48 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int *fill_redir(char *str, t_node *node)
{
	int i;
	int	r;

	i = 0;
	r = -1;
	node->redir = malloc(count_redir(node));
	while (str[i++])
	{
		if (str[i] == '\"')
			while (str[++i] != '\"')
				;
		if (str[i] == '\'')
			while (str[++i] != '\'')
				;
		if (str[i] == '<' && str[i + 1] != '<' && str[i - 1] != '<')
			node->redir[++r] = 5;
		else if (str[i] == '<' && str[i + 1] == '<')
			node->redir[++r] = 6;
		else if (str[i] == '>' && str[i + 1] != '>' && str[i - 1] != '>')
			node->redir[++r] = 7;
		else if (str[i] == '>' && str[i + 1] == '>')
			node->redir[++r] = 8;
	}
//	printf("*****%d\n", r);
//	node->redir[++r] = 0;
//	printf("*****%d\n", r);
	return (node->redir);
}
