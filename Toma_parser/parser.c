/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:25:38 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/24 17:28:08 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *parser(char *str)
{
	int		i;
	char	**sp;
	t_node	*node;
	t_node	*new;

	new = malloc(sizeof(t_node));
	i = 0;
	node = NULL;
	if (!checkquotes(str))
		return (0);
	sp = ft_split(str, '|');
	i = 0;
	while (i < wcount(str, '|') && sp[i])
	{
		initialize(sp[i], new);
		ft_lstadd_back(&node, new);
		++i;
	}
	return (node);
}
