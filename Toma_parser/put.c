/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:06:25 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/04 17:28:01 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	put_in(t_node *node, char *str, int s)
{
	int	i;

	i = 0;
	//write(1, "hello\n", 6);
	if (str)
	{
		if (str[s] != ' ' && str[s])
		{
			printf("baby %d %s\n", s, str + s);
			node->infile[i] = ft_strdup(str + s);
			//ft_strcpy(node->infile[i], str + s);
			printf("cucu %s\n", node->infile[i]);
			s = ft_strlen(node->infile[i]);
		}
		/*while (*str[s] != ' ' && *str[s])
		{
			*node->infile[i]++ = *str[s]++;
			write(1, &*node->infile[i], 1);
			++s;
		}*/
		++i;
	}
	return (s);
}
