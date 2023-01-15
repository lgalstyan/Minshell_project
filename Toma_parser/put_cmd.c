/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:13:03 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/09 16:23:06 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	put_cmd(t_node *node, char *str, int s)
{
	int	i;
	int l;

	i = 0;
	node->cmd[i++] = ft_strdup(str);
	//str = rm_space(str);
	l = ft_strlen(str);
	s = ft_strlen(node->cmd[0]);
	printf("baby\n");
	while (str[s] && s < l)
	{
		if (str[s] && str[s] != ' ')
		{
			if (str[s - 1] == '-')
				s -= 1;
	/*		if ((str[s] == '\"' || str[s] == '\'') && node->cmd[i] == ft_strdup(str + s))
				s += ft_strlen(node->cmd[i]);*/
			if (str[s] == '<' || str[s] == '>')
				return (s);
			node->cmd[i] = ft_strdup(str + s);
			printf("cmd[%d] = %s\n", i, node->cmd[i]);
			s += ft_strlen(node->cmd[i]);
			printf("s = %d str + s = %s\n", s, str + s);
		}
		else
			return(s);
		write(1, &str+s, 1);
		++i;
		++s;
	}
	return (s);
}
