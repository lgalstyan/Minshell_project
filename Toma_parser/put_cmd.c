/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:13:03 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/24 15:45:49 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	put_cmd(t_node *node, char *str, int s)
{
	int	i;
	int l;

	i = 0;
	node->cmd[i++] = ft_strdup(str);
	printf("~~~%s\n", str); 
	str = rm_space(str);
	l = ft_strlen(str);
	s = ft_strlen(node->cmd[0]);
	while (str[s] && s < l)
	{
		if (str[s] && str[s] != ' ')
		{
			printf("str = %s\n", str);
			printf("s = %d str + s = %s\n", s, str + s);
			node->cmd[i] = ft_strdup(str + s);
			//ft_strcpy(node->infile[i], str + s);
			printf("cmd[%d] = %s\n", i, node->cmd[i]);
			s += ft_strlen(node->cmd[i]);
			printf("s = %d str + s = %s\n", s, str + s);
		}
		if (str[s] == '-' && str[s + 1])
		{
			ft_strcpy(node->cmd[i], str + s);
			printf("opt cmd[i] = %s\n", node->cmd[i]);
			s += ft_strlen(node->cmd[i]);
		}
		else
			return(s);
		++i;
		++s;
	}
	return (s);
}
