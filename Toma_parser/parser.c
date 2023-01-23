/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:25:38 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/23 16:01:17 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
// stugel "-eri qanaky zuyg lini
// stugel | piperi qanaky lini spliti qanak -1
// amen mi pipe qcel mi nodei mej
// hanel redirectionnery

void	print_node(t_node *node)
{
	int	i;

	i = 0;
	if(node)
	{
		while (node->cmd[i])
		{
			printf("cmd = %s", node->cmd[i]);
			i++;
		}
		// i = 0; 
		// while (node->heardock[i])
		// {
		// 	printf("heardock = %s", node->heardock[i]);
		// 	i++;
		// }
		// i = 0; 
		// while (node->append[i])
		// {
		// 	printf("append = %s", node->append[i]);
		// 	i++;
		// }
		// i = 0; 
		// while (node->outfile[i])
		// {
		// 	printf("outfile = %s", node->outfile[i]);
		// 	i++;
		// }
		// i = 0; 
		// while (node->redir[i])
		// {
		// 	printf("redir = %d", node->redir[i]);
		// 	i++;
		// }
	}
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
	if (!checkquotes(str)) //lava
	{
		printf("Syntax error: the number of quotes is incorrect\n");
		return (0);
	}
	sp = pars_ft_split(str, '|'); // lava	
	while (i < wcount(str, '|') && sp[i])
	{
		initialize(sp[i], new);
		ft_lstadd_back(&node, new);
		++i;
	}
	return (node);
}

void	allocate_matrix(t_node	*head)
{
	head->counts.s_infile = ft_infile_count(head->readline);
	head->counts.s_outfile = ft_outfile_count(head->readline);
	head->counts.s_heredoc = ft_heredoc_count(head->readline);
	head->counts.s_append = ft_append_count(head->readline);
	
	printf("s_infile = %d, s_outfile = %d, s_heredoc = %d, s_append = %d\n", head->counts.s_infile, head->counts.s_outfile, head->counts.s_heredoc, head->counts.s_append);
	head->infile = calloc((head->counts.s_infile + 1), sizeof(char *));
	head->outfile = calloc((head->counts.s_outfile + 1), sizeof(char *));
	head->heredoc = calloc((head->counts.s_heredoc + 1), sizeof(char *));
	head->append = calloc((head->counts.s_append + 1), sizeof(char *));
}

t_node	*parser(t_node *head)
{	
	allocate_matrix(head);
	return (head);
}
