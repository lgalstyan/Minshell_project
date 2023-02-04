/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:59:37 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/03 17:40:46 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

	t_node	*init_readline(char *str, t_node *node)
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
  
	i = 0;
	node = NULL;
	if (checks(str))
		return (0);
	sp = pars_ft_split(str, '|');
	while (sp && sp[i])
	{
		new = malloc(sizeof(t_node));
		init_readline(sp[i], new);
		ft_list_add_back(&node, new);
		++i;
	}
	// while(node)
	// {
	// 	printf("lexreadline{%s}\n", node->readline);
	// 	node = node->next;
	// }
	node->counts.s_pipe = pipe_count(str);
	return (node);
}