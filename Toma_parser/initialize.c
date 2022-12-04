/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:34:10 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/04 18:24:39 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*initialize(char *str, t_node *node)
{
	int		i;

	//node->cmd[0] = ft_strdup(str);
	//printf("%s", node->cmd[0]);
	i = 0;
	i += put_cmd(node, str, i);
	//i = ft_strlen(node->cmd[0]);
	//while (str && str[i])
	//{
		//if (str[i] == ' ')
		//{
		//write(1, "hello\n", 6);
		//	++i;
		//}
		/*if (str[i] == '<' && str[i] + 1 != '<')
		{
			i += put_in(node, str, i);
		}
		write(1, "hello\n", 6);
		++i;*/
		/*else if (*str == '>' && *str + 1 == '>')
			put_heardock(&node, &str);
		else if (*str == '<' && *str + 1 != '<')
			put_out(&node, &str);
		else if (*str == '<' && *str + 1 == '<')
			put_append(&node, &str);*/
	//}
	node->next = NULL;
	return (node);
}
