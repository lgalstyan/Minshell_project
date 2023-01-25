/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:13:03 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/25 12:46:58 by lgalstya         ###   ########.fr       */
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
// static int	is_space(char *str)
// {
// 	int	i;

// 	i = -1;
// 	while (str && str[++i])
// 		if (str[i] != ' ')
// 			return (0);
// 	return (1);
// }

// char	*pars_cmd(t_node *data, char *str, int index)
// {
// 	int			i;
// 	static int	l = 0;

// 	i = 0;
// 	if (is_space(str))
// 		return (NULL);
// 	if (str[i + index] == '"')
// 	{
// 		++i;
// 		while (str[i + index] && str[i + index] != '"')
// 			++i;
// 		++i;
// 	}
// 	else
// 		while (str[i + index] && is_meta(str[i + index]))
// 			++i;
// 	data->cmd[l] = ft_substr(str, index, i);
// 	// printf("cmd[%d] = !%s!\n\n", l, data->cmd[l]);
// 	++l;
// 	if (l == 3)
// 		l = 0;
// 	return (ft_strcut(str, index, i));
// }
