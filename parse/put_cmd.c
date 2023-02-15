/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:13:03 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/30 13:24:52 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ignore_quotes(char *str)
{
	int	i;

	i = 0;
	if (str && str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
	}
	if (str && str[i] == '\'')
	{
		i++;
		while (str && str[i] != '\'')
			i++;
	}
	return (i);
}

static int	size_curr_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (ignore_quotes(str + i))
			return (count + ignore_quotes(str + i));
		if (is_space(str[i]))
			return (count);
		count++;
		i++;
	}
	return (count);
}

int	put_cmd(t_node *node, int index)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	if (!ft_strlen(node->readline))
		return (-1);
	while (index <= ft_strlen(node->readline) && node->readline[index]
		&& i < node->counts.s_cmd)
	{
		l = size_curr_str(node->readline + index);
		if (l != 0)
		{
			node->cmd[i] = ft_substr(node->readline, index, l + 1);
			index += l;
			i++;
		}
		else
		{
			if (!node->readline[index])
				break ;
			index++;
		}
	}
	node->cmd[i] = NULL;
	return (index);
}
