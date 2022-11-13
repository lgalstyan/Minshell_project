/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:34:10 by tyenokya          #+#    #+#             */
/*   Updated: 2022/11/13 17:23:05 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	initialize(char *str)
{
	//int		i;
	t_node	node;
	
	//i = 0;
	while (*str != ' ')
		*node.cmd[0]++ = *str++;
	/*while (*str)
	{
		if (*str == ' ')
			++*str;
		if (*str == '>' && *str + 1 != '>')
			put_in(&node, &str);
		else if (*str == '>' && *str + 1 == '>')
			put_heardock(&node, &str);
		else if (*str == '<' && *str + 1 != '<')
			put_out(&node, &str);
		else if (*str == '<' && *str + 1 == '<')
			put_append(&node, &str);
	}*/
	return (node);
}
