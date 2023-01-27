/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:59:37 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/27 16:21:22 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h" 

static	t_node	*initialize(char *str, t_node *node)
{
	node->readline = ft_strdup(str);
	node->next = NULL;
	return (node);
}


t_node *lexer(char *str)
{
	int		i;
	char	**sp;
	t_node	*node;
	t_node	*new;
  
	new = malloc(sizeof(t_node));
	i = 0;
	node = NULL;
	if (!checkquotes(str))
	{
		printf("Syntax error: the number of quotes is incorrect\n");
		return (0);
	}
	sp = pars_ft_split(str, '|');
	while (i < ft_wcount(str, '|') && sp[i])
	{
		initialize(sp[i], new);
		ft_lstadd_back(&node, new);
		printf("%s", node->readline);
		++i;
	}
	return (node);
}