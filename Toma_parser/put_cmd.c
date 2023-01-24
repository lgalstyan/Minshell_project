/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:13:03 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/24 14:15:39 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	put_cmd(t_node *node, int s)
{
	int	i;
	int l;

	i = 0;
	node->cmd = malloc(sizeof(char *) + 50);
	node->cmd[i++] = ft_strdup(node->readline);
	// node->cmd[i] = ft_strdup(NULL);
	//printf("node->cmd[i] = %s\n", node->cmd[0]);

	l = pars_ft_strlen(node->readline);
	s = pars_ft_strlen(node->cmd[0]);
	while (node->readline[s] && s < l)
	{
		if (node->readline[s] && node->readline[s] != ' ')
		{
			if (node->readline[s - 1] == '-')
				s -= 1;
	/*		if ((node->readline[s] == '\"' || node->readline[s] == '\'') && node->cmd[i] == ft_strdup(str + s))
				s += pars_ft_strlen(node->cmd[i]);*/
			if (node->readline[s] == '<' || node->readline[s] == '>')
				return (s);
			node->cmd[i] = ft_strdup(node->readline + s);
			s += pars_ft_strlen(node->cmd[i]);
		}
		else
			return(s);
		++i;
		++s;
	}
	node->cmd[i] = NULL;
	// printf("%s", node->cmd[i]);
	return (s);
}
