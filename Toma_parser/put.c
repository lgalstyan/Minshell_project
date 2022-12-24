/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:06:25 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/24 15:34:20 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	put_in(t_node *node, char *str, int s)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(str);
	//write(1, "hello\n", 6);
	while (str[s] && s < l)
	{
		if (str[s] && str[s] != ' ')
		{
			node->infile[i] = ft_strdup(str + s);
			//ft_strcpy(node->infile[i], str + s);
			printf("infile[%d] = %s\n", i, node->infile[i]);
			s = ft_strlen(node->infile[i]);
		}
		if (str[s] != ' ' && str[s])
		{
			ft_strcpy(node->infile[i], str + s);
			write(1, &*node->infile[i], 1);
			s += ft_strlen(node->infile[i]);
		}
		++i;
	}
	return (s);
}
