/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:13:03 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/20 15:15:51 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	put_cmd(t_node *node, char *str, int s)
{
	int	i;
	int l;

	i = 0;
	node->cmd = malloc(sizeof(char *));
	node->cmd[i++] = ft_strdup(str);
	// node->cmd[i] = ft_strdup(NULL);
	printf("node->cmd[i] = %s\n", node->cmd[0]);

	l = pars_ft_strlen(str);
	s = pars_ft_strlen(node->cmd[0]);
	while (str[s] && s < l)
	{
		if (str[s] && str[s] != ' ')
		{
			if (str[s - 1] == '-')
				s -= 1;
	/*		if ((str[s] == '\"' || str[s] == '\'') && node->cmd[i] == ft_strdup(str + s))
				s += pars_ft_strlen(node->cmd[i]);*/
			if (str[s] == '<' || str[s] == '>')
				return (s);
			node->cmd[i] = ft_strdup(str + s);
			s += pars_ft_strlen(node->cmd[i]);
		}
		else
			return(s);
		++i;
		++s;
	}
	return (s);
}
