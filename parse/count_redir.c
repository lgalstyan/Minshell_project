/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:04:31 by tyenokya          #+#    #+#             */
/*   Updated: 2023/03/10 15:13:12 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ignore_quotes(char *str, int *i)
{
	while (str && str[*i])
	{
		if (str[*i] == '\"')
		{
			while (str[++*i] && str[*i] != '\"')
				;
			++*i;
		}
		else if (str[*i] == '\'')
		{
			while (str[++*i] && str[*i] != '\'')
				++*i;
		}
		if (!str[*i])
			break ;
		++*i;
	}
}

int	is_cmd(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] == ' ')
		i++;
	while (s && s[i])
	{
		if (s[i] == '<' || s[i] == '>')
			return (0);
		i++;
	}
	return (1);
}

void	cut_redir2(t_node **node, int flag)
{
	int		i;
	char	*str;

	i = -1;
	(void)flag;
	while ((*node) && (*node)->heredoc && (*node)->heredoc[++i])
	{
		str = ft_strdup((*node)->readline);
		free((*node)->readline);
		(*node)->readline = ft_strcut(str, (*node)->heredoc[i]);
		if (!flag && str && !ft_strcmp(str, (*node)->heredoc[i]))
			free(str);
		str = 0;
	}	
	i = -1;
	while ((*node) && (*node)->append && (*node)->append[++i])
	{
		str = ft_strdup((*node)->readline);
		free((*node)->readline);
		(*node)->readline = ft_strcut(str, (*node)->append[i]);
		if (!flag && str && !ft_strcmp(str, (*node)->append[i]))
			free(str);
		str = 0;
	}
}

void	cut_redir3(t_node **node, int flag)
{
	int		i;
	char	*str;

	i = -1;
	(void)flag;
	while ((*node) && (*node)->outfile && (*node)->outfile[++i])
	{
		if ((*node)->readline)
			str = ft_strdup((*node)->readline);
		free((*node)->readline);
		(*node)->readline = ft_strcut(str, (*node)->outfile[i]);
		// if (!flag && str && !ft_strcmp(str, (*node)->outfile[i]))
		// {
		// 	printf("hello out\n");
		// 	free(str);
		// }
			// free(str);
		str = 0;
	}
}

t_node	*cut_redir(t_node *node)
{
	int		i;
	char	*str;
	int		flag;

	flag = is_cmd(node->readline);
	if (!node)
		return (0);
	i = -1;
	while (node && node->infile && node->infile[++i])
	{
		str = ft_strdup(node->readline);
		free(node->readline);
		node->readline = ft_strcut(str, node->infile[i]);
		if (!flag && str && !ft_strcmp(str, node->infile[i]))
		{
			printf("hello in\n");
			free(str);
		}
		str = 0;
	}
	cut_redir3(&node, flag);
	cut_redir2(&node, flag);
	return (node);
}
