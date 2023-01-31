/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:59:37 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/29 13:49:40 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

static	t_node	*init_readline(char *str, t_node *node)
{
	node->readline = ft_strdup(str);
	node->next = NULL;
	return (node);
}

static int	pipe_count(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line && line[i])
	{
		if (line[i] == '|')
			count++;
		i++;
	}
	return (count);
}

static int	checks(char *str)
{
	if (checkquotes(str))
	{
		printf("Syntax error: the number of quotes is incorrect\n");
		exit_code = 258;
		return (1);
	}
	if (pipe_count(str) + 1 != ft_wcount(str, '|'))
	{
		printf("Syntax error: the number of pipe is incorrect\n");
		exit_code = 258;
		return (1);
	}
	return (0);
}

t_node *lexer(char *str)
{
	int		i;
	char	**sp;
	t_node	*node;
	t_node	*new;
  
	new = malloc(sizeof(t_node));
	i = 0;
	node = NULL;
	if (checks(str))
		return (0);
	sp = pars_ft_split(str, '|');
	while (i < ft_wcount(str, '|') && sp[i])
	{
		init_readline(sp[i], new);
		ft_lstadd_back(&node, new);
		++i;
	}
	return (node);
}