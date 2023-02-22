/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:59:37 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/20 14:44:25 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

t_node	*init_readline(char *str, t_node *node)
{
	// printf("str = %s\n", str);
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
		//Lernona grel
		// if (line[i] == '\"')
		// {
		// 	while (line[++i] && line[i] != '\"')
		// 		;
		// 	++i;	
		// }
		// else if (line[i] == '\'')
		// {
		// 	while (line[++i] && line[i] != '\'')
		// 		;
		// 	++i;	
		// }
		// if (line && line[i] == '\0')
		// 	break ;
		//esqany
		if (line[i] == '|')
			count++;
		i++;
	}
	return (count);
}

static int	checks(char *str, t_env **en)
{
	if (checkquotes(str))
	{
		printf("Syntax error: the number of quotes is incorrect\n");
		set_exit_code("258", en);
		return (1);
	}
	if (pipe_count(str) + 1 != ft_wcount(str, '|'))
	{
		printf("Syntax error: the number of pipe is incorrect\n");
		set_exit_code("258", en);
		return (1);
	}
	return (0);
}

t_node	*lexer(char *str, t_env **en)
{
	int		i;
	char	**sp;
	t_node	*node;
	t_node	*new;

	i = 0;
	node = NULL;
	if (checks(str, en))
		return (0);
	sp = pars_ft_split(str, '|');
	while (sp && sp[i])
	{
		new = malloc(sizeof(t_node));
		init_readline(sp[i], new);//stex petqa listnel nodenel maqrel ete new-n chi stexcvum, sp-n el
		ft_list_add_back(&node, new);
		++i;
	}
	node->counts.s_pipe = pipe_count(str);
	free(sp);
	return (node);
}
