/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:59:37 by lgalstya          #+#    #+#             */
/*   Updated: 2023/03/10 14:33:18 by tyenokya         ###   ########.fr       */
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
		if (line[i] == '\"' || line[i] == '\'')
			ignore_quotes(line, &i);
		if (!line[i])
			break ;
		if (line[i] == '|')
			count++;
		i++;
	}
	return (count);
}

int	ft_check_pipe(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] != '|')
			++i;
		if (str[i] == '|')
		{
			++i;
			while (str && str[i] && is_space(str[i]) == 1)
				++i;
			if (str[i] == '|')
				return (1);
		}
		else
			break ;
		++i;
	}
	return (0);
}

static int	checks(char *str, t_env **en)
{
	if (checkquotes(str))
	{
		printf("Syntax error: the number of quotes is incorrect\n");
		set_exit_code("258", en);
		return (1);
	}
	if (ft_check_pipe(str) || pipe_count(str) + 1 != ft_wcount(str, '|'))
	{
		printf("Syntax error: the number of pipe is incorrect\n");
		set_exit_code("258", en);
		return (1);
	}
	return (0);
}

void	lexer(t_node **node, char *str, t_env **en)
{
	int		i;
	char	**sp;
	t_node	*new;

	i = 0;
	*node = NULL;
	if (checks(str, en))
		return ;
	sp = pars_ft_split(str, '|');
	while (sp && sp[i])
	{
		new = malloc(sizeof(t_node));
		new->readline = ft_strdup(sp[i]);
		new->next = NULL;
		ft_list_add_back(node, new);
		++i;
	}
	(*node)->counts.s_pipe = pipe_count(str);
	free_arr(sp);
}
